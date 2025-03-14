#ifndef DEFAULT_HPP
# define DEFAULT_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExec;
	bool _isSigned;

public:
	// 1. Form constructor
	Form();
	// 2. Copy constructor
	Form(const Form& other);
	// 3. Copy assignment operator
	Form& operator=(const Form& other);
	// 4. Destructor
	~Form();
	// No member variables or additional methods

	Form(int gradeToSign, int gradeToExec);
	// Getters for the private fields
	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	bool isFormSigned() const;

	//TODO: In Form.hpp
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
std::ostream& operator<<(std::ostream &out_file, const Form &obj);
#endif
