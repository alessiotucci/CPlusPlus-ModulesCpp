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
// options are:
//1) robotomy request
//2) presidential pardon
//3) shrubbery creation
// Helper to map form names to an integer code
static int formCode(const std::string &name)
{
	if (name == "shrubbery creation")
		return 0;
	if (name == "robotomy request")
		return 1;
	if (name == "presidential pardon")
		return 2;
	return (-1);
}
AForm* Intern::makeForm(std::string nameForm, std::string target)
{
//It will print something like:
//Intern creates <form>
//If the form name passed as parameter doesn’t exist, print an explicit error message.
	int code = formCode(nameForm);
	AForm *form = NULL;
	switch (code)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw NonExistentRequestException();
	}
	std::cout << "Intern creates [" << form->getName() << "]" <<  std::endl;
	return form;
}
