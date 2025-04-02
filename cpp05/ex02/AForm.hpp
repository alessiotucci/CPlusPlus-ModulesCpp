#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

/*TODO: update this class to be ABSTRACT */
class AForm
{
private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExec;
	bool _isSigned;

public:
	// 1. AForm constructor
	AForm();
	// 2. Copy constructor
	AForm(const AForm& other);
	// 3. Copy assignment operator
	AForm& operator=(const AForm& other);
	// 4. Destructor
	~AForm();
	// No member variables or additional methods

	AForm(int gradeToSign, int gradeToExec);
	// Getters for the private fields
	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	bool isAFormSigned() const;

	//TODO: In AForm.hpp
	void beSigned(const Bureaucrat &bureaucrat);
	 // nested class for exception
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

};

// outside the class we try to implement the overload operator
std::ostream& operator<<(std::ostream &out_file, const AForm &obj);
#endif
