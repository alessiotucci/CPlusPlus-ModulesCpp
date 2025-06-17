/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/13 13:35:48 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/17 14:45:51                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::cout << "TEST1: Array of int\n";
	int arrayInt[4] = {1, 2, 3, 4};
	for (int i = 0; i < 4; i++)
	{
		std::cout << "array[" << i << "] " << arrayInt[i] << std::endl;
	}

	std::cout << "TEST2: Array of double\n";
	double arrayDouble[4] = {1.1, 2.2, 3.3, 4.4};
	for (int i = 0; i < 4; i++)
	{
		std::cout << "array[" << i << "] " << arrayDouble[i] << std::endl;
	}

	std::cout << "TEST3: Array of float\n";
	float arrayFloat[4] = {1.1f, 2.2f, 3.3f, 4.4f};
	for (int i = 0; i < 4; i++)
	{
		std::cout << "array[" << i << "] " << arrayFloat[i] << std::endl;
	}

	std::cout << "TEST4: Array of char\n";
	char arrayChar[4] = { 'a', 'b', 'c', 'd'};
	for (int i = 0; i < 4; i++)
	{
		std::cout << "array[" << i << "] " << arrayChar[i] << std::endl;
	}

	std::cout << "TEST5: Array of string\n";
	std::string arrayString[4] = {"ciao", "come", "va", "ehy?"};
	for (int i = 0; i < 4; i++)
	{
		std::cout << "array[" << i << "] " << arrayString[i] << std::endl;
	}

	return(0);
}
