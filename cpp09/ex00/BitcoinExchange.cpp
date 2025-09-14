/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: BitcoinExchange.cpp                                     ( o.o )    */
/*   Created: 2025/06/21 14:02:23 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/14 16:04:15                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::Btc() : _db()
{

}

Btc::Btc(const Btc &other)
{
	*this = other;
}

Btc& Btc::operator=(const Btc &other)
{
	if (this != &other)
	{
		_db = other._db;
	}
	return (*this);
}

Btc::~Btc()
{

}


// Helpers
static std::string trim(const std::string &s)
{
	std::size_t i = 0;
	while ()
		i++;
}

// Helpers
static bool isDigits(const std::string &s)
{
	if (s.empty())
		return (false);
	for (std::size_t i = 0; i < s.size(); ++i)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return (false);
	return (true);

}

// It is not a full calendar validator (no leap-year/month-length exact checks),

// Very basic date validation for format YYYY-MM-DD and reasonable month/day ranges.
// but it is enough to catch malformed dates as required by the subject.
static bool isValidDate(const std::string &date)
{

}

// Parse a single input line "YYYY-MM-DD | value".
// Returns true if the line contains a valid pair (stored in out_date/out_value).
// On invalid format/date returns false (caller prints appropriate message).
static bool parseInputLine(const std::string &line, std::string &out_date, double &out_value)
{

}

// ----- Public API -----
bool Btc::loadDatabase(const std::string &dbfile)
{

}

bool Btc::processInputFile(const std::string &inputfile)
{

}

