/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: DataStructure.hpp                                       ( o.o )    */
/*   Created: 2025/05/30 15:25:48 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/01 18:05:57                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATASTRUCTURE_HPP
#define DATASTRUCTURE_HPP

#include <string>
#include <iostream>

class DataStructure
{
private:

public:
	DataStructure();
	DataStructure(int prefix, int suffix);
	DataStructure(const DataStructure& other);
	DataStructure& operator=(const DataStructure& other);
	~DataStructure();
	int prefix;
	int suffix;
};

std::ostream& operator<<(std::ostream& output, const DataStructure param);
#endif


