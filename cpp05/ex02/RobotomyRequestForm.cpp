#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>
#include <cstdlib>

//1) Constructor: Calls the base class constructor with the formś name and
//required grades
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

//TODO: implement this function
// Makes some drilling noises.
// Then, informs that <target> has been robotomized successfully 50% of the time.
// Otherwise, informs that the robotomy failed.
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << "!!DRILL NOISES!!" << std::endl;
	// perform the checks
	srand(time(NULL));
	if (rand() & 1) // Check least significant bit
		std::cout << "[" << _target << "] has been robotomized successfully!\n";
	else
		std::cout << "[" << _target << "] has NOT been robotomized ";
	return ;
}
