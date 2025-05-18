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

//1) 
static bool looksLikeChar(const std::string string)
{
	if (string.length() == 1 && isalnum(string[0]))
		return (true);
	return (false);
}

static char handleChar(const std::string str)
{
	return (str[0]);
}

static bool looksLikeInt(const std::string string) { (void)string; return true; }
static void handleInt(const std::string str) { (void)str; return; }

static bool looksLikeFloat(const std::string string) { (void)string; return true; }
static void handleFloat(const std::string str) { (void)str; return; }

static bool looksLikeDouble(const std::string string) { (void)string; return true; }
static void handleDouble(const std::string str) { (void)str; return; }

void ScalarConverter::convert(const std::string& param)
{
	char set_char = 'a';
	int set_int = 0;
	float set_float = 0.0f;
	double set_double = 0.0;

	if (looksLikeChar(param))
		set_char = handleChar(param);
	else if (looksLikeInt(param))
		handleInt(param);
	else if (looksLikeFloat(param))
		handleFloat(param);
	else if (looksLikeDouble(param))
		handleDouble(param);
/*	else if (isPseudoLiteral(param))
		handlePseudo(param);*/
	displayResult(set_char, set_int, set_float, set_double); // pass the conversion to this function
}


