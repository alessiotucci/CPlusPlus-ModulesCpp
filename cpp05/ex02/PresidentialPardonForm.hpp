#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	// 1. PresidentialPardonForm constructor
	// TODO:All of them take only one parameter in their constructor: the target of the form.
	PresidentialPardonForm(std::string &target);
	// 2. Copy constructor
	PresidentialPardonForm(const PresidentialPardonForm& other);
	// 3. Copy assignment operator
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	// 4. Destructor
	virtual ~PresidentialPardonForm();
	// No member variables or additional methods
	virtual void execute(Bureaucrat const & executor) const;

};
#endif


