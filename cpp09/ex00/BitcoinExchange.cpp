/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: BitcoinExchange.cpp                                     ( o.o )    */
/*   Created: 2025/06/21 14:02:23 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/14 16:12:41                                   /         */
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
	std::size_t start = 0;
	//First while to skipping leading spaces
	while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
		++start;

	//If the counter is equal to the string size (meaning there are only spaces)
	// return an empty string (might actually want to handle this better)
	if (start == s.size())
		return std::string();

	//Second while to cut the space at the end
	std::size_t end = s.size() - 1;
	while (end > start && std::isspace(static_cast<unsigned char>(s[end])))
		--end;

	//Returning the string without any spaces (before and after)
	return s.substr(start, end - start + 1);
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
	// format YYYY-MM-DD size:10
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	std::string y = date.substr(0, 4);
	std::string m = date.substr(5, 2);
	std::string d = date.substr(8, 2);

	if (!isDigits(y) || !isDigits(m) || !isDigits(d))
		return (false);

	int month = std::atoi(m.c_str());
	int day = std::atoi(d.c_str());
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);

	// Basic sanity: year should be non-zero (you can relax/change this if needed)
	int year = std::atoi(y.c_str());
	if (year < 0)
		return (false);

	return (true);
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

