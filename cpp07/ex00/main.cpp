/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/13 13:35:28 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/13 15:16:56                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
	std::cout << "\033[1;33m" << "===== TEST with int"" =====" << "\033[0m" << std::endl;
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << "\033[1;33m" << "===== TEST with double"" =====" << "\033[0m" << std::endl;
	double c = 2.1;
	double d = 3.5;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << "\033[1;33m" << "===== TEST with float"" =====" << "\033[0m" << std::endl;
	float e = 2.5f;
	float f = 7.2f;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

	std::cout << "\033[1;33m" << "===== TEST with strings"" =====" << "\033[0m" << std::endl;
	std::string cha = "chaine1";
	std::string dha = "chaine2";
	::swap(cha, dha);
	std::cout << "cha = " << cha << ", dha = " << dha << std::endl;
	std::cout << "min(cha, dha) = " << ::min(cha, dha) << std::endl;
	std::cout << "max(cha, dha) = " << ::max(cha, dha) << std::endl;

	return 0;
}

