/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:53:33 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 14:37:57 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
// Zombie class definition
#include <iostream>
/* Define color macros */
# define BLUE    "\033[1;34m"
# define PURPLE  "\033[1;35m"
# define GRAY    "\033[1;30m"
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m"
# define RESET   "\033[0m"
/* Define Background colors macros */
# define BG_RESET        "\033[49m"
# define BG_GREEN        "\033[42m"
# define BG_CYAN         "\033[46m"
# define BG_YELLOW       "\033[43m"
# define BG_RED          "\033[41m"

class Zombie
{
private:
	std::string name;
	// Name of the Zombie

public:
	Zombie(std::string name); //TODO: search initialized list
	// Constructor to initialize the Zombie with a name
	~Zombie();
	// Destructor to announce when a Zombie is destroyed
	void announce(void);
};

// outside the class I can put some outer methods
Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif
