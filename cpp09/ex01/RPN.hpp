/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: RPN.hpp                                                 ( o.o )    */
/*   Created: 2025/06/21 14:03:41 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/19 17:47:37                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
# define RNP_HPP

#include <iostream>
#include <stack> // Required header for std::stack
#include <sstream> // Required to split the input

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

class Rpn
{
private:
	std::stack<int> _Stack;

public:
	Rpn();
	Rpn(const Rpn& other);
	Rpn& operator=(const Rpn& other);
	~Rpn();

	std::stack<int> getStack() const;
	int evaluateToken(const std::string &tok);
	int splitInput(const std::string &phrase);

};
#endif


