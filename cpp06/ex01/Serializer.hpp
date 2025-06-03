/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Serializer.hpp                                          ( o.o )    */
/*   Created: 2025/05/30 15:24:49 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/03 12:33:19                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <string>
#include "Data.hpp"
/*
https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type
*/
class Serializer
{
	// some stuff to change here
private:
public:
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();

};


#endif
