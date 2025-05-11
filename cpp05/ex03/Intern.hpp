#ifndef DEFAULT_HPP
# define DEFAULT_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
public:
	// 1. Intern constructor
	Intern();
	// 2. Copy constructor
	Intern(const Intern& other);
	// 3. Copy assignment operator
	Intern& operator=(const Intern& other);
	// 4. Destructor
	~Intern();

// the makeForm() function. It takes two strings.
// The first one is the name of a form and the second one is the target of the form.
// It return a pointer to a Form object (whose name is the one passed as parameter) whose target will be initialized to the second parameter.
	AForm* makeForm(std::string nameForm, std::string target);

//If the form name passed as parameter doesn’t exist, print an explicit error message.
	class	NonExistentRequestException: public std::exception
	{
		virtual const char	*what() const throw()
		{
			return ("try other type of form");
		}
	};
};
#endif


