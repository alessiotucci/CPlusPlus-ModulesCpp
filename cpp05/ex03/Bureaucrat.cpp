//TODO
#include "Bureaucrat.hpp"
#include <iostream> //TO USE THE PRINT STATEMENTS
#include "AForm.hpp"
//Default constructor implementation
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) // lowest grade
{ }

// Exception what() implementations
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		_grade = grade;
	}
}

//simple the destructor
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	*this = other;
	return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	this->_grade = other.getGrade();
	return (*this);
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

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/*An accessor function, also known as a getter function,
 * is a member function of a class that returns the value of a private data member.
 * The purpose of an accessor function is to provide
 * READ-ONLY access to the PRIVATE DATA MEMBER.
 * */

std::ostream& operator<<(std::ostream &out_file, const Bureaucrat &obj)
{
	out_file << obj.getName()
	<< ", " << "bureaucrat grade "
	<< obj.getGrade() << std::endl;

	return (out_file);
}

//TODO: those two function are attempting an operation
void Bureaucrat::IncrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::DecrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

//TODO: In Bureaucrat.hpp
void Bureaucrat::signForm(AForm &form) const
{
	//TODO: UPDATE
	try
	{
		//TODO: Update this shit
		form.beSigned(*this); // calling the form function with this as param
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(std:: exception &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName()
		<< "because [" << e.what()  << "] " << std::endl;
	}
}

