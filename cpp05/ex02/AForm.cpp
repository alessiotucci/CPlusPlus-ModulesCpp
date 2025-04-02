//TODO: update this class implementation to be abstract
#include "AForm.hpp"

//0) Constructor with parameters (has to raised exceptions)
AForm::AForm(int gradeToSign, int gradeToExec) : _name("Default Form"), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	//TODO: this is not allowed
/*	this->_gradeToSign = gradeToSign;
	this->_gradeToExec = gradeToExec;*/
}
//1)Default constructor implementation
AForm::AForm() : _name("Default AForm"),  _gradeToSign(150), _gradeToExec(150), _isSigned(false)
{ }

//2)Copy constructor
AForm::AForm(const AForm& other) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
	*this = other;
	return ;
}

//3)Copy assign operator
AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}

//4)Destructor
AForm::~AForm() {}

//GETTER
std::string AForm::getName() const
{
	return (this->_name);
}

//GETTER
int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

//GETTER
int AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

//GETTER
bool AForm::isAFormSigned() const
{
	return (this->_isSigned);
}

//TODO implement this function
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	//Example
	// buro grade : 5 > form grade needed is 1
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else
	{
		this->_isSigned = true;
	}
}

// Exception what() implementations
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

//OVERLOAD OF THE PRINT OPERATOR
std::ostream& operator<< (std::ostream &out_file, const AForm &obj)
{
	out_file << obj. getName()
	<< "grade to sign: ["
	<< obj.getGradeToSign()
	<< "]" << std::endl
	<< "grate to exect: ["
	<< obj.getGradeToExec()
	<< "]" << std::endl
	<< "is it signed: [" 
	<< obj.isAFormSigned()
	<< "]" << std::endl;
	return (out_file);
}
