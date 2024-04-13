/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:07:12 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 17:28:21 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl test;
	test.complain("DEBUG");
	test.complain("INFO");
	test.complain("WARNING");
	test.complain("ERROR");
}
