// main.cpp
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {

    // --- EXISTING TESTS FOR BUREAUCRAT & FORMS ---
    std::cout << BLUE << "=== TEST 1: Create Bureaucrat Bob (grade 120) ===" << RESET << std::endl;
    Bureaucrat bob(120, "Bob");
    std::cout << bob << std::endl;

    std::cout << BLUE << "=== TEST 2: Bob signs & executes ShrubberyCreationForm ===" << RESET << std::endl;
    ShrubberyCreationForm shrub("Home");
    std::cout << shrub << std::endl;
    try { bob.signForm(shrub); } 
    catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }
    try { shrub.execute(bob); }
    catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << BLUE << "=== TEST 3: Bob fails to sign RobotomyRequestForm ===" << RESET << std::endl;
    RobotomyRequestForm robot("Office");
    std::cout << robot << std::endl;
    try { bob.signForm(robot); }
    catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }
    try { robot.execute(bob); }
    catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << BLUE << "=== TEST 4: Alice (grade 1) signs & executes PresidentialPardonForm ===" << RESET << std::endl;
    Bureaucrat alice(1, "Alice");
    PresidentialPardonForm pardon("Prisoner");
    std::cout << pardon << std::endl;
    try { alice.signForm(pardon); }
    catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }
    try { pardon.execute(alice); }
    catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    // --- NEW TESTS FOR INTERN ---
    std::cout << BLUE << "\n=== INTERN TESTS ===" << RESET << std::endl;
    Intern someRandomIntern;

    // Test 5: Valid creation via Intern
    std::cout << BLUE << "TEST 5: Intern creates ShrubberyCreationForm for 'Garden'" << RESET << std::endl;
    try {
        AForm *f1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
        std::cout << *f1;
        delete f1;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    // Test 6: Valid creation via Intern
    std::cout << BLUE << "TEST 6: Intern creates RobotomyRequestForm for 'Bender'" << RESET << std::endl;
    try {
        AForm *f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *f2;
        delete f2;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    // Test 7: Valid creation via Intern
    std::cout << BLUE << "TEST 7: Intern creates PresidentialPardonForm for 'Zaphod'" << RESET << std::endl;
    try {
        AForm *f3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
        std::cout << *f3;
        delete f3;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    // Test 8: Invalid form name
    std::cout << BLUE << "TEST 8: Intern attempts to create 'unknown form'" << RESET << std::endl;
    try {
        AForm *f4 = someRandomIntern.makeForm("unknown form", "Nobody");
        delete f4;
    }
    catch (std::exception &e) {
        std::cout << RED << "Caught: " << e.what() << RESET << std::endl;
    }

    // Test 9: Use Intern-created form and have Bob sign & execute it
    std::cout << BLUE << "TEST 9: Bob signs & executes form created by Intern" << RESET << std::endl;
    try {
        AForm *f5 = someRandomIntern.makeForm("shrubbery creation", "Park");
        std::cout << *f5;
        bob.signForm(*f5);
        f5->execute(bob);
        delete f5;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    // Test 10: Multiple form requests in one go
    std::cout << BLUE << "TEST 10: Intern creates all three forms in an array" << RESET << std::endl;
    const char *names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    const char *targets[3] = { "Home", "Office", "Galaxy" };
    AForm *forms[3] = { 0, 0, 0 };

    for (int i = 0; i < 3; ++i) {
        try {
            forms[i] = someRandomIntern.makeForm(names[i], targets[i]);
        }
        catch (std::exception &e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    // Clean up
    for (int i = 0; i < 3; ++i)
        delete forms[i];

    return 0;
}

