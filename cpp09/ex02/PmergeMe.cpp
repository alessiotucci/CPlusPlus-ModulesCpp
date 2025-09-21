/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: PmergeMe.cpp                                            ( o.o )    */
/*   Created: 2025/06/21 14:06:38 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/21 19:34:11                                   /         */
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

static void printyPairs(const std::vector< std::pair<int,int> > &pairs, bool hasLeftover, int leftover)
{
	// This function now prints the winner in RED and the loser in BLUE.
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		int first = pairs[i].first;
		int second = pairs[i].second;

		int winner;
		int loser;

		// Determine the winner (larger) and loser (smaller) for printing
		if (first > second)
		{
			winner = first;
			loser = second;
		}
		else
		{
			winner = second;
			loser = first;
		}

		std::cout << "[" << RED << winner << RESET << ", " << BLUE << loser << RESET << "]";

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

void Pmergeme::printPairs(const std::vector< std::pair<int,int> > &pairs, bool hasLeftover, int leftover) const
{
	// Print pairs in the requested format: [a, b] [c, d] ...
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "]";
		if (i + 1 < pairs.size() || hasLeftover)
			std::cout << " ";
	}
	if (hasLeftover)
	{
		std::cout << "[" << leftover << "]";
	}
	//TODO: perform a swap in a way we have the winner (COLOR RED) as first in
	//the pair
	//
	//TODO: and  the loser as the second (COLOR BLUE) 
	std::cout << std::endl;
	printyPairs(pairs, hasLeftover, leftover);
}

int Pmergeme::makeWinnersAndLosersFromPairs(const std::vector< std::pair<int,int> > &pairs, std::vector<int> &winners, std::vector<int> &losers) const
{
    winners.clear();
    losers.clear();

    for (std::size_t i = 0; i < pairs.size(); ++i)
    {
        int a = pairs[i].first;
        int b = pairs[i].second;
        if (a >= b)
        {
            winners.push_back(a);
            losers.push_back(b);
        }
        else
        {
            winners.push_back(b);
            losers.push_back(a);
        }
    }
    return 0;
}

int Pmergeme::reduceWinnersUntilOneCouple(std::vector<int> winners) const
{
    // trivial checks
    if (winners.empty())
    {
        std::cout << "No winners to reduce." << std::endl;
        return -1;
    }

    // Loop until we have exactly two winners (one couple) or cannot reduce further
    while (winners.size() > 2)
    {
        std::vector<int> nextWinners;
        std::size_t i = 0;
        for (; i + 1 < winners.size(); i += 2)
        {
            int a = winners[i];
            int b = winners[i + 1];
            // the winner is the larger element
            nextWinners.push_back((a >= b) ? a : b);
        }
        // if odd leftover, carry it over as-is
        if (i < winners.size())
            nextWinners.push_back(winners[i]);

        // move to next round
        winners = nextWinners;
    }

    // After reduction, check results
    if (winners.size() == 2)
    {
        std::cout << "[" << winners[0] << ", " << winners[1] << "]" << std::endl;
        return 0;
    }
    else if (winners.size() == 1)
    {
        // single leftover, no couple
        std::cout << "Reduction produced a single leftover: [" << winners[0] << "]" << std::endl;
        return -1;
    }
    else
    {
        // should not happen, but be safe
        std::cout << "No final couple produced." << std::endl;
        return -1;
    }
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
    printPairs(pairs, hasLeftover, leftover);

    // build winners (larger of each pair)
    std::vector<int> winners;
    winners.reserve(pairs.size() + (hasLeftover ? 1 : 0));

    //TODO: implement a way to keep track of winning and losing --> userful in
	//binary search:
    // build losers (larger of each pair)
    std::vector<int> losers;
    losers.reserve(pairs.size() + (hasLeftover ? 1 : 0));

    for (std::size_t j = 0; j < pairs.size(); ++j)
    {
        int a = pairs[j].first;
        int b = pairs[j].second;
        winners.push_back((a >= b) ? a : b);
    }
    // If leftover exists, propagate it to next round as-is
    if (hasLeftover)
        winners.push_back(leftover);

    // If winners produce the final couple, print and stop
    if (winners.size() == 2)
    {
        std::cout << "Final couple, check if need to swap" << std::endl;
        std::cout << "[" << winners[0] << ", " << winners[1] << "]" << std::endl;
        return;
    }
    // If we have a single leftover only, print it as leftover and stop
    if (winners.size() == 1)
    {
        std::cout << "Single leftover: [" << winners[0] << "]" << std::endl;
        return;
    }
    // Otherwise recurse on the winners
    recursePairs(winners);
}


void Pmergeme::sortPairWithLog(std::pair<int,int> &p) const
{
    int a = p.first;
    int b = p.second;

    // print original pair
    std::cout << "[" << a << ", " << b << "] sorting --> ";

    // sort ascending
    if (a > b)
        std::swap(a, b);

    // print result
    std::cout << "[" << a << ", " << b << "] !" << std::endl;

    // store sorted pair back
    p.first = a;
    p.second = b;
}

void Pmergeme::insertPartnerBinary(std::vector<int> &sorted, int partner, int pairedWith) const
{
    // If sorted is empty, just push and print
    if (sorted.empty())
    {
        std::cout << "(" << partner << ") was originally paired with " << pairedWith
                  << ", start from [] --> [ " << partner << " ]" << std::endl;
        sorted.push_back(partner);
        return;
    }

    int low = 0;
    int high = static_cast<int>(sorted.size()) - 1;
    int mid = (low + high) / 2;

    // Log the element we start comparing with (the initial midpoint)
    std::cout << "(" << partner << ") was originally paired with " << pairedWith
              << ", so binary search start from [" << sorted[mid] << "] --> ";

    // Manual lower_bound-like binary search to determine insert position
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (sorted[mid] < partner)
            low = mid + 1;
        else
            high = mid - 1;
    }
    // low is the insertion index
    std::vector<int>::iterator it = sorted.begin() + low;
    sorted.insert(it, partner);

    // print resulting sorted vector (compact format)
    std::cout << "[";
    for (std::size_t i = 0; i < sorted.size(); ++i)
    {
        if (i) std::cout << ", ";
        std::cout << sorted[i];
    }
    std::cout << "]" << std::endl;
}


