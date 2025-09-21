/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: PmergeMe.hpp                                            ( o.o )    */
/*   Created: 2025/06/21 14:06:34 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/21 16:10:30                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>

#include <vector>
#include <deque>

//
#include <sstream>
#include <algorithm>
#include <cctype>
#include <limits.h>


class Pmergeme
{
private:
	std::deque<int> _deque;
	std::vector<int> _vector;
public:
	Pmergeme();
	Pmergeme(const Pmergeme& other);
	Pmergeme& operator=(const Pmergeme& other);
	~Pmergeme();

	int		parseArgs(int ac, char **av);
	int		parseInput(const std::string &s);
	bool	isValidNumber(const std::string &tok, int &outValue) const;
	bool	containsDuplicate(const std::vector<int> &vec, int value) const;
	void	fillVector(const std::vector<int> &values);
	void	fillDeque(const std::vector<int> &values);

//
	const	std::vector<int>&	getVector() const;
	const	std::deque<int>&	getDeque()  const;
	void	printVector() const;
	void	printDeque() const;
};
#endif
