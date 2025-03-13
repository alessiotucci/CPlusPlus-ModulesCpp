#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat test1 = Bureaucrat();
	std::cout << "test1 " << test1 << std::endl;

	for (int i = 0; i < 120; i++)
	{
		std::cout << test1 << std::endl;
		std::cout << "Incrementing the grade ";
		test1.IncrementGrade();
	}
	return (0);
}
