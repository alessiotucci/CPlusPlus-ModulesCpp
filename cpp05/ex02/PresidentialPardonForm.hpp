#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm
{
	// some stuff to change here
private:
	std::string _target;

public:
	// 1. PresidentialPardonForm constructor
	PresidentialPardonForm();
	// 2. Copy constructor
	PresidentialPardonForm(const PresidentialPardonForm& other);
	// 3. Copy assignment operator
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	// 4. Destructor
	virtual ~PresidentialPardonForm();
	// No member variables or additional methods

};
#endif


