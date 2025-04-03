#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm(std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

//TODO: implement the execute function
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	// perform the checks
	(void)executor;
	return ;
}
