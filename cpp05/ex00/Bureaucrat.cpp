//TODO
#include "Bureaucrat.hpp"
#include <iostream> //TO USE THE PRINT STATEMENTS

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(int grade)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat & operator = (const Bureaucrat &other)
{

}

//TODO: getters
// GETTER METHOD

// Prefer using direct access to member variables for cleaner code:
// int my_getter()
// {
// 		return _private_var;
// 	}
// Use 'this->' only if there's a naming conflict:
// int my_getter(int _private_var)
// {
// 		return this->_private_var;
// }

std::string getName() const
{
	return (this->_name);
}

int getGrade() const
{
	return (this->_grade);
}

