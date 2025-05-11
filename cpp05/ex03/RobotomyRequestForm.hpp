#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	// some stuff to change here
private:
	std::string _target;
public:
	// 1. RobotomyRequestForm constructor
	// TODO:All of them take only one parameter in their constructor: the target of the form.
	RobotomyRequestForm(std::string target);
	// 2. Copy constructor
	RobotomyRequestForm(const RobotomyRequestForm& other);
	// 3. Copy assignment operator
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	// 4. virtual Destructor
	virtual ~RobotomyRequestForm();

	//TODO: implement this function in the concrete form
	virtual void execute(Bureaucrat const & executor) const;
};
#endif


