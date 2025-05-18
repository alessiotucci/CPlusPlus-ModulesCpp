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

static void displayResult(char a, int b, float c, double d)
{
	std::cout << "char: " << a << std::endl;
	std::cout << "int: " << b << std::endl;
	std::cout << "float: " << c << std::endl;
	std::cout << "double: " << d << std::endl;
}
static bool looksLikeChar(const std::string string) { (void)string; return true; }
static void handleChar(const std::string str) { (void)str; return; }

static bool looksLikeInt(const std::string string) { (void)string; return true; }
static void handleInt(const std::string str) { (void)str; return; }

static bool looksLikeFloat(const std::string string) { (void)string; return true; }
static void handleFloat(const std::string str) { (void)str; return; }

static bool looksLikeDouble(const std::string string) { (void)string; return true; }
static void handleDouble(const std::string str) { (void)str; return; }

void ScalarConverter::convert(const std::string& param)
{
	if (looksLikeChar(param))
		handleChar(param);
	else if (looksLikeInt(param))
		handleInt(param);
	else if (looksLikeFloat(param))
		handleFloat(param);
	else if (looksLikeDouble(param))
		handleDouble(param);
/*	else if (isPseudoLiteral(param))
		handlePseudo(param);*/
	displayResult('a', 0, 0.0f, 0.0); // pass the conversion to this function
}


