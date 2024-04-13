/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:04:13 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 10:55:53 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *
 * Write a program that contains:
	• A string variable initialized to "HI THIS IS BRAIN".
	• stringPTR: A pointer to the string.
	• stringREF: A reference to the string.
*/
#include <iostream>
# define BLUE    "\033[1;34m"
# define PURPLE  "\033[1;35m"
# define GRAY    "\033[1;30m"
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m"
# define RESET   "\033[0m"
# define BG_RESET        "\033[49m"
# define BG_GREEN        "\033[42m"
# define BG_CYAN         "\033[46m"
# define BG_YELLOW       "\033[43m"
# define BG_RED          "\033[41m"


int	main()
{
	std::cout << "Write a program that contains:\n";
	std::cout <<" 1)	A string variable initialized to 'HI THIS IS BRAIN'.\n";
	std::cout <<" 2)	stringPTR: A pointer to the string.\n";
	std::cout <<" 3)	stringREF: A reference to the string.\n\n\n";
	std::string	new_string = "HI THIS IS BRAIN";
	std::string *stringPTR = &new_string;
	std::string& stringREF = new_string;
	/*************************************************************************/
	std::cout << " Your program has to print:\n";

	std::cout << "\t1) The memory address of the string variable.\n";
	std::cout << "\t" << RED << &new_string << RESET << ": MEMORY of the string\n";
	std::cout << "\t2) The memory address held by stringPTR.\n";
	std::cout << "\t" << RED << stringPTR<< RESET << ": MEMORY of the pointer\n";
	std::cout << "\t3) The memory address held by stringREF.\n";
	std::cout << "\t" << RED << &stringREF << RESET << ": MEMORY of the reference\n";
	/*************************************************************************/
	std::cout << "And then:\n\n";

	std::cout << "\t• The value of the string variable.\n";
	std::cout << "\t" << YELLOW << new_string << RESET << ": VALUE of the string\n";
	std::cout << "\t• The value pointed to by stringPTR.\n";
	std::cout << "\t" << YELLOW << *stringPTR << RESET << ": VALUE of the pointer\n";
	std::cout << "\t• The value pointed to by stringREF.\n";
	std::cout << "\t" << YELLOW << stringREF << RESET << ": VALUE of the reference\n";
	return (0);
}
