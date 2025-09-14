/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: BitcoinExchange.hpp                                     ( o.o )    */
/*   Created: 2025/06/21 14:02:20 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/14 17:55:15                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

//TODO: just added those header
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>

//COLORS
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
