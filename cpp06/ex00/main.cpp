#include "ScalarConverter.hpp"
int main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
		return (0);
	}
	std::cout << RED << "ERROR: KO!\n" << RESET;
	std::cout << "provide an argument: example: ./converter 42\n";
	return (-1);
}
