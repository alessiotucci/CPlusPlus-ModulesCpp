#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	// Test 1: Create a Bureaucrat Bob with grade 120 and print him.
	std::cout << BLUE << "TEST 1: Create Bureaucrat Bob (grade 120)" << RESET << std::endl;
	// Test 2: Bob signs and executes a ShrubberyCreationForm (required: sign 145, exec 137).
	std::cout << BLUE << "TEST 2: Bob signs and executes ShrubberyCreationForm targeting 'Home'" << RESET << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Error in Test 2: " << e.what() << RESET << std::endl;
	}
	
	// Test 3: Bob attempts to sign a RobotomyRequestForm (required: sign 72, exec 45) - should fail.
	std::cout << BLUE << "TEST 3: Bob attempts to sign RobotomyRequestForm targeting 'Office'" << RESET << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 3 Exception: " << e.what() << RESET << std::endl;
	}
	
	// Test 4: Bob attempts to sign a PresidentialPardonForm (required: sign 25, exec 5) - should fail.
	std::cout << BLUE << "TEST 4: Bob attempts to sign PresidentialPardonForm targeting 'Prisoner'" << RESET << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 4 Exception: " << e.what() << RESET << std::endl;
	}
	
	// Test 5: High-ranked Bureaucrat Alice (grade 1) signs and executes PresidentialPardonForm.
	std::cout << BLUE << "TEST 5: Alice (grade 1) signs and executes PresidentialPardonForm targeting 'Prisoner'" << RESET << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 5 Exception: " << e.what() << RESET << std::endl;
	}
	
	// Test 6: Bureaucrat Charlie (grade 50) signs a RobotomyRequestForm but fails execution.
	std::cout << BLUE << "TEST 6: Charlie (grade 50) signs RobotomyRequestForm targeting 'Machine', execution should fail" << RESET << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 6 Exception: " << e.what() << RESET << std::endl;
	}
	
	// Test 7: Bureaucrat Dave (grade 40) successfully signs and executes a RobotomyRequestForm.
	std::cout << BLUE << "TEST 7: Dave (grade 40) signs and executes RobotomyRequestForm targeting 'Machine'" << RESET << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 7 Exception: " << e.what() << RESET << std::endl;
	}
	
	// Test 8: Bureaucrat Eve (grade 150) tries to sign a ShrubberyCreationForm (should fail because 150 > 145).
	std::cout << BLUE << "TEST 8: Eve (grade 150) attempts to sign ShrubberyCreationForm targeting 'Garden'" << RESET << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 8 Exception: " << e.what() << RESET << std::endl;
	}
	
	// Test 9: Bureaucrat Frank (grade 25) signs a PresidentialPardonForm successfully, but fails execution (25 > 5).
	std::cout << BLUE << "TEST 9: Frank (grade 25) signs PresidentialPardonForm targeting 'Politician', but execution fails" << RESET << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 9 Exception: " << e.what() << RESET << std::endl;
	}
	
	// Test 10: Execute a form without signing it.
	std::cout << BLUE << "TEST 10: Attempt to execute an unsigned ShrubberyCreationForm targeting 'Office'" << RESET << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 10 Exception: " << e.what() << RESET << std::endl;
	}
	
	return 0;
}

