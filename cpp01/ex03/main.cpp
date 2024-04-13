/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:04:40 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 17:52:09 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
/*
int	main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		club.setType("some other type of club");
		jim.attack();
	}
return (0);
}*/
int	main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		std::cout << "JIM IS A HUMAN B" << std::endl;
		HumanB jim("Jim");
		jim.attack();
	}
	{
		std::cout << "JOSEPH IS A HUMAN B" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB joseph("Joseph");
		joseph.setWeapon(club);
		club.setType("kalashnikov");
		joseph.attack();
		club.setType("small gun");
		joseph.attack();
	}
return (0);
}
