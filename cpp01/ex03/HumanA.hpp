/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:05:29 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 14:41:46 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
//TODO: HumanA takes the Weapon in its constructor
/*		HumanA will ALWAYS be armed */
class HumanA
{
private:
	std::string name;
public:
	HumanA();
	~HumanA();
	void attack();
};
#endif
