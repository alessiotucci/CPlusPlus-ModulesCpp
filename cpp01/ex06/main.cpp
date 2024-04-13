/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:07:59 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 16:00:10 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

// LEVELS:
// 1) Debug
// 2) Info
// 3) Warning
// 4) Error

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string check = av[1];
		Harl test;

		if (!check.compare("DEBUG") || !check.compare("INFO")
			||!check.compare("WARNING") ||!check.compare("ERROR"))
			test.complain(av[1]);
		else
			test.complain(""); // implement a method without args

	}
	else
		std::cout << "USAGE: ./harlFilter \"WARNING\"\n";
	return (0);
}
