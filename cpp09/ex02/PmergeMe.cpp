/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: PmergeMe.cpp                                            ( o.o )    */
/*   Created: 2025/06/21 14:06:38 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/21 21:30:20                                   /         */
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

static void VectorPrint(const std::vector<int> &v)
{
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
void Pmergeme::printVector() const
{
	const std::vector<int> &v = _vector;
	VectorPrint(v);
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
	if (!ss || tmp < 0 || tmp > static_cast<long>(INT_MAX))
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

//void Pmergeme::swapPairs(std::vector< std::pair<int,int> > &pairs, bool hasLeftover, int leftover, int level) const
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

// Public entry that your main calls
void Pmergeme::recursePairs(const std::vector<int> &elements) const
{
	//TODO: the return here is discarded
	recursePairsImpl(elements, 0);
}

// helper: insert 'loser' into sorted 'chain' so that it appears before 'partner'.
// Tries the immediate predecessor first (cheap) then falls back to lower_bound.
static void insertBeforePartner(std::vector<int> &chain, int loser, int partner)
{
	std::cout << "insertBeforePartner: loser = " << loser << " partner = " << partner << std::endl;
	VectorPrint(chain);
	
    // find partner index
    std::size_t pIdx = 0;
    for (; pIdx < chain.size(); ++pIdx)
	{
        if (chain[pIdx] == partner)
			break;
    }
	//TODO: If shouldn´t happen, it won´t happen!!
    // if not found (shouldn't happen), insert by global lower_bound as fallback
    if (pIdx == chain.size())
	{
        std::vector<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), loser);
        chain.insert(it, loser);
        return;
    }

    // partner is at pIdx; we must insert somewhere in [0 .. pIdx] (before partner)
    if (pIdx == 0)
	{
        chain.insert(chain.begin(), loser);
        return;
    }

    // try immediate predecessor first (this uses only one comparison)
    int pred = chain[pIdx - 1];
    if (loser >= pred)
	{
        // fits between pred and partner
        chain.insert(chain.begin() + pIdx, loser);
        return;
    }

    // otherwise binary search on [0 .. pIdx-1)
    std::vector<int>::iterator it = std::lower_bound(chain.begin(), chain.begin() + pIdx, loser);
    chain.insert(it, loser);
}

// recursive implementation that returns the sorted chain for this subtree.
// Public wrapper (recursePairs) will just call this and ignore the return or print final result.
std::vector<int> Pmergeme::recursePairsImpl(const std::vector<int> &elements, int level) const
{
    // 1) build pairs from elements (adjacent)
    std::vector< std::pair<int,int> > pairs;
    bool hasLeftover = false;
    int leftover = 0;

    std::size_t i = 0;
    for ( ; i + 1 < elements.size(); i += 2 )
	{
        pairs.push_back(std::make_pair(elements[i], elements[i+1]));
    }
    if (i < elements.size())
	{
		hasLeftover = true;
		leftover = elements[i];
	}

    // 2) normalize & print (your swapPairs normalizes in-place)
    // Keep your existing swapPairs call (it will ensure pair.first <= pair.second).
    swapPairs(pairs, hasLeftover, leftover);

    // 3) collect winners (second of each pair)
    std::vector<int> winners;
    winners.reserve(pairs.size());
    for (std::size_t k = 0; k < pairs.size(); ++k)
        winners.push_back(pairs[k].second);

/******************************************************************************/
// 4) STOP condition: when winners.size() <= 2 we build a base chain and insert this level's losers
    if (winners.size() < 2)
	{
        std::vector<int> chain;
        if (winners.size() == 2)
		{
            // sort the two winners into ascending order
            int a = winners[0], b = winners[1];
            if (a <= b)
			{
				chain.push_back(a);
				chain.push_back(b);
			}
            else
			{
				chain.push_back(b);
				chain.push_back(a);
			}
        }
		else if (winners.size() == 1)
		{
            chain.push_back(winners[0]);
        } // else winners empty -> chain stays empty

        // insert current-level losers (pair.first) before their partners using minimal comparisons
        for (std::size_t k = 0; k < pairs.size(); ++k)
		{
            int loser = pairs[k].first;
            int partner = pairs[k].second;
            insertBeforePartner(chain, loser, partner);
        }

        // if leftover exists at this level, insert it into chain (full-range lower_bound)
        if (hasLeftover)
		{
            std::vector<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), leftover);
            chain.insert(it, leftover);
        }
        return chain;
    }
/******************************************************************************/

    // 5) otherwise recurse on winners
    std::vector<int> sorted_winners = recursePairsImpl(winners, level + 1);

    // 6) after recursion returns, insert current-level losers into sorted_winners
    for (std::size_t k = 0; k < pairs.size(); ++k)
	{
        int loser = pairs[k].first;
        int partner = pairs[k].second;
        insertBeforePartner(sorted_winners, loser, partner);
    }

    // 7) insert leftover if any
    if (hasLeftover)
	{
        std::vector<int>::iterator it = std::lower_bound(sorted_winners.begin(), sorted_winners.end(), leftover);
        sorted_winners.insert(it, leftover);
    }

    return sorted_winners;
}
