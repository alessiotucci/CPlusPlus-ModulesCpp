/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/19 15:16:53 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/23 16:16:26                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <vector>
#include <list>

int main()
{
	std::cout << GREEN << "SPAN: let's start testing span" << RESET << std::endl;

	/* TEST1: Empty Span */
	std::cout << std::endl;
	std::cout << YELLOW << "TEST1: " << RESET << "testing with empty span" << std::endl;
	try
	{
		Span s1(5);
		std::cout << "Calling shortestSpan on empty Span...\n";
		std::cout << "Shortest span: " << s1.shortestSpan() << std::endl; // should throw
	} catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	/* TEST2: Add more than capacity */
	std::cout << YELLOW << "TEST2: " << RESET << "testing by adding more than capacity" << std::endl;
	try
	{
		Span s2(2);
		s2.addNumber(3);
		s2.addNumber(5);
		std::cout << "Trying to add a third number...\n";
		s2.addNumber(9); // should throw
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	/* TEST3: Add vector with addRange */
	std::cout << YELLOW << "TEST3: " << RESET << "testing with a vector of int" << std::endl;
	try
	{
		Span s3(5);
		std::vector<int> v;//= {10, 20, 30};
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		s3.addRange(v.begin(), v.end());
		s3.addNumber(5);
		s3.addNumber(40);
		std::cout << s3;
		std::cout << "Shortest span: " << s3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << s3.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	/* TEST4: Add C-style array */
	std::cout << YELLOW << "TEST4: " << RESET << "testing with a C-style array" << std::endl;
	try
	{
		Span s4(4);
		int arr[] = {100, 200, 300, 150};
		s4.addRange(arr, arr + 4);
		std::cout << s4;
		std::cout << "Shortest span: " << s4.shortestSpan() << std::endl;
		std::cout << "Longest span: " << s4.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	/* TEST5: Add list */
	std::cout << YELLOW << "TEST5: " << RESET << "testing with a list of int" << std::endl;
	try {
		Span s5(6);
		std::list<int> l;// = {42, 0, 21, -7, 14, 100};
		l.push_back(42);
		l.push_back(0);
		l.push_back(21);
		l.push_back(-7);
		l.push_back(14);
		l.push_back(100);
		s5.addRange(l.begin(), l.end());
		std::cout << s5;
		std::cout << "Shortest span: " << s5.shortestSpan() << std::endl;
		std::cout << "Longest span: " << s5.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	/* TEST6: Large amount of numbers */
	std::cout << YELLOW << "TEST6: " << RESET << "testing with a lot of spans" << std::endl;
	try {
		Span s6(10000);
		for (int i = 0; i < 10000; ++i)
			s6.addNumber(i);
	//	TODO:std::cout << s6;
		std::cout << "Shortest span: " << s6.shortestSpan() << std::endl;
		std::cout << "Longest span: " << s6.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	/* TEST7: Only one number in Span */
	std::cout << YELLOW << "TEST7: " << RESET << "testing with only one number" << std::endl;
	try {
		Span s7(2);
		s7.addNumber(42);
		std::cout << "Shortest span: " << s7.shortestSpan() << std::endl; // should throw
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "SPAN: all tests done" << RESET << std::endl;
	return 0;
}

