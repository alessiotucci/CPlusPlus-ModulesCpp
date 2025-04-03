#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

//1) Constructor: Calls the base class constructor with the form's name and required grades.
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

//2) Copy constructor.
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

//3) Copy assignment operator (Call base class assignment operator)
ShrubberyCreationForm::ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

//4) Destructor.
ShrubberyCreationForm:~ShrubberyCreationForm() {}


//TODO: implement the execute function
