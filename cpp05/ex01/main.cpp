#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << BLUE << "======== Test 1: Default Bureaucrat ========" << RESET << std::endl;
	Bureaucrat defaultBureaucrat;
	std::cout << defaultBureaucrat << std::endl;

	std::cout << BLUE << "======== Test 2: Parameterized Bureaucrat (valid) ========" << RESET << std::endl;
	try
	{
		Bureaucrat alice(50, "Alice");
		std::cout << alice << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "======== Test 3: Bureaucrat with grade too high (invalid: grade < 1) ========" << RESET << std::endl;
	try
	{
		Bureaucrat bob(0, "Bob");
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "======== Test 4: Bureaucrat with grade too low (invalid: grade > 150) ========" << RESET << std::endl;
	try
	{
		Bureaucrat charlie(151, "Charlie");
		std::cout << charlie << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "======== Test 5: Increment/Decrement Grade ========" << RESET << std::endl;
	try
	{
		Bureaucrat dave(2, "Dave");
		std::cout << dave << std::endl;
		std::cout << YELLOW << "Incrementing grade for Dave..." << RESET << std::endl;
		dave.IncrementGrade(); // Should succeed: grade goes from 2 to 1.
		std::cout << GREEN << "After increment: " << RESET << dave;
		std::cout << YELLOW << "Attempting to increment beyond limit (should throw)..." << RESET << std::endl;
		dave.IncrementGrade(); // Should throw exception: cannot go beyond grade 1.
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught during increment: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "======== Test 6: Create a Valid Form ========" << RESET << std::endl;
	try
	{
		Form taxForm(30, 40); // Valid grades
		std::cout << GREEN << "Created form:" << RESET << std::endl << taxForm;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught while creating form: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "======== Test 7: Create an Invalid Form (grade to sign < 1) ========" << RESET << std::endl;
	try
	{
		Form invalidForm(0, 40); // Invalid: grade to sign < 1
		std::cout << invalidForm;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught while creating form: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "======== Test 8: Successful Form Signing ========" << RESET << std::endl;
	try
	{
		Bureaucrat eric(10, "Eric");
		Form contract(20, 30); // Requires grade <= 20 to sign
		eric.signForm(contract);
		std::cout << GREEN << "Form after signing:" << RESET << std::endl << contract;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught during form signing: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "======== Test 9: Failed Form Signing ========" << RESET << std::endl;
	try
	{
		Bureaucrat frank(50, "Frank");
		Form permit(30, 40); // Requires grade <= 30 to sign; Frank's grade is 50.
		frank.signForm(permit);
		std::cout << permit;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught during form signing: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "======== Test 10: Bureaucrat Copy Constructor ========" << RESET << std::endl;
	try
	{
		Bureaucrat original(25, "Original");
		Bureaucrat copy = original;  // Copy constructor
		std::cout << "Original: " << original;
		std::cout << "Copy: " << copy;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught during copy construction: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "======== Test 11: Bureaucrat Copy Assignment ========" << RESET << std::endl;
	try
	{
		Bureaucrat first(40, "First");
		Bureaucrat second(10, "Second");
		std::cout << "Before assignment:" << std::endl;
		std::cout << "First: " << first;
		std::cout << "Second: " << second;
		first = second; // Copy assignment operator
		std::cout << GREEN << "After assignment:" << RESET << std::endl;
		std::cout << "First: " << first;
		std::cout << "Second: " << second;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught during copy assignment: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "======== Test 12: Insertion Operator Overload for Form ========" << RESET << std::endl;
	try
	{
		Form invitation(5, 10);
		std::cout << invitation;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught during printing: " << e.what() << RESET << std::endl;
	}

	return 0;
}

