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
	std::cout << BLUE << "TEST 2: Bob signs ShrubberyCreationForm targeting 'Home'" << RESET << std::endl;
	ShrubberyCreationForm Home = ShrubberyCreationForm("Home");
	std::cout << "---\n" << Home << "---\n";
	try
	{
		Bob.signForm(Home);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Error in Test 2: " << RESET << e.what() << std::endl;
	}

	std::cout << YELLOW << "TEST 2.1: Bob execute ShrubberyCreationForm targeting 'Home' --> creating a ascii three" << RESET << std::endl;
	try
	{
		Bob.executeForm(Home);
		//Home.execute(Bob);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Error in Test 2: " << RESET << e.what() << std::endl;
	}
	// Test 3: Bob attempts to sign a RobotomyRequestForm (required: sign 72, exec 45) - should fail.
	std::cout << BLUE << "TEST 3: Bob attempts to sign RobotomyRequestForm targeting 'Office'" << RESET << std::endl;
	RobotomyRequestForm Office = RobotomyRequestForm("Office");
	std::cout << "---\n" << Office << "---\n";
	try
	{
		Bob.signForm(Office);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 3 Exception: " << RESET << e.what() << std::endl;
	}
	std::cout << YELLOW << "TEST 3.1: Bob attempts to exec RobotomyRequestForm targeting 'Office'" << RESET << std::endl;
	try
	{
		Bob.executeForm(Office);
		//Office.execute(Bob);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 3 Exception: " << RESET << e.what() << std::endl;
	}
	// Test 4: Bob attempts to sign a PresidentialPardonForm (required: sign 25, exec 5) - should fail.
	std::cout << BLUE << "TEST 4: Bob attempts to sign PresidentialPardonForm targeting 'Prisoner'" << RESET << std::endl;
	PresidentialPardonForm Prisoner = PresidentialPardonForm("Prisoner");
	std::cout << "---\n" << Prisoner << "---\n";
	try
	{
		Bob.signForm(Prisoner);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 4 Exception: " << RESET << e.what() << std::endl;
	}
	std::cout << YELLOW << "TEST 4.1: Bob attempts to exec PresidentialPardonForm targeting 'Prisoner'" << RESET << std::endl;
	try
	{
		Bob.executeForm(Prisoner);
		//Prisoner.execute(Bob);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 4 Exception: " << RESET << e.what() << std::endl;
	}
	// Test 5: High-ranked Bureaucrat Alice (grade 1) signs and executes PresidentialPardonForm.
	std::cout << BLUE << "TEST 5: Alice (grade 1) signs PresidentialPardonForm targeting 'Prisoner'" << RESET << std::endl;
	Bureaucrat Alice = Bureaucrat(1, "Alice");
	std::cout << "***\nName of high rank: " << Alice << "***\n";
	std::cout << "---\n" << Prisoner << "---\n";
	try
	{
		Alice.signForm(Prisoner);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 5 Exception: " << RESET << e.what() << std::endl;
	}
	std::cout << YELLOW << "TEST 5.1: Alice executes PresidentialPardonForm targeting 'Prisoner'" << RESET << std::endl;
	try
	{
		Alice.executeForm(Prisoner);
		//Prisoner.execute(Alice);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 5.1 Exception: " << RESET << e.what() << std::endl;
	}

	// Test 6: Bureaucrat Charlie (grade 50) signs a RobotomyRequestForm but fails execution.
	std::cout << BLUE << "TEST 6: Charlie (grade 50) signs RobotomyRequestForm targeting 'Machine'" << RESET << std::endl;
	RobotomyRequestForm Machine= RobotomyRequestForm("Machine");
	std::cout << "---\n" << Machine << "---\n";
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
	std::cout << YELLOW << "TEST 6.1: Charlie exec RobotomyRequestForm targeting 'Machine'" << RESET << std::endl;
	try
	{
		//Machine.execute(Charlie);
		Charlie.executeForm(Machine);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 6 Exception: " << RESET << e.what() << std::endl;
	}
	
	// Test 7: Bureaucrat Dave (grade 40) successfully signs and executes a RobotomyRequestForm.
	std::cout << BLUE << "TEST 7: Dave (grade 40) signs RobotomyRequestForm targeting 'Machine'" << RESET << std::endl;
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
	std::cout << YELLOW << "TEST 7.1: Dave executes RobotomyRequestForm targeting 'Machine'" << RESET << std::endl;
	try
	{
		//Machine.execute(Dave);
		Dave.executeForm(Machine);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 7 Exception: " << RESET << e.what() << std::endl;
	}

	// Test 8: Bureaucrat Eve (grade 150) tries to sign a ShrubberyCreationForm (should fail because 150 > 145).
	std::cout << BLUE << "TEST 8: Eve (grade 150) attempts to sign ShrubberyCreationForm targeting 'Garden'" << RESET << std::endl;
	ShrubberyCreationForm Garden = ShrubberyCreationForm("Garden");
	std::cout << "---\n" << Garden << "---\n";
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
	std::cout << YELLOW << "TEST 8.1: Eve exec ShrubberyCreationForm targeting 'Garden'" << RESET << std::endl;
	try
	{
		//Garden.execute(Eve);
		Eve.executeForm(Garden);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 8 Exception: " << RESET << e.what() << std::endl;
	}

	// Test 9: Bureaucrat Frank (grade 25) signs a PresidentialPardonForm successfully, but fails execution (25 > 5).
	std::cout << BLUE << "TEST 9: Frank (grade 25) signs PresidentialPardonForm targeting 'Politician', but execution fails" << RESET << std::endl;
	PresidentialPardonForm Politician = PresidentialPardonForm("Politician");
	std::cout << "---\n" << Politician << "---\n";
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
	std::cout << YELLOW << "TEST 9.1: Frank  exec PresidentialPardonForm targeting 'Politician'" << RESET << std::endl;
	try
	{
		//Politician.execute(Frank);
		Frank.executeForm(Politician);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Test 9 Exception: " << RESET << e.what() << std::endl;
	}
	return (0);
}

