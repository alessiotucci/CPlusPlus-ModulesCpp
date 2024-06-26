/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:06:39 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 12:09:16 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SedLoser.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 4)
	{
		SedLoser fr(av[1], av[2], av[3]);
		fr.replace();
		return (0);
	}
	else
		std::cout << "The Program takes 3 argoument\n"
				  << "1) filename, 2)target, 3) replacement\n";
	return -1;
}
