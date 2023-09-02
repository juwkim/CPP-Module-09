/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 06:08:18 by juwkim            #+#    #+#             */
/*   Updated: 2023/09/02 06:19:37 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

class RPN
{
	public:
		static void	run(const std::string notation);
	private:
		virtual ~RPN(void);
		RPN(void);
		RPN(const RPN& q);
		RPN& operator=(const RPN& q);
};
