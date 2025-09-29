/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: PmergeMe.cpp                                            ( o.o )    */
/*   Created: 2025/06/21 14:06:38 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/29 10:39:44                                   /         */
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

//TODO:
static void DequePrint(const std::deque<int> &d)
{
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
	DequePrint(d);
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
	//TODO: Before filling check if it is already sorted!
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

void printPairs(const std::vector< std::pair<int, int> > &pairs, size_t index)
{
	// Now print them with colors
	std::cout << std::endl;
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		if (index != i)
			std::cout << " [" << pairs[i].first << ", " << pairs[i].second << "] ";
		else
			std::cout << " [" << YELLOW << pairs[i].first << ", " << pairs[i].second << RESET << "] ";
	}
	std::cout << std::endl;
}

//void Pmergeme::swapPairs(std::vector< std::pair<int,int> > &pairs, bool hasLeftover, int leftover, int level) const
void Pmergeme::swapPairsVector(std::vector< std::pair<int,int> > &pairs, bool hasLeftover, int leftover) const
{
	// Normalize pairs so that .first is always the winner (larger)
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first > pairs[i].second)
		{
			std::swap(pairs[i].first, pairs[i].second);
		}
	}
	(void)hasLeftover; (void)leftover;
	/*
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
	*/
}


void Pmergeme::recursePairsDeque(const std::deque<int> &elements) const
{
	std::cout << "Before: ";
	DequePrint(elements);
	clock_t start = clock();
	std::deque<int> result = recursePairsImplDeque(elements, 0);
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0; // convert to microseconds
	std::cout << "After: ";
	DequePrint(result);
	std::cout << "Time to process a range of " << elements.size() 
			  << " elements with std::deque : " 
			  << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
}

void Pmergeme::recursePairs(const std::vector<int> &elements) const
{
	std::cout << "Before: ";
	VectorPrint(elements);
	clock_t start = clock();
	std::vector<int> result = recursePairsImpl(elements, 0);
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0; // convert to microseconds
	std::cout << "After: ";
	VectorPrint(result);
	std::cout << "Time to process a range of " << elements.size() 
			  << " elements with std::vector : " 
			  << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
}

static std::size_t power_of_two(std::size_t exp)
{
	std::size_t result = 1;
	for (std::size_t i = 0; i < exp; ++i)
	{
		result *= 2u;
	}
	return result;
}

// Generate Jacobsthal-like indices up to limit
std::vector<std::size_t> jacobsthal_indices(std::size_t limit)
{
	std::vector<std::size_t> indices;
	if (limit == 0)
		return indices;
	
	// Base cases: t0 = 1, t1 = 1
	std::vector<std::size_t> sequence;
	sequence.push_back(1); 
	sequence.push_back(1); 
	
	// Build sequence until >= limit
	std::size_t k = 1;
	while (sequence[k] < limit)
	{
		++k;
		std::size_t next_value = power_of_two(k) - sequence[k - 1];
		sequence.push_back(next_value);
	}
	
	// Track the smallest lower bound we reach
	std::size_t lowest_lower = limit + 1; // Initialize to a value larger than any possible lower
	
	// Generate blocks of indices
	for (std::size_t idx = 2; idx < sequence.size(); ++idx)
	{
		std::size_t upper;
		if (sequence[idx] <= limit)
			upper = sequence[idx];
		else
			upper = limit;
		std::size_t lower = sequence[idx - 1] + 1;
		if (lower > upper)
		 	continue;
		
		// Track the smallest lower we encounter
		if (lower < lowest_lower)
			lowest_lower = lower;
			
		for (std::size_t j = upper; j >= lower; --j)
		{
			indices.push_back(j);
			if (j == lower) break; // prevent unsigned underflow
		}
	}
	
	// Now add the remainder: everything below lowest_lower, starting from 1 (not 2!)
	std::size_t start_remainder = 1;
	if (lowest_lower <= limit + 1)
	{
		for (std::size_t j = lowest_lower - 1; j >= start_remainder; --j)
		{
			indices.push_back(j);
			if (j == start_remainder)
				break; // prevent unsigned underflow
		}
	}
	else
	{
		// No blocks were generated, add all from limit down to start_remainder
		for (std::size_t j = limit; j >= start_remainder; --j)
		{
			indices.push_back(j);
			if (j == start_remainder)
				break; // prevent unsigned underflow
		}
	}
	
	return indices;
}



// helper: insert 'loser' into sorted 'chain' so that it appears before 'partner'.
// Tries the immediate predecessor first (cheap) then falls back to lower_bound.
static void insertBeforePartner(std::vector<int> &chain, int loser, int partner)
{
//	std::cout << "\ninsert loser [" << loser << "]" << " before partner [" << partner << "]" << std::endl;
	
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
/*
	VectorPrint(chain);
	std::cout << "if not found (shouldn't happen), insert by global lower_bound as fallback " << std::endl;
	std::cout << std::endl;
*/
        return;
    }

    // partner is at pIdx; we must insert somewhere in [0 .. pIdx] (before partner)
    if (pIdx == 0)
	{
        chain.insert(chain.begin(), loser);
/*
	VectorPrint(chain);
	std::cout << "partner is at pIdx; we must insert somewhere in [0 .. pIdx] (before partner) " << std::endl;
	std::cout << std::endl;
*/
        return;
    }

   // try immediate predecessor first (this uses only one comparison)
    int pred = chain[pIdx - 1];
    if (loser >= pred)
	{
        // fits between pred and partner
        chain.insert(chain.begin() + pIdx, loser);
/*
	VectorPrint(chain);
	std::cout << "try immediate predecessor first (this uses only one comparison) " << std::endl;
	std::cout << std::endl;
*/
        return;
    }
    // otherwise binary search on [0 .. pIdx-1)
    std::vector<int>::iterator it = std::lower_bound(chain.begin(), chain.begin() + pIdx, loser);
    chain.insert(it, loser);
}

static void insertLosersByJacobsthal(std::vector<int> &chain, const std::vector< std::pair<int,int> > &pairs)
{
	if (pairs.empty())
		return;
	// compute Knuth/Jacobsthal index order (1-based indices)
	std::vector<std::size_t> order = jacobsthal_indices(pairs.size());
	for (std::size_t i = 0; i < order.size(); ++i)
	{
		//std::cout << "order[i] " << order[i] << std::endl;
		std::size_t idx = order[i];

		if (idx == 0 || idx > pairs.size())
			continue; // safety

		int loser   = pairs[idx - 1].first;
		int partner = pairs[idx - 1].second;

		/*
		printPairs(pairs, idx);
		std::cout << "accessing pairs at index: " << idx - 1 << std::endl;
		std::cout  <<"int loser   =  " << pairs[idx - 1].first << std::endl;
		std::cout  <<"int partner =  " << pairs[idx - 1].second << std::endl;
		*/

		// skip if loser already in chain (defensive)
		bool present = false;
		for (std::size_t z = 0; z < chain.size(); ++z)
		{
			if (chain[z] == loser)
			{
			present = true;
			break;
			}
		}
		if (present)
			continue;
		insertBeforePartner(chain, loser, partner);
	}
}

void Pmergeme::buildPairsFromVector(const std::vector<int> &elements, std::vector< std::pair<int,int> > &outPairs, bool &hasLeftover, int &leftover) const
{
	outPairs.clear();
	hasLeftover = false;
	leftover = 0;

	std::size_t i = 0;
	for (; i + 1 < elements.size(); i += 2)
	{
		outPairs.push_back(std::make_pair(elements[i], elements[i + 1]));
	}
	if (i < elements.size())
	{
		hasLeftover = true;
		leftover = elements[i];
	}
}

void Pmergeme::collectWinnersFromPairsDeque(const std::deque< std::pair<int,int> > &pairs, std::deque<int> &winners) const
{
    winners.clear();
    for (std::size_t i = 0; i < pairs.size(); ++i)
    {
        winners.push_back(pairs[i].second);
    }
}

void Pmergeme::collectWinnersFromPairs(const std::vector< std::pair<int,int> > &pairs, std::vector<int> &winners) const
{
	winners.clear();
	winners.reserve(pairs.size());
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		winners.push_back(pairs[i].second);
	}
}

static std::vector<int> buildBaseChainFromWinners(const std::vector<int> &winners)
{
	std::vector<int> chain;
	if (winners.size() == 2)
	{
		int a = winners[0];
		int b = winners[1];
		if (a <= b) //TODO: comparision
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
	}
	return chain;
}

static std::deque<int> buildBaseChainFromWinnersDeque(const std::deque<int> &winners)
{
    std::deque<int> chain;
    if (winners.size() == 2)
    {
        int a = winners[0];
        int b = winners[1];
        if (a <= b) //TODO: comparision
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
    }
    return chain;
}

static void insertLeftoverIntoChainDeque(std::deque<int> &chain, bool hasLeftover, int leftover)
{
    if (!hasLeftover)
        return;
    std::deque<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), leftover); //TODO: using lower_bound (check if it's allowed)
    chain.insert(it, leftover);
}

static void insertLeftoverIntoChain(std::vector<int> &chain, bool hasLeftover, int leftover)
{
	if (!hasLeftover)
		return;
	std::vector<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), leftover); //TODO: using lowerbond (check if it's allowed)
	chain.insert(it, leftover);
}

// recursive implementation that returns the sorted chain for this subtree.
// Public wrapper (recursePairs) will just call this and ignore the return or print final result.
std::vector<int> Pmergeme::recursePairsImpl(const std::vector<int> &elements, int level) const
{
	std::vector< std::pair<int,int> > pairs;
	bool hasLeftover = false;
	int leftover = 0;
	buildPairsFromVector(elements, pairs, hasLeftover, leftover);
	swapPairsVector(pairs, hasLeftover, leftover);
	std::vector<int> winners;
	collectWinnersFromPairs(pairs, winners);

	/* print statement to debug*/
	/*
	std::cout << "Winners vector:\n";
	VectorPrint(winners);
	*/

	if (winners.size() <= 2)
	{
		std::vector<int> chain = buildBaseChainFromWinners(winners);
		insertLosersByJacobsthal(chain, pairs);
		insertLeftoverIntoChain(chain, hasLeftover, leftover);
		return (chain); // TODO: chain is what we return
	}
	std::vector<int> sorted_winners = recursePairsImpl(winners, level + 1);
	insertLosersByJacobsthal(sorted_winners, pairs);
	// 6) insert leftover if any
	if (hasLeftover)
	{
		//std::cout << "Step 6) inserting the leftover" << std::endl;
		std::vector<int>::iterator it = std::lower_bound(sorted_winners.begin(), sorted_winners.end(), leftover);
		sorted_winners.insert(it, leftover);
	}
	return sorted_winners;
}

void Pmergeme::buildPairsFromDeque(const std::deque<int> &elements, std::deque< std::pair<int,int> > &outPairs, bool &hasLeftover, int &leftover) const
{
    outPairs.clear();
    hasLeftover = false;
    leftover = 0;

    std::size_t i = 0;
    for (; i + 1 < elements.size(); i += 2)
    {
        outPairs.push_back(std::make_pair(elements[i], elements[i + 1]));
    }
    if (i < elements.size())
    {
        hasLeftover = true;
        leftover = elements[i];
    }
}

//void Pmergeme::swapPairsDeque(std::deque< std::pair<int,int> > &pairs, bool hasLeftover, int leftover, int level) const
void Pmergeme::swapPairsDeque(std::deque< std::pair<int,int> > &pairs, bool hasLeftover, int leftover) const
{
	// Normalize pairs so that .first is always the winner (larger)
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first > pairs[i].second)
		{
			std::swap(pairs[i].first, pairs[i].second);
		}
	}
	(void)hasLeftover; (void)leftover;
	/*
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
	*/
}

// helper: insert 'loser' into sorted 'chain' so that it appears before 'partner'.
// Tries the immediate predecessor first (cheap) then falls back to lower_bound.
static void insertBeforePartnerDeque(std::deque<int> &chain, int loser, int partner)
{
//	std::cout << "\ninsert loser [" << loser << "]" << " before partner [" << partner << "]" << std::endl;

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
        std::deque<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), loser);
        chain.insert(it, loser);
/*
    DequePrint(chain);
    std::cout << "if not found (shouldn't happen), insert by global lower_bound as fallback " << std::endl;
    std::cout << std::endl;
*/
        return;
    }

    // partner is at pIdx; we must insert somewhere in [0 .. pIdx] (before partner)
    if (pIdx == 0)
    {
        chain.insert(chain.begin(), loser);
/*
    DequePrint(chain);
    std::cout << "partner is at pIdx; we must insert somewhere in [0 .. pIdx] (before partner) " << std::endl;
    std::cout << std::endl;
*/
        return;
    }

   // try immediate predecessor first (this uses only one comparison)
    int pred = chain[pIdx - 1];
    if (loser >= pred)
    {
        // fits between pred and partner
        chain.insert(chain.begin() + pIdx, loser);
/*
    DequePrint(chain);
    std::cout << "try immediate predecessor first (this uses only one comparison) " << std::endl;
    std::cout << std::endl;
*/
        return;
    }

    // otherwise binary search on [0 .. pIdx-1)
    std::deque<int>::iterator it = std::lower_bound(chain.begin(), chain.begin() + pIdx, loser);
    chain.insert(it, loser);
}

static void insertLosersByJacobsthalDeque(std::deque<int> &chain, const std::deque< std::pair<int,int> > &pairs)
{
    if (pairs.empty())
        return;
    // compute Knuth/Jacobsthal index order (1-based indices)
    std::vector<std::size_t> order = jacobsthal_indices(pairs.size());
    for (std::size_t i = 0; i < order.size(); ++i)
    {
        //std::cout << "order[i] " << order[i] << std::endl;
        std::size_t idx = order[i];

        if (idx == 0 || idx > pairs.size())
            continue; // safety

        int loser   = pairs[idx - 1].first;
        int partner = pairs[idx - 1].second;

        /*
        printPairsDeque(pairs, idx);
        std::cout << "accessing pairs at index: " << idx - 1 << std::endl;
        std::cout  <<"int loser   =  " << pairs[idx - 1].first << std::endl;
        std::cout  <<"int partner =  " << pairs[idx - 1].second << std::endl;
        */

        // skip if loser already in chain (defensive)
        bool present = false;
        for (std::size_t z = 0; z < chain.size(); ++z)
        {
            if (chain[z] == loser)
            {
                present = true;
                break;
            }
        }
        if (present)
            continue;
        insertBeforePartnerDeque(chain, loser, partner);
    }
}



// recursive implementation that returns the sorted chain for this subtree.
// Public wrapper (recursePairs) will just call this and ignore the return or print final result.
std::deque<int> Pmergeme::recursePairsImplDeque(const std::deque<int> &elements, int level) const
{
    std::deque< std::pair<int,int> > pairs;
    bool hasLeftover = false;
    int leftover = 0;
    buildPairsFromDeque(elements, pairs, hasLeftover, leftover);
    swapPairsDeque(pairs, hasLeftover, leftover);
    std::deque<int> winners;
    collectWinnersFromPairsDeque(pairs, winners);

    /* print statement to debug*/
    /*
    std::cout << "Winners deque:\n";
    DequePrint(winners);
    */

    if (winners.size() <= 2)
    {
        std::deque<int> chain = buildBaseChainFromWinnersDeque(winners);
        insertLosersByJacobsthalDeque(chain, pairs);
        insertLeftoverIntoChainDeque(chain, hasLeftover, leftover);
        return (chain); // TODO: chain is what we return
    }
    std::deque<int> sorted_winners = recursePairsImplDeque(winners, level + 1);
    insertLosersByJacobsthalDeque(sorted_winners, pairs);
    // 6) insert leftover if any
    if (hasLeftover)
    {
        //std::cout << "Step 6) inserting the leftover" << std::endl;
        std::deque<int>::iterator it = std::lower_bound(sorted_winners.begin(), sorted_winners.end(), leftover);
        sorted_winners.insert(it, leftover);
    }
    return sorted_winners;
}
