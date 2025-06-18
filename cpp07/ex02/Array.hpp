/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Array.hpp                                               ( o.o )    */
/*   Created: 2025/06/18 15:05:45 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/18 16:55:42                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
/*Develop a class template Array that contains elements of type T and that implements
the following behavior and functions*/
template <class T>
class Array
{

private:
	int _size;
	T *_array;

public:
	/*Construction with no parameter: Creates an empty array.*/
	Array();
	/*Construction with an unsigned int n as a parameter:
	 * Creates an array of n elements initialized by default*/
	Array(unsigned int n);
	Array(const Array &other);
	Array& operator=(const Array &other);
	~Array();

/*Elements can be accessed through the subscript operator: [ ].*/
	// operator[]
/*A member function size() that returns the number of elements in the array. This
member function takes no parameters and must not modify the current instance.*/
	int size() const;

/*When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown*/
	public:
		class ArrayOutOfBoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif


