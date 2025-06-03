/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: DataStructure.cpp                                       ( o.o )    */
/*   Created: 2025/05/30 15:25:51 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/03 12:34:34                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
Data::Data(): prefix(0), suffix(0) { }
Data::Data(int prefix, int suffix): prefix(prefix), suffix(suffix) { }
Data::Data(const Data& other)
{
	*this = other;
}
Data::~Data(){ }
Data& Data::operator=(const Data& other)
{
	if (this != &other)
	{
		this->prefix = other.prefix;
		this->suffix = other.suffix;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output, const Data param)
{
	output << "DATA STRUCTURE:" << std::endl;
	output << "prefix: "<< param.prefix << std::endl;
	output << "suffix: "<< param.suffix<< std::endl;
	return output;
}
