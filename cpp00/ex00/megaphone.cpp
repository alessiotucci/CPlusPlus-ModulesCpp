#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

void	function_a(void)
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void	function_b(char **av)
{
	char text;
	for (int i = 1; av[i] != 0; i++)
	{
		for (int j = 0; av[i][j] != 0; j++)
		{
			text = av[i][j];
			std::cout << (char)std::toupper(text);
		}
	}
}

int	main(int ac, char **av)
{

//	std::string str = "Hello World";
//	std::cout << str << std::endl;
//	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
//	std::cout << str << std::endl;
	(ac == 1) ? function_a() : function_b(av);
	std::cout << std::endl;
	return 0;
}
