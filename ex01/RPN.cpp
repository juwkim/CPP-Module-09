/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 06:09:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/09/02 06:37:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN(void)
{
}

RPN::RPN(void)
{
}

RPN::RPN(const RPN& q)
{
	(void)q;
}

RPN& RPN::operator=(const RPN& q)
{
	(void)q;
	return *this;
}

static bool calculate(std::stack<const int>& s, const char op)
{
	if (s.size() < 2)
		return false;
	const int num2 = s.top(); s.pop();
	const int num1 = s.top(); s.pop();
	switch (op)
	{
		case '+': s.push(num1 + num2); break;
		case '-': s.push(num1 - num2); break;
		case '*': s.push(num1 * num2); break;
		case '/':
		{
			if (num2 == 0)
				return false;
			s.push(num1 / num2);
			break;
		}
		default:
			return false;
	}
	return true;
}

void RPN::run(const std::string expr)
{
	std::stack<const int> s;

	for (std::string::const_iterator it = expr.begin(), end = expr.end(); it != end; ++it) {
		if (std::isspace(*it))
			continue;
		if (std::isdigit(*it)) {
			s.push(static_cast<const int>(*it - '0'));
			continue;
		}
		if (calculate(s, static_cast<const char>(*it)) == false) {
			std::cout << "Error" << '\n';
			return;
		}
	}
	if (s.size() != 1) {
		std::cout << "Error" << '\n';
		return;
	}
	std::cout << s.top() << '\n';
}
