#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    // Test 1: Valid constructions
    std::cout << BLUE << "\n==== TEST 1: Valid Constructions ====\n" << RESET;
    try {
        std::cout << CYAN << "Creating Alice (grade 1)" << RESET << std::endl;
        Bureaucrat b1(1, "Alice");
        std::cout << "CREATED: " << b1 << std::endl;

        std::cout << CYAN << "\nCreating Bob (grade 75)" << RESET << std::endl;
        Bureaucrat b2(75, "Bob");
        std::cout << "CREATED: " << b2 << std::endl;

        std::cout << CYAN << "\nCreating Charlie (grade 150)" << RESET << std::endl;
        Bureaucrat b3(150, "Charlie");
        std::cout << "CREATED: " << b3 << std::endl;

        std::cout << GREEN << "\n✓ All valid bureaucrats created" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ FAIL: " << e.what() << RESET << std::endl;
    }

    // Test 2: Invalid constructions
    std::cout << BLUE << "\n==== TEST 2: Invalid Constructions ====\n" << RESET;
    try {
        std::cout << CYAN << "Attempting grade 0 (too high):" << RESET << std::endl;
        Bureaucrat b0(0, "TooHigh");
        std::cout << RED << "✗ Unexpectedly created: " << b0 << RESET << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << GREEN << "✓ CAUGHT: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << CYAN << "\nAttempting grade 151 (too low):" << RESET << std::endl;
        Bureaucrat b151(151, "TooLow");
        std::cout << RED << "✗ Unexpectedly created: " << b151 << RESET << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << GREEN << "✓ CAUGHT: " << e.what() << RESET << std::endl;
    }

    // Test 3: Normal increment
    std::cout << BLUE << "\n==== TEST 3: Valid Increment ====\n" << RESET;
    try {
        Bureaucrat b(2, "Promotable");
        std::cout << "INITIAL STATE: " << b << std::endl;
        
        b.IncrementGrade();
        std::cout << CYAN << "After increment: " << b << RESET << std::endl;
        
        std::cout << GREEN << "✓ Increment successful" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ FAIL: " << e.what() << RESET << std::endl;
    }

    // Test 4: Increment overflow
    std::cout << BLUE << "\n==== TEST 4: Increment Overflow ====\n" << RESET;
    try {
        Bureaucrat b(1, "TopGrade");
        std::cout << "INITIAL STATE: " << b << std::endl;
        std::cout << "Attempting increment..." << std::endl;
        
        b.IncrementGrade();
        std::cout << RED << "✗ Unexpected success: " << b << RESET << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << GREEN << "✓ CAUGHT: " << e.what() << RESET << std::endl;
        std::cout << CYAN << "Expected outcome - object destroyed after exception" << RESET << std::endl;
    }

    // Test 5: Normal decrement
    std::cout << BLUE << "\n==== TEST 5: Valid Decrement ====\n" << RESET;
    try {
        Bureaucrat b(149, "Demotable");
        std::cout << "INITIAL STATE: " << b << std::endl;
        
        b.DecrementGrade();
        std::cout << CYAN << "After decrement: " << b << RESET << std::endl;
        
        std::cout << GREEN << "✓ Decrement successful" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ FAIL: " << e.what() << RESET << std::endl;
    }

    // Test 6: Decrement overflow
    std::cout << BLUE << "\n==== TEST 6: Decrement Overflow ====\n" << RESET;
    try {
        Bureaucrat b(150, "LowestGrade");
        std::cout << "INITIAL STATE: " << b << std::endl;
        std::cout << "Attempting decrement..." << std::endl;
        
        b.DecrementGrade();
        std::cout << RED << "✗ Unexpected success: " << b << RESET << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << GREEN << "✓ CAUGHT: " << e.what() << RESET << std::endl;
        std::cout << CYAN << "Expected outcome - object destroyed after exception" << RESET << std::endl;
    }

    // Test 7: Getters
    std::cout << BLUE << "\n==== TEST 7: Getters Validation ====\n" << RESET;
    try {
        Bureaucrat b(42, "GetterTest");
        std::cout << "TEST OBJECT: " << b << std::endl;
        
        if (b.getName() == "GetterTest" && b.getGrade() == 42) {
            std::cout << GREEN << "✓ Getters work correctly" << RESET << std::endl;
        } else {
            std::cout << RED << "✗ Getter mismatch:" 
                     << "\n  Name: " << b.getName()
                     << "\n  Grade: " << b.getGrade() << RESET << std::endl;
        }
    } catch (...) {
        std::cout << RED << "✗ Unexpected error" << RESET << std::endl;
    }

    // Test 8: Output operator
    std::cout << BLUE << "\n==== TEST 8: Output Formatting ====\n" << RESET;
    try {
        Bureaucrat b(99, "Formatted");
        std::cout << YELLOW << "EXPECTED FORMAT: Formatted, bureaucrat grade 99" << RESET << std::endl;
        std::cout << "ACTUAL OUTPUT:   " << b << std::endl;
    } catch (...) {
        std::cout << RED << "✗ Output test failed" << RESET << std::endl;
    }

    // Test 9: Copy constructor
    std::cout << BLUE << "\n==== TEST 9: Copy Construction ====\n" << RESET;
    try {
        Bureaucrat original(50, "Original");
        std::cout << "ORIGINAL: " << original << std::endl;
        
        Bureaucrat copy(original);
        std::cout << "COPY:      " << copy << std::endl;
        
        if (copy.getGrade() == original.getGrade()) {
            std::cout << GREEN << "✓ Copy matches original" << RESET << std::endl;
        } else {
            std::cout << RED << "✗ Copy mismatch:" 
                     << "\n  Original: " << original.getGrade()
                     << "\n  Copy:     " << copy.getGrade() << RESET << std::endl;
        }
    } catch (...) {
        std::cout << RED << "✗ Copy failed" << RESET << std::endl;
    }

    // Test 10: Assignment operator
    std::cout << BLUE << "\n==== TEST 10: Assignment Operator ====\n" << RESET;
    try {
        Bureaucrat source(10, "Source");
        Bureaucrat target(20, "Target");
        
        std::cout << "BEFORE ASSIGNMENT:\n"
                  << "  Source: " << source << "\n"
                  << "  Target: " << target << std::endl;
        
        target = source;
        std::cout << "AFTER ASSIGNMENT:\n"
                  << "  Source: " << source << "\n"
                  << "  Target: " << target << std::endl;
        
        if (target.getGrade() == source.getGrade()) {
            std::cout << GREEN << "✓ Assignment successful" << RESET << std::endl;
        } else {
            std::cout << RED << "✗ Assignment failed:" 
                     << "\n  Source: " << source.getGrade()
                     << "\n  Target: " << target.getGrade() << RESET << std::endl;
        }
    } catch (...) {
        std::cout << RED << "✗ Assignment error" << RESET << std::endl;
    }

    return 0;
}
