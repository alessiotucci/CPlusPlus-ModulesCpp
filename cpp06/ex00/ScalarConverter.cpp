#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }
ScalarConverter::~ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}
ScalarConverter& ScalarConverter::operator=( const ScalarConverter& src)
{
	(void)src;
	//if (this != &src)
	//{
	//
	//}
	return (*this);
}

void ScalarConverter::convert(const std::string& param)
{
	std::cout << "[" << param << "]\n" ;
	std::cout << "convert function called!\n";
}


