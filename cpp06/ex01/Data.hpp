/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: DataStructure.hpp                                       ( o.o )    */
/*   Created: 2025/05/30 15:25:48 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/03 12:34:10                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data
{
private:

public:
	Data();
	Data(int prefix, int suffix);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();
	int prefix;
	int suffix;
};

std::ostream& operator<<(std::ostream& output, const Data param);
#endif


