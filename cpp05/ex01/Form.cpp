//TODO:
#include "Form.hpp"

//1)Default constructor implementation
Form::Form() : _name("Default Form"),  _gradeToSign(150), _gradeToExec(150), _isSigned(false)
{ }

//2)Copy constructor
Form::Form(const Form& other) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
	*this = other;
	return ;
}

//3)Copy assign operator
Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}

//4)Destructor
Form::~Form() {}

//GETTER
std::string Form::getName() const
{
	return (this->_name);
}

//GETTER
int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

//GETTER
int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

//GETTER
bool Form::isFormSigned() const
{
	return (this->_isSigned);
}

//TODO implement this function
void Form::beSigned(const Bureaucrat &bureaucrat)
{

}

//OVERLOAD OF THE PRINT OPERATOR
std::ostream& operator<< (std::ostream &out_file, const Form &obj)
{
	out_file << obj. getName()
	<< "grade to sign: ["
	<< obj.getGradeToSign()
	<< "]" << std::endl
	<< "grate to exect: ["
	<< obj.getGradeToExec()
	<< "]" << std::endl
	<< "is it signed: [" 
	<< obj.isFormSigned()
	<< "]" << std::endl;
	return (out_file);
}
