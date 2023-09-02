/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 06:39:17 by juwkim            #+#    #+#             */
/*   Updated: 2023/09/02 17:05:02 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void ford_johnson(std::vector<int>& c)
{
	if (c.size() == 1)
		return;

	bool odd = false;
	int  num;
	if (c.size() & 1) {
		odd = true;
		num = c.back(); c.pop_back();
	}

	std::vector<std::pair<int, int> > pairs; pairs.reserve(c.size() / 2);
	for (size_t i = 0; i < c.size(); i += 2)
		pairs.push_back(std::make_pair(c[i], c[i + 1]));

	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}

	for (size_t i = 1; i < pairs.size(); ++i) {
		std::pair<int, int>	key = pairs[i];
		size_t j = i;
		while (j > 0 && pairs[j - 1] > key) {
			pairs[j] = pairs[j - 1];
			--j;
		}
		pairs[j] = key;
	}

	std::vector<int> mainChain, pendingElements;

	for (size_t i = 0; i < pairs.size(); ++i) {
		mainChain.push_back(pairs[i].first);
		pendingElements.push_back(pairs[i].second);
	}

	mainChain.insert(mainChain.begin(), pendingElements[0]);

    std::vector<const size_t> jacobstal;
	jacobstal.push_back(1);
	jacobstal.push_back(3);
	size_t i = 0;
	while (true) {
		const size_t next = jacobstal[i] + 2 * jacobstal[i + 1];
		jacobstal.push_back(next);
		if (next >= pendingElements.size())
			break;
		++i;
	}

	for (size_t i = 0; i < jacobstal.size() - 1; ++i) {
		size_t start = jacobstal[i];
		size_t end = std::min(jacobstal[i + 1], pendingElements.size()) - 1;
		for (size_t j = end; j >= start; --j) {
			const int num = pendingElements[j];
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), num), num);
		}
	}
	if (odd == true)
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), num), num);
	c = mainChain;
}

void ford_johnson(std::deque<int>& c)
{
	if (c.size() == 1)
		return;

	bool odd = false;
	int  num;
	if (c.size() & 1) {
		odd = true;
		num = c.back(); c.pop_back();
	}

	std::vector<std::pair<int, int> > pairs; pairs.reserve(c.size() / 2);
	for (size_t i = 0; i < c.size(); i += 2)
		pairs.push_back(std::make_pair(c[i], c[i + 1]));

	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}

	for (size_t i = 1; i < pairs.size(); ++i) {
		std::pair<int, int>	key = pairs[i];
		size_t j = i;
		while (j > 0 && pairs[j - 1] > key) {
			pairs[j] = pairs[j - 1];
			--j;
		}
		pairs[j] = key;
	}

	std::deque<int> mainChain, pendingElements;

	for (size_t i = 0; i < pairs.size(); ++i) {
		mainChain.push_back(pairs[i].first);
		pendingElements.push_back(pairs[i].second);
	}

	mainChain.insert(mainChain.begin(), pendingElements[0]);

    std::vector<const size_t> jacobstal;
	jacobstal.push_back(1);
	jacobstal.push_back(3);
	size_t i = 0;
	while (true) {
		const size_t next = jacobstal[i] + 2 * jacobstal[i + 1];
		jacobstal.push_back(next);
		if (next >= pendingElements.size())
			break;
		++i;
	}

	for (size_t i = 0; i < jacobstal.size() - 1; ++i) {
		size_t start = jacobstal[i];
		size_t end = std::min(jacobstal[i + 1], pendingElements.size()) - 1;
		for (size_t j = end; j >= start; --j) {
			const int num = pendingElements[j];
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), num), num);
		}
	}
	if (odd == true)
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), num), num);
	c = mainChain;
}
