/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Profile.hpp                                             ( o.o )    */
/*   Created: 2025/06/18 11:09:27 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/18 11:23:08                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */
#ifndef PROFILE_HPP
# define PROFILE_HPP

#include <string>
#include <iostream>

class Profile
{
	// some stuff to change here
private:
	std::string _name;
	int _age;
	bool _taken;

public:
	// 1. Profile constructor
	Profile();
	Profile(std::string name, int age, bool taken);
	// 2. Copy constructor
	Profile(const Profile& other);
	// 3. Copy assignment operator
	Profile& operator=(const Profile& other);
	// 4. Destructor
	~Profile();
	int getAge();
	std::string getName();
	bool isTaken();
};

//overload to output
std::ostream& operator<<(std::ostream& output, const Profile param);
#endif


