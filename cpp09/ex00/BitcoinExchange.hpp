/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: BitcoinExchange.hpp                                     ( o.o )    */
/*   Created: 2025/06/21 14:02:20 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/05 17:25:27                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>

//TODO: just added those header
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>

class Btc
{

private:
	std::map<std::string, double> _db; // later: database (date -> price)

public:

	Btc();
	Btc(const Btc &other);
	Btc& operator=(const Btc &other);
	~Btc();
	// No member variables or additional methods


	// Load the official bitcoin price DB (not implemented here yet)
	bool loadDatabase(const std::string &dbfile);
	// Process the user-supplied input file (the method we focus on now)
	bool processInputFile(const std::string &inputfile);

};
#endif
