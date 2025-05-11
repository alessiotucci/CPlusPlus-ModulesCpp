// main.cpp
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    using std::cout;
    using std::endl;

    // --- EXISTING TESTS FOR BUREAUCRAT & FORMS ---
    cout << BLUE << "=== TEST 1: Create Bureaucrat Bob (grade 120) ===" << RESET << endl;
    Bureaucrat bob(120, "Bob");
    cout << bob << endl;

    cout << BLUE << "=== TEST 2: Bob signs & executes ShrubberyCreationForm ===" << RESET << endl;
    ShrubberyCreationForm shrub("Home");
    cout << shrub << endl;
    try { bob.signForm(shrub); } 
    catch (std::exception &e) { cout << RED << e.what() << RESET << endl; }
    try { shrub.execute(bob); }
    catch (std::exception &e) { cout << RED << e.what() << RESET << endl; }

    cout << BLUE << "=== TEST 3: Bob fails to sign RobotomyRequestForm ===" << RESET << endl;
    RobotomyRequestForm robot("Office");
    cout << robot << endl;
    try { bob.signForm(robot); }
    catch (std::exception &e) { cout << RED << e.what() << RESET << endl; }
    try { robot.execute(bob); }
    catch (std::exception &e) { cout << RED << e.what() << RESET << endl; }

    cout << BLUE << "=== TEST 4: Alice (grade 1) signs & executes PresidentialPardonForm ===" << RESET << endl;
    Bureaucrat alice(1, "Alice");
    PresidentialPardonForm pardon("Prisoner");
    cout << pardon << endl;
    try { alice.signForm(pardon); }
    catch (std::exception &e) { cout << RED << e.what() << RESET << endl; }
    try { pardon.execute(alice); }
    catch (std::exception &e) { cout << RED << e.what() << RESET << endl; }

    // --- NEW TESTS FOR INTERN ---
    cout << BLUE << "\n=== INTERN TESTS ===" << RESET << endl;
    Intern someRandomIntern;

    // Test 5: Valid creation via Intern
    cout << BLUE << "TEST 5: Intern creates ShrubberyCreationForm for 'Garden'" << RESET << endl;
    try {
        AForm *f1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
        cout << *f1;
        delete f1;
    }
    catch (std::exception &e) {
        cout << RED << e.what() << RESET << endl;
    }

    // Test 6: Valid creation via Intern
    cout << BLUE << "TEST 6: Intern creates RobotomyRequestForm for 'Bender'" << RESET << endl;
    try {
        AForm *f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        cout << *f2;
        delete f2;
    }
    catch (std::exception &e) {
        cout << RED << e.what() << RESET << endl;
    }

    // Test 7: Valid creation via Intern
    cout << BLUE << "TEST 7: Intern creates PresidentialPardonForm for 'Zaphod'" << RESET << endl;
    try {
        AForm *f3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
        cout << *f3;
        delete f3;
    }
    catch (std::exception &e) {
        cout << RED << e.what() << RESET << endl;
    }

    // Test 8: Invalid form name
    cout << BLUE << "TEST 8: Intern attempts to create 'unknown form'" << RESET << endl;
    try {
        AForm *f4 = someRandomIntern.makeForm("unknown form", "Nobody");
        delete f4;
    }
    catch (std::exception &e) {
        cout << RED << "Caught: " << e.what() << RESET << endl;
    }

    // Test 9: Use Intern-created form and have Bob sign & execute it
    cout << BLUE << "TEST 9: Bob signs & executes form created by Intern" << RESET << endl;
    try {
        AForm *f5 = someRandomIntern.makeForm("shrubbery creation", "Park");
        cout << *f5;
        bob.signForm(*f5);
        f5->execute(bob);
        delete f5;
    }
    catch (std::exception &e) {
        cout << RED << e.what() << RESET << endl;
    }

    // Test 10: Multiple form requests in one go
    cout << BLUE << "TEST 10: Intern creates all three forms in an array" << RESET << endl;
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
            cout << RED << e.what() << RESET << endl;
        }
    }
    // Clean up
    for (int i = 0; i < 3; ++i)
        delete forms[i];

    return 0;
}

