#include "Intern.hpp"
#include "AForm.hpp"
//TODO:

Intern::Intern()
{ }

// 2. Copy constructor
Intern::Intern(const Intern& other)
{
	*this = other;
	return ;
}

// 3. Copy assignment operator
Intern& Intern::operator=(const Intern& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

// 4. Destructor
Intern::~Intern() { }


//TODO: implement this function
AForm* Intern::makeForm(std::string nameForm, std::string target)
{
	(void)nameForm; (void)target;
	AForm *form;
	form = 0;
	return (form);
//It will print something like:
//Intern creates <form>
//If the form name passed as parameter doesn’t exist, print an explicit error message.
}
