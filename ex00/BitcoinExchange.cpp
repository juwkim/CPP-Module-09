/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 03:59:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/09/02 17:29:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& q)
{
	(void)q;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& q)
{
	(void)q;
	return *this;
}

inline bool is_leap_year(const int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

inline bool is_valid_date(const int year, const int month, const int day) {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    const int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int max_day;
    if (month == 2 && is_leap_year(year))
        max_day = 29;
	else
		max_day = days_in_month[month];

    return day <= max_day;
}

inline static std::string strtime(const int y, const int m, const int d)
{
	std::ostringstream str;

	str << std::setfill('0')
		<< std::setw(4) << y << '-'
		<< std::setw(2) << m << '-'
		<< std::setw(2) << d;
	return str.str();
}

inline static int to_time(const int y, const int m, const int d)
{
	return y * 10000 + m * 100 + d;
}

static std::multimap<int, double> make_db()
{
	int y, m, d;
	double exchange_rate;

	
	std::multimap<int, double> db;

	std::ifstream in("data.csv", std::ios_base::in);
	std::string header; std::getline(in, header);
	for (std::string line; std::getline(in, line);) {
		if (std::sscanf(line.c_str(), "%d-%d-%d,%lf", &y, &m, &d, &exchange_rate) != 4)
			break;
		db.insert(std::make_pair(to_time(y, m, d), exchange_rate));
	}
	return db;
}

void BitcoinExchange::run(const char* file)
{
	std::ifstream in(file, std::ios_base::in);
	if (in.is_open() == false) {
		std::cout << "Error: not a valid file." << '\n';
		return;
	}

	std::string	header; std::getline(in, header);
	if (header != "date | value") {
		std::cout << "Error: not a valid header." << '\n';
		return;
	}

	std::multimap<int, double> db = make_db();

	for (std::string line; std::getline(in, line);) {
		int y, m, d;
		double val;

		if (std::sscanf(line.c_str(), "%d-%d-%d | %lf", &y, &m, &d, &val) != 4) {
			std::cout << "Error: bad input => " << line.c_str() << '\n';
			continue;
		}
		if (is_valid_date(y, m, d) == false) {
			std::cout << "Error: not a valid date => " << strtime(y, m, d) << '\n';
			continue;
		}
		if (val < 0) {
			std::cout << "Error: not a positive number." << '\n';
			continue;
		}
		if (val > 1000) {
			std::cout << "Error: too large a number." << '\n';
			continue;
		}
		std::multimap<int, double>::const_iterator it = db.lower_bound(to_time(y, m, d));
		if (it->first > to_time(y, m, d))
			it = std::prev(it);
		std::cout << strtime(y, m, d)
		          << " => " << val
				  << " = " << val * it->second << '\n';
	}
	in.close();
}
