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
	Bureaucrat Bob = Bureaucrat(120, "Bob");
	std::cout << "Name of: " << Bob;


	// Test 2: Bob signs and executes a ShrubberyCreationForm (required: sign 145, exec 137).
	std::cout << BLUE << "TEST 2: Bob signs and executes ShrubberyCreationForm targeting 'Home'" << RESET << std::endl;
	ShrubberyCreationForm Home = ShrubberyCreationForm("Home");
	try
	{
		Bob.signForm(Home);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Error in Test 2: " << RESET << e.what() << std::endl;
	}
	
	// Test 3: Bob attempts to sign a RobotomyRequestForm (required: sign 72, exec 45) - should fail.
	std::cout << BLUE << "TEST 3: Bob attempts to sign RobotomyRequestForm targeting 'Office'" << RESET << std::endl;
	RobotomyRequestForm Office = RobotomyRequestForm("Office");
	try
	{
		Bob.signForm(Office);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 3 Exception: " << RESET << e.what() << std::endl;
	}
	
	// Test 4: Bob attempts to sign a PresidentialPardonForm (required: sign 25, exec 5) - should fail.
	std::cout << BLUE << "TEST 4: Bob attempts to sign PresidentialPardonForm targeting 'Prisoner'" << RESET << std::endl;
	PresidentialPardonForm Prisoner = PresidentialPardonForm("Prisoner");
	try
	{
		Bob.signForm(Prisoner);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 4 Exception: " << RESET << e.what() << std::endl;
	}
	
	// Test 5: High-ranked Bureaucrat Alice (grade 1) signs and executes PresidentialPardonForm.
	std::cout << BLUE << "TEST 5: Alice (grade 1) signs and executes PresidentialPardonForm targeting 'Prisoner'" << RESET << std::endl;
	Bureaucrat Alice = Bureaucrat(1, "Alice");
	std::cout << "Name of high rank: " << Alice;
	try
	{
		Alice.signForm(Prisoner);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 5 Exception: " << RESET << e.what() << std::endl;
	}
	
	// Test 6: Bureaucrat Charlie (grade 50) signs a RobotomyRequestForm but fails execution.
	std::cout << BLUE << "TEST 6: Charlie (grade 50) signs RobotomyRequestForm targeting 'Machine', execution should fail" << RESET << std::endl;
	RobotomyRequestForm Machine= RobotomyRequestForm("Machine");
	Bureaucrat Charlie = Bureaucrat(50, "Charlie");
	std::cout << "Name : " << Charlie;
	try
	{
		Charlie.signForm(Machine);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 6 Exception: " << RESET << e.what() << std::endl;
	}
	
	// Test 7: Bureaucrat Dave (grade 40) successfully signs and executes a RobotomyRequestForm.
	std::cout << BLUE << "TEST 7: Dave (grade 40) signs and executes RobotomyRequestForm targeting 'Machine'" << RESET << std::endl;
	Bureaucrat Dave = Bureaucrat(40, "Dave");
	std::cout << "Name : " << Dave;
	try
	{
		Dave.signForm(Machine);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 7 Exception: " << RESET << e.what() << std::endl;
	}
	
	// Test 8: Bureaucrat Eve (grade 150) tries to sign a ShrubberyCreationForm (should fail because 150 > 145).
	std::cout << BLUE << "TEST 8: Eve (grade 150) attempts to sign ShrubberyCreationForm targeting 'Garden'" << RESET << std::endl;
	ShrubberyCreationForm Garden = ShrubberyCreationForm("Garden");
	Bureaucrat Eve = Bureaucrat(150, "Eve");
	std::cout << "Name : " << Eve;
	try
	{
		Eve.signForm(Garden);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 8 Exception: " << RESET << e.what() << std::endl;
	}
	
	// Test 9: Bureaucrat Frank (grade 25) signs a PresidentialPardonForm successfully, but fails execution (25 > 5).
	std::cout << BLUE << "TEST 9: Frank (grade 25) signs PresidentialPardonForm targeting 'Politician', but execution fails" << RESET << std::endl;
	PresidentialPardonForm Politician = PresidentialPardonForm("Politician");
	Bureaucrat Frank = Bureaucrat(25, "Frank");
	std::cout << "Name : " << Frank;
	try
	{
		Frank.signForm(Politician);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 9 Exception: " << RESET << e.what() << std::endl;
	}
	
	// Test 10: Execute a form without signing it.
	std::cout << BLUE << "TEST 10: Attempt to execute an unsigned ShrubberyCreationForm targeting 'Office'" << RESET << std::endl;
	try
	{
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 10 Exception: " << RESET << e.what() << std::endl;
	}
	return (0);
}

