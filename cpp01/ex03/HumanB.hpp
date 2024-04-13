/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:05:59 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 11:21:24 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//TODO: HumanB may not always have a Weapon
class HumanB
{
private:
	std::string name;
public:
	HumanB();
	~HumanB();
	void attack();
};
