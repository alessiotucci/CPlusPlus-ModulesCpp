/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: DataStructure.cpp                                       ( o.o )    */
/*   Created: 2025/05/30 15:25:51 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/05/30 15:48:38                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "DataStructure.hpp"
DataStructure::DataStructure(){ }
DataStructure::DataStructure(const DataStructure& other)
{
	*this = other;
}
DataStructure::~DataStructure(){ }
DataStructure& DataStructure::operator=(const DataStructure& other)
{
	if (this != &other)
	{

	}
	return (*this);
}
