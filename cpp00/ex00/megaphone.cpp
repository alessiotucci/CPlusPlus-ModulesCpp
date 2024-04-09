#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;
void	no_args(void)
{
	cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

void	make_upper(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i] != 0)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			cout << (char)toupper(av[i][j]);
			j++;
		}
	i++;
	}
}
int	main(int ac, char **av)
{
	(ac == 1) ? no_args() : make_upper(av);
	cout << endl;
	return 0;
}
