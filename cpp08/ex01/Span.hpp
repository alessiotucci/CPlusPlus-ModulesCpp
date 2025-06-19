/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Span.hpp                                                ( o.o )    */
/*   Created: 2025/06/19 15:44:14 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/19 15:44:31                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_HPP
# define DEFAULT_HPP

#include <string>

class Default
{
	// some stuff to change here
private:
	std::string _name;
	int _age;
	bool _taken;

public:
	// 1. Default constructor
	Default();
	// 2. Copy constructor
	Default(const Default& other);
	// 3. Copy assignment operator
	Default& operator=(const Default& other);
	// 4. Destructor
	~Default();
	// No member variables or additional methods

};
#endif


