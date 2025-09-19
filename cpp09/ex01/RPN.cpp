/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: RPN.cpp                                                 ( o.o )    */
/*   Created: 2025/06/21 14:03:45 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/19 16:46:21                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn()
{

}

Rpn::~Rpn()
{

}

Rpn::Rpn(const Rpn& other)
{
	*this = other;
	return;
}

std::stack<int> Rpn::getStack() const
{
	return (_Stack);
}

Rpn& Rpn::operator=(const Rpn& other)
{
	if (this != &other)
	{
		this->_Stack = other.getStack();
	}
	return (*this);
}



