/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/21 13:59:33 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/19 18:16:51                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*Your program must take an inverted Polish mathematical expression as an argument.*/
int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "RNP: wrong arguments" << std::endl;
	}
	else
	{
		std::cout << "RNP: evaluation expression [" << av[1] << "]" << std::endl;
	}
	Rpn r;
	r.splitInput(av[1]);
	std::cout << r << std::endl;
	return (0);
}
