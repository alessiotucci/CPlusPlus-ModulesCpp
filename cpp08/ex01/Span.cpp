/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Span.cpp                                                ( o.o )    */
/*   Created: 2025/06/19 15:44:18 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/23 15:33:23                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
Span::Span(unsigned int N) : _nSize(N)
{
	std::cout << "the max to store is " << N << std::endl;
}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_nSize = other._nSize;
		this->_n = other._n;
	}
	return (*this);
}

Span::~Span() {}

/*TODO:
This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it.
Any attempt to add a new element if there are already N elements stored should throw an exception.
*/
void Span::addNumber(int n)
{
	if (_n.size() >= _nSize)
		throw SpanIsFullException();
	_n.push_back(n);
}
/*TODO:
If there are no numbers stored, or only one, no span can be found. Thus, throw an exception.
*/
int Span::shortestSpan() const
{
	//throw SpanIsEmptyException();
	//throw SpanIsOnlyOneException();
	//throw SpanNotFoundException();
	return (0);
}
int Span::longestSpan() const
{
//throw SpanIsEmptyException();
	//throw SpanIsOnlyOneException();
	//throw SpanNotFoundException();
	return (0);
}
unsigned int Span::getSize() const
{
	return (_nSize);
}

std::vector<int> Span::getVector() const
{
	return (_n);
}

const char	*Span::SpanIsFullException::what() const throw()
{
	return("CUSTOM EXCEPTION: Span is full!!");
}

const char	*Span::SpanIsEmptyException::what() const throw()
{
	return("CUSTOM EXCEPTION: Span is empty!!");
}

const char	*Span::SpanNotFoundException::what() const throw()
{
	return("CUSTOM EXCEPTION: Span not found!!");
}

const char	*Span::SpanIsOnlyOneException::what() const throw()
{
	return("CUSTOM EXCEPTION: there only one number!!!");
}

std::ostream& operator<<(std::ostream &out_file, const Span &obj)
{
	out_file << "Span size: " << obj.getSize() << std::endl;
	unsigned int i = 0;
	std::vector<int> t = obj.getVector();
	while (i < obj.getSize())
	{
		out_file << "Span[" << i << "]" << t[i] << std::endl;
		i++;
	}

	return (out_file);
}


