/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: PmergeMe.hpp                                            ( o.o )    */
/*   Created: 2025/06/21 14:06:34 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/28 20:42:52                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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

#include <string>
#include <iostream>
#include <vector>
#include <deque>

//
#include <sstream>
#include <algorithm>
#include <cctype>
#include <limits.h>


#include <utility>  // for std::pair
#include <ctime>  // for clock()
#include <iomanip>  // for std::setwd


class Pmergeme
{
private:
	std::deque<int> _deque;
	std::vector<int> _vector;


// helpers used by recursePairsImpl
void buildPairsFromVector(const std::vector<int> &elements, std::vector< std::pair<int,int> > &outPairs, bool &hasLeftover,int &leftover) const;
void buildPairsFromDeque(const std::deque<int> &elements, std::deque< std::pair<int,int> > &outPairs, bool &hasLeftover, int &leftover) const;

void collectWinnersFromPairs(const std::vector< std::pair<int,int> > &pairs, std::vector<int> &winners) const;
void collectWinnersFromPairsDeque(const std::deque< std::pair<int,int> > &pairs, std::deque<int> &winners) const;


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

// create adjacent pairs from internal vector; returns pairs and optionally leftover
int makePairsFromVector(std::vector< std::pair<int,int> > &outPairs, bool &hasLeftover, int &leftover) const;
// create adjacent pairs from internal deque; returns pairs and optionally leftover
int makePairsFromDeque(std::vector< std::pair<int,int> > &outPairs, bool &hasLeftover, int &leftover) const;

/*****************************************************************************/
// recursively build and print pairs from the provided VECTOR until 
void recursePairs(const std::vector<int> &elements) const;
std::vector<int> recursePairsImpl(const std::vector<int> &elements, int level) const;

void collectWinnersFromPairs(const std::vector< std::pair<int,int> > &pairs, std::vector<int> &winners);

/*****************************************************************************/
void recursePairsDeque(const std::deque<int> &elements) const;
std::deque<int> recursePairsImplDeque(const std::deque<int> &elements, int level) const;

void buildPairsFromVector(const std::vector<int> &elements, std::vector< std::pair<int,int> > &outPairs, bool &hasLeftover, int &leftover);

void swapPairsVector(std::vector< std::pair<int,int> > &pairs, bool hasLeftover, int leftover) const;
void swapPairsDeque(std::deque< std::pair<int,int> > &pairs, bool hasLeftover, int leftover) const;

};
#endif
