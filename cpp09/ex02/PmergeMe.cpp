/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: PmergeMe.cpp                                            ( o.o )    */
/*   Created: 2025/06/21 14:06:38 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/21 15:47:26                                   /         */
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

