/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:07:59 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 14:18:20 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl test;
		test.complain(av[1]);
//		test.complain("INFO");
//		test.complain("WARNING");
//		test.complain("ERROR");
	}
	else
		std::cout << "USAGE: ./harlFilter \"WARNING\"\n";
	return (0);
}
