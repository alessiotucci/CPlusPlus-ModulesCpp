#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

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
// Informs that <target> has been pardoned by Zaphod Beeblebrox.
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	// perform the checks
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox\n";
	return ;
}
