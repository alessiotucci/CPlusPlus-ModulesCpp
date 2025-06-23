/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Span.hpp                                                ( o.o )    */
/*   Created: 2025/06/19 15:44:14 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/23 14:03:05                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

// Span.hpp
#ifndef SPAN_HPP
#define SPAN_HPP

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
#include <stdexcept>
#include <algorithm> // sort, min_element, max_element
#include <iterator>  // distance
#include <iostream>


class Span
{
	// some stuff to change here
private:
	unsigned int _nSize;
	std::vector<int> _n;


public:
	// 1. Span constructor
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
	//custom function
	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;

// nested class for the custom exception
	public:
		class SpanIsFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class SpanNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class SpanIsEmptyException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class SpanIsOnlyOneException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

// template function to add variety of numbers using iterators
	template <typename T>
	void addRange(T begin, T end)
	{
		(void)begin;(void)end;
	}
};
//overload to output
std::ostream& operator<<(std::ostream& output, const Span param);
#endif


