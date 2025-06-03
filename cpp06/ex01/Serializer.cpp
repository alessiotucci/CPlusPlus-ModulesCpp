/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Serializer.cpp                                          ( o.o )    */
/*   Created: 2025/05/30 15:25:01 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/03 13:08:32                                   /         */
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
		return (*this);
	}
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

