/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/19 15:17:46 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/24 12:18:37                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <string> // For std::string

int main()
{
    // 1. Create a stack of strings
     std::cout << YELLOW << "1. Create a stack of strings" << RESET << std::endl;
    std::stack<std::string> messages;
    // 2. Push elements onto the stack
    messages.push("First message");
    messages.push("Second message");
    messages.push("Third message");

    // 3. Check if the stack is empty
    if (!messages.empty())
	{
        std::cout << "Stack is not empty." << std::endl;
    }

    // 4. Get the size of the stack
    std::cout << "Stack size: " << messages.size() << std::endl;

    // 5. Access and process elements from the top
    std::cout << "Processing stack elements:" << std::endl;
    while (!messages.empty())
	{
        std::cout << "  Top element: " << messages.top() << std::endl;
        messages.pop(); // Remove the top element
    }

    // 6. Check if the stack is empty again
    if (messages.empty())
	{
        std::cout << "Stack is now empty." << std::endl;
    }
	std::cout << RED << "trying to iterate over a standard stack"<< RESET << std::endl;
/*TODO:
	stack<int>::iterator start = messages.begin();
	stack<int>::iterator end = messages.end();
	while (start != end)
	{
	std::cout << *it << std::endl;
	start++;
	}*/
    std::cout << GREEN << "\n\n1. Create a MutantStack of strings" << RESET << std::endl;
    MutantStack<std::string> mutant;
    // 2. Push elements onto the MutantStack
    mutant.push("First message");
    mutant.push("Second message");
    mutant.push("Third message");

    // 3. Check if the MutantStack is empty
    if (!mutant.empty())
	{
        std::cout << "Stack is not empty." << std::endl;
    }

    // 4. Get the size of the MutantStack
    std::cout << "Stack size: " << mutant.size() << std::endl;

    // 5. Access and process elements from the top
    std::cout << "Processing MutantStack elements:" << std::endl;
    while (!mutant.empty())
	{
        std::cout << "  Top element: " << mutant.top() << std::endl;
        mutant.pop(); // Remove the top element
    }

    // 6. Check if the MutantStack is empty again
    if (mutant.empty())
	{
        std::cout << "Stack is now empty." << std::endl;
    }
	std::cout << GREEN << "Iterate over a standard stack"<< RESET << std::endl;
	//TODO:
	MutantStack<int> m;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			m.push((i * 3) % 7);
		else
			m.push((i * 7) % 3);
	}
	
	MutantStack<int>::iterator start = m.begin();
	MutantStack<int>::iterator end = m.end();
	while (start != end)
	{
	std::cout << *start << std::endl;
	start++;
	}

    // Demonstrating copy constructor and assignment operator
    std::stack<int> s1;
    s1.push(100);
    s1.push(200);

    std::stack<int> s2 = s1; // Copy constructor
    std::cout << "s2 top: " << s2.top() << std::endl; // Output: s2 top: 200

    std::stack<int> s3;
    s3 = s1; // Assignment operator
    std::cout << "s3 top: " << s3.top() << std::endl; // Output: s3 top: 200

    return 0;
}
