#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExec;
	bool _isSigned;

public:
	AForm(std::string target, int gradeToSign, int gradeToExec);
	// 1. AForm constructor
	AForm();
	// 2. Copy constructor
	AForm(const AForm& other);
	// 3. Copy assignment operator
	AForm& operator=(const AForm& other);
	// 4. virtual Destructor (it is an abstract class)
	virtual ~AForm();
	// No member variables or additional methods

	AForm(int gradeToSign, int gradeToExec);
	// Getters for the private fields
	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	bool isAFormSigned() const;

	void beSigned(const Bureaucrat &bureaucrat);
	void checkRequired(const Bureaucrat &bureaucrat) const;
/*Now, add the execute(Bureaucrat const & executor) const member function to
the base form*/
	virtual void execute(Bureaucrat const & executor) const = 0;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

// outside the class we try to implement the overload operator
std::ostream& operator<<(std::ostream &out_file, const AForm &obj);
#endif
