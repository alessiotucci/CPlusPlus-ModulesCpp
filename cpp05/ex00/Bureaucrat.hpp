/*****************************************************************************
*You should be able to use each of your headers independently from others.   *
*Thus, they must include all the dependencies they need.                     *
*However, you must avoid the problem of double inclusion by adding include guards.
*Otherwise, your grade will be 0.                                            *
*****************************************************************************/
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

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
		//
		//
	public:
		Bureaucrat ();
		Bureaucrat (const Bureaucrat &other);
		~Bureaucrat ();
		Bureaucrat & operator = (const Bureaucrat aother);
		// getters
		// function to increment
		// overload operator
};

// https://www.francescmm.com/orthodox-canonical-class-form/
// implement the class in canonical form
// CONSTRUCTOR
// DESTRUCTOR
// COPY COSTRUCTOR
//
#endif
