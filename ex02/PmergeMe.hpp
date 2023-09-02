/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 06:38:46 by juwkim            #+#    #+#             */
/*   Updated: 2023/09/02 08:30:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

void ford_johnson(std::vector<int>& c);
void ford_johnson(std::deque<int>& c);

template <typename T>
std::string to_string(const T& c)
{
	std::ostringstream s;
	typename T::const_iterator it = c.begin();
	const typename T::const_iterator end = c.end();

	s << *it; ++it;
	for (; it != end; ++it)
		s << " " << *it;
	return s.str();
}

template <typename T>
double sort_time(T& c, const std::vector<int>& nums)
{
	clock_t	start_time = clock();
	c.assign(nums.begin(), nums.end());
	ford_johnson(c);
	clock_t	end_time = clock();
	return static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
}
