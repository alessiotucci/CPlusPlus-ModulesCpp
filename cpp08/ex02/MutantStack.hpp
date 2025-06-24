/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: MutantStack.hpp                                         ( o.o )    */
/*   Created: 2025/06/19 15:45:38 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/24 11:45:24                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

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

#include <vector>
#include <deque>
#include <stack>
#include <stdexcept>
#include <iterator>  // distance
#include <iostream>

					// CT = container type default is deque
template <typename T, typename CT = std::deque<T> >
class MutantStack : public std::stack<T, CT>
{
public:
	//MutantStack constructor: those constructor need to call
	//Orthodox canonical form (?)
	MutantStack() : std::stack<T, CT>() {};
	MutantStack(const MutantStack<T, CT> &obj): std::stack<T, CT>(obj) { *this = obj; }
	MutantStack& operator=(const MutantStack &obj)
	{
		if (this != &obj)
			this->c = obj.c;
		return (*this);
	};
	~MutantStack() {};

	//TODO: Implementation of the iterators
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
};
#endif
