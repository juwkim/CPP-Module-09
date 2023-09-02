/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 03:59:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/09/02 06:03:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	public:
		static void	run(const char *file);

	private:
		virtual ~BitcoinExchange(void);
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& q);
		BitcoinExchange& operator=(const BitcoinExchange& q);
};
