/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Serializer.cpp                                          ( o.o )    */
/*   Created: 2025/05/30 15:25:01 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/05/30 15:48:15                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */
#include "Serializer.hpp"
Serializer::Serializer(){ }
Serializer::Serializer(const Serializer& other)
{
	*this = other;
}
Serializer::~Serializer(){ }
Serializer& Serializer::operator=(const Serializer& other)
{
	if (this != &other)
	{

	}
	return (*this);
}


