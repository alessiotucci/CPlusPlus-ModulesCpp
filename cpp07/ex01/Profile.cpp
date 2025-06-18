/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Profile.cpp                                             ( o.o )    */
/*   Created: 2025/06/18 11:09:33 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/18 11:38:26                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "Profile.hpp"
Profile::Profile() : _name("empty"), _age(0), _taken(false)
{
//	std::cout << "Default constructor called!!\n";
}

Profile::Profile(std::string name, int age, bool taken) : _name(name), _age(age), _taken(taken)
{
//	std::cout << "Parameter constructor called!!\n";
}

Profile::Profile(const Profile& other)
{
	*this = other;
}

Profile& Profile::operator=(const Profile& other)
{
	if (this != &other)
	{
		this->_age = other.getAge();
		this->_name = other.getName();
		this->_taken = other.isTaken();
	}
	return *this;
}

Profile::~Profile()
{
//	std::cout << "Destructor called!!\n";
}


int Profile::getAge() const
{
	return _age;
}

std::string Profile::getName() const
{
	return _name;
}

bool Profile::isTaken() const
{
	return _taken;
}

std::ostream& operator<<(std::ostream& output, const Profile param)
{
	output << "PROFILE INFO\n";
	output << "Name: " << param.getName() << std::endl;
	output << "Age: " << param.getAge() << std::endl;
	output << "taken: " << param.isTaken() << std::endl;
	return (output);
}
