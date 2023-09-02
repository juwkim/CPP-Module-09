/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 06:09:47 by juwkim            #+#    #+#             */
/*   Updated: 2023/09/02 06:13:02 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Usage: ./RPN [inverted polish mathematical expression]" << '\n';
		return 0;
	}
	RPN::run(argv[1]);
	return 0;
}
