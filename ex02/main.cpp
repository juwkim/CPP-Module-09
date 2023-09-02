/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 06:39:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/09/02 08:18:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << "Usage: ./PmergeMe sequence ... " << '\n';
		return 0;
	}

	std::vector<int> nums;
	nums.reserve(argc - 1);
	
	char *endptr;
	unsigned long long num;
	for (int i = 1; i < argc; ++i) {
		num = std::strtoull(argv[i], &endptr, 10);
		if (*endptr != '\0') {
			std::cout << "Error: invalid argument: " << argv[i] << '\n';
			return 0;
		}
		if (num < 0) {
			std::cout << "Error: not a positive number: " << argv[i] << '\n';
			return 0;
		}
		if (num > INT32_MAX) {
			std::cout << "Error: too large a number: " << argv[i] << '\n';
			return 0;
		}
		nums.push_back(static_cast<int>(num));
	}

	std::vector<int> v; const double time_v = sort_time(v, nums);
	std::deque<int>  d; const double time_d = sort_time(d, nums);

	std::cout << "Before: " << to_string(nums) << '\n'
	          << "After : " << to_string(v) << '\n'
			  << std::fixed
			  << "Time to process a range of " << v.size()
	          << " elements with std::vector : " << time_v << " us" << '\n'
			  << "Time to process a range of " << d.size()
	          << " elements with std::deque  : " << time_d << " us" << '\n';
	return 0;
}
