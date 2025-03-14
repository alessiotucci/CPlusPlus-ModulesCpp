/*****************************************************************************
*You should be able to use each of your headers independently from others.   *
*Thus, they must include all the dependencies they need.                     *
*However, you must avoid the problem of double inclusion by adding include guards.
*Otherwise, your grade will be 0.                                            *
*****************************************************************************/

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include "Form.hpp"
class Form;
# define BLUE    "\033[1;34m"
# define PURPLE  "\033[1;35m"
# define GRAY    "\033[1;30m"
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m"
# define RESET   "\033[0m"
# define BG_RESET        "\033[49m"
# define BG_GREEN        "\033[42m"
# define BG_CYAN         "\033[46m"
# define BG_YELLOW       "\033[43m"
# define BG_RED          "\033[41m"

//TODO:
/*A Bureaucrat must have:
 * • a constant name.
 * • a grade that ranges from 1 (highest) to 150 (lowest).
*/

//TODO:
/*You will provide getters for both these attributes:
 * getName();
 * getGrade();
 * Implement also two member functions;
 * increment the bureaucrat grade.
 * decrement the bureaucrat grade.
*/

//TODO:
/*Implement an overload of the insertion («) operator to print something like*/

//TODO:
/* If the grade is out of range,
 * both of them will throw the same exceptions as the constructor.*/
class Bureaucrat
{
	private:
		// private string for name
		std::string _name;

		// private int for the grade
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat & operator = (const Bureaucrat &other);

		// getters
		std::string getName() const;
		int getGrade() const;

		// function to increment
		void IncrementGrade();
		// function to decrement
		void DecrementGrade();

		//TODO: In Bureaucrat.hpp
		void signForm(Form &form) const;

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

// outside the class we try to implement the overload to stream insertion
std::ostream& operator<<(std::ostream &out_file, const Bureaucrat &obj);

// https://www.francescmm.com/orthodox-canonical-class-form/
// implement the class in canonical form

// CONSTRUCTOR
// DESTRUCTOR
// COPY COSTRUCTOR

#endif
