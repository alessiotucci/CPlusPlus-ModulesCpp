/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: BitcoinExchange.cpp                                     ( o.o )    */
/*   Created: 2025/06/21 14:02:23 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/15 11:16:32                                   /         */
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
	{
		std::cout << RED << "Invalid: " << RESET << "wrong month: " << month << std::endl;
		return (false);
	}
	if (day < 1 || day > 31)
	{
		std::cout << RED << "Invalid: " << RESET << "wrong day: " << day << std::endl;
		return (false);
	}

	// Basic sanity: year should be non-zero (you can relax/change this if needed)
	int year = std::atoi(y.c_str());
	if (year < 0)
	{
		std::cout << RED << "Invalid: " << RESET << "wrong year: " << year << std::endl;
		return (false);
	}

	return (true);
}

// Parse a single input line "YYYY-MM-DD | value".
// Returns true if the line contains a valid pair (stored in out_date/out_value).
// On invalid format/date returns false (caller prints appropriate message).
static bool parseInputLine(const std::string &line, std::string &out_date, double &out_value)
{
	std::string::size_type bar = line.find('|');
	if (bar == std::string::npos)
		return false;

	std::string left = trim(line.substr(0, bar));
	std::string right = trim(line.substr(bar + 1));

	if (left.empty() || right.empty())
		return false;

	if (!isValidDate(left))
		return false;

	// parse numeric value using stringstream (robust for floats/ints)
	std::stringstream ss(right);
	double val;
	if (!(ss >> val))
		return false;

	// ensure there isn't trailing non-space garbage
	std::string rest;
	if (ss >> rest)
		return false;

	out_date = left;
	out_value = val;
	return true;
}

// ----- Public API -----
bool Btc::loadDatabase(const std::string &dbfile)
{
	// Placeholder: For now, just check file can be opened.
	std::ifstream ifs(dbfile.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Error: could not open database file." << std::endl;
		return false;
	}
	// Real parsing into _db will be implemented later.
	// Close and return true for now.
	ifs.close();
	return true;
}

bool Btc::processInputFile(const std::string &inputfile)
{
	std::cout << YELLOW << "DEBUG LOG: " << RESET << inputfile << std::endl;
	std::ifstream infile(inputfile.c_str());
	if (!infile.is_open())
	{
		std::cout << RED << "Error: " << RESET << "could not open file." << std::endl;
		return false;
	}
	std::string line;
	bool first = true;
	while (std::getline(infile, line))
	{
		// Trim line and skip empty lines
		std::string tline = trim(line);
		if (tline.empty())
			continue;
		// Skip the header if present (exact header from subject: "date | value")
		if (first)
		{
			first = false;
			std::string low = tline;
			// naive check of header
			if (low == "date | value" || low == "date|value")
				continue;
			// else fall through: treat as a data line
		}
		std::string date;
		double value;
		bool ok = parseInputLine(tline, date, value);
		if (!ok)
		{
			std::cout<< RED << "Error: " << RESET << "bad input => " << tline << std::endl;
			continue;
		}
		// Now check range constraints: must be 0 <= value <= 10000 (subject)
		if (value < 0.0)
		{
			std::cout << RED << "Error: " << RESET << "not a positive number.\n=> " << tline << std::endl;
			continue;
		}
		if (value > 10000.0)
		{
			std::cout << RED << "Error: " << RESET << "too large a number.\n=> " << value << std::endl;
			continue;
		}
		// If everything ok, store input line for later processing
	}
	infile.close();
	return true;
}

