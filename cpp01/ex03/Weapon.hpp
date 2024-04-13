/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:05:01 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 15:33:44 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//TODO: Always add the include guards
#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
private:
	std:: string type;
public:
	const	std::string&	getType() const;
	void	setType(std::string param);
	Weapon(std:: string _type);
	~Weapon();
};
#endif
