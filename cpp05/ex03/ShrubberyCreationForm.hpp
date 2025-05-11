#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include <string>
#include "AForm.hpp"

// Define a macro for your big ASCII art.  Each line is a separate
// string literal, and the backslash at the end joins them into one.
#define BIG_TREE_ART \
"               ,@@@@@@@,                \n" \
"       ,,,.   ,@@@@@@/@@,  .oo8888o.    \n" \
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o  \n" \
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" \
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' \n" \
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'  \n" \
"   `&%\\ ` /%&'    |.|        \\ '|8'    \n" \
"       |o|        | |         | |       \n" \
"       |.|        | |         | |       \n" \
"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n"

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


