/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/21 14:00:15 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/21 21:14:02                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	Pmergeme pm;
	if (ac == 1)
	{
		std::cerr << "Error: no arguments" << std::endl;
		return 1;
	}
	else if (ac == 2)
	{
		if (pm.parseInput(std::string(av[1])) != 0)
			return 1;
	}
	else
	{
		// multiple argv tokens mode: parse av[1]..av[ac-1]
		if (pm.parseArgs(ac, av) != 0)
			return 1;
	}
	// success: you can report counts or proceed to sorting stage
	std::cout << "Vector " << pm.getVector().size() << " numbers." << std::endl;
	pm.printVector();
////	std::cout << "Deque " << pm.getDeque().size() << " numbers." << std::endl;
////	pm.printDeque();
//
	std::cout << "\nStarting making pairs alright!\n";
	pm.recursePairs(pm.getVector());
	
	// For deque-based pairs
	//pm.makePairsFromDeque(pairs, hasLeftover, leftover);
	//pm.printPairs(pairs, hasLeftover, leftover);

}

