#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

private:
	std::string _target; // The target where the shrubbery will be created.
public:
	// Constructor: takes one parameter for the target.
	ShrubberyCreationForm(const std::string &target);
	// 2. Copy constructor
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	// 3. Copy assignment operator
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	// 4. virtual Destructor (it is a derived class from AForm)
	virtual ~ShrubberyCreationForm();
	// No member variables or additional methods

	//TODO: Now we can implement the pure virtual funcion in the concrete
	virtual void execute(Bureaucrat const & executor) const;

};
#endif


