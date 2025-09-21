/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: PmergeMe.cpp                                            ( o.o )    */
/*   Created: 2025/06/21 14:06:38 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/21 19:57:38                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Pmergeme::Pmergeme() { }
Pmergeme::~Pmergeme() { }

Pmergeme::Pmergeme(const Pmergeme& other)
{
	*this = other;
	return ;
}

Pmergeme& Pmergeme::operator=(const Pmergeme& other)
{
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return (*this);
}

const std::vector<int>& Pmergeme::getVector() const { return _vector; }
const std::deque<int>&  Pmergeme::getDeque()  const { return _deque; }

//Helper to print
void Pmergeme::printVector() const
{
	const std::vector<int> &v = _vector;
	std::cout << "[";
	if (v.empty())
	{
		std::cout << " ]" << std::endl;
		return;
	}

	std::cout << " ";
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		if (i != 0)
			std::cout << ", ";
		std::cout << v[i];
	}
	std::cout << " ]" << std::endl;
}

//Helper to print
void Pmergeme::printDeque() const
{
	const std::deque<int> &d = _deque;
	std::cout << "[";
	if (d.empty())
	{
		std::cout << " ]" << std::endl;
		return;
	}

	std::cout << " ";
	for (std::size_t i = 0; i < d.size(); ++i)
	{
		if (i != 0)
			std::cout << ", ";
		std::cout << d[i];
	}
	std::cout << " ]" << std::endl;
}


bool Pmergeme::isValidNumber(const std::string &tok, int &outValue) const
{
	if (tok.empty())
		return (false);
	std::size_t i = 0;
	if (tok[0] == '+')
	{
		if (tok.size() == 1)
			return false;
		i = 1;
	}
	for (; i < tok.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(tok[i])))
			return (false);
	}
	std::stringstream ss(tok);
	long tmp = 0;
	ss >> tmp;
	if (!ss || tmp <= 0 || tmp > static_cast<long>(INT_MAX))
		return false;

	outValue = static_cast<int>(tmp);
	return true;
}

bool Pmergeme::containsDuplicate(const std::vector<int> &vec, int value) const
{
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		if (vec[i] == value)
			return true;
	}
	return false;
}

void Pmergeme::fillVector(const std::vector<int> &values)
{
	_vector.clear();
	// reserve if you know approximate size (safe in C++98)
	_vector.reserve(values.size());
	for (std::size_t i = 0; i < values.size(); ++i)
		_vector.push_back(values[i]);
}

void Pmergeme::fillDeque(const std::vector<int> &values)
{
	_deque.clear();
	for (std::size_t i = 0; i < values.size(); ++i)
		_deque.push_back(values[i]);
}

int Pmergeme::parseInput(const std::string &s)
{
	std::vector<int> values;
	std::stringstream ss(s);
	std::string tok;

	// split on whitespace
	while (ss >> tok)
	{
		int val = 0;
		if (!isValidNumber(tok, val))
		{
			std::cerr << "Error: invalid number -> " << tok << std::endl;
			return (-1);
		}
		// check duplicates in vector
		if (containsDuplicate(values, val))
		{
			std::cerr << "Error: duplicate number -> " << val << std::endl;
			return (-1);
		}
		values.push_back(val);
	}
	if (values.empty())
	{
		std::cerr << "Error: no numbers provided" << std::endl;
		return (-1);
	}
	fillVector(values);
	fillDeque(values);
	return (0);
}

int Pmergeme::parseArgs(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cerr << "Error: no arguments" << std::endl;
		return -1;
	}

	std::vector<int> values;
	for (int i = 1; i < ac; ++i)
	{
		std::string tok(av[i]);
		int val = 0;
		if (!isValidNumber(tok, val))
		{
			std::cerr << "Error: invalid number -> " << tok << std::endl;
			return -1;
		}

		if (containsDuplicate(values, val))
		{
			std::cerr << "Error: duplicate number -> " << val << std::endl;
			return -1;
		}

		values.push_back(val);
	}

	if (values.empty())
	{
		std::cerr << "Error: no numbers provided" << std::endl;
		return -1;
	}

	fillVector(values);
	fillDeque(values);
	return 0;
}

int Pmergeme::makePairsFromVector(std::vector< std::pair<int,int> > &outPairs, bool &hasLeftover, int &leftover) const
{
	outPairs.clear();
	hasLeftover = false;
	leftover = 0;

	const std::vector<int> &v = _vector;
	std::size_t n = v.size();
	if (n == 0)
		return 0; // nothing to do

	std::size_t i = 0;
	for (; i + 1 < n; i += 2)
	{
		outPairs.push_back(std::make_pair(v[i], v[i + 1]));
	}
	if (i < n)
	{
		// odd element left
		hasLeftover = true;
		leftover = v[i];
	}
	return 0;
}

int Pmergeme::makePairsFromDeque(std::vector< std::pair<int,int> > &outPairs, bool &hasLeftover, int &leftover) const
{
	outPairs.clear();
	hasLeftover = false;
	leftover = 0;

	const std::deque<int> &d = _deque;
	std::size_t n = d.size();
	if (n == 0)
		return 0;

	std::size_t i = 0;
	for (; i + 1 < n; i += 2)
	{
		outPairs.push_back(std::make_pair(d[i], d[i + 1]));
	}
	if (i < n)
	{
		hasLeftover = true;
		leftover = d[i];
	}
	return 0;
}

void Pmergeme::swapPairs(std::vector< std::pair<int,int> > &pairs, bool hasLeftover, int leftover) const
{
	// Normalize pairs so that .first is always the winner (larger)
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first > pairs[i].second)
		{
			std::swap(pairs[i].first, pairs[i].second);
		}
	}
	// Now print them with colors
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		std::cout << "[" << RED << pairs[i].first << RESET
				  << ", " << BLUE << pairs[i].second << RESET << "]";
		if (i + 1 < pairs.size() || hasLeftover)
			std::cout << " ";
	}
	if (hasLeftover)
	{
		// Leftover doesn't have a pair, so it's printed without winner/loser colors.
		std::cout << "[" << YELLOW << leftover << RESET << "]";
	}
	std::cout << std::endl;
}

void Pmergeme::recursePairs(const std::vector<int> &elements) const
{
    // base empty-check
    if (elements.empty())
    {
        std::cout << "No elements to process." << std::endl;
        return;
    }

    // build adjacent pairs from 'elements'
    std::vector< std::pair<int,int> > pairs;
    bool hasLeftover = false;
    int leftover = 0;
    std::size_t i = 0;
    for (; i + 1 < elements.size(); i += 2)
    {
        pairs.push_back(std::make_pair(elements[i], elements[i + 1]));
    }

    if (i < elements.size())
    {
        hasLeftover = true;
        leftover = elements[i];
    }

    // print this level's pairs using the existing helper
    swapPairs(pairs, hasLeftover, leftover);
	//TODO: we have to start the logic from here!
	/* This function need to be recursinve, and we need to keep track of the old
	 * pairs, of the lever before 
	 */
//    recursePairs(winners);
}

