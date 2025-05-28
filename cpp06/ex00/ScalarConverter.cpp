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
	return (*this);
}

static void displayResult(char c, int i, float f, double d)
{
	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	std::cout << "int: " << i << std::endl;

	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}


//1) 
static bool looksLikeChar(const std::string& str)
{
	return (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]));

}
static void handleChar(const std::string& str, char& c, int& i, float& f, double& d)
{
	c = str[0]; // this is the char
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
}

//2) --- IN
static bool looksLikeInt(const std::string string)
{
	if (string.empty())
		return (false);

	size_t i = 0;
	if (string[0] == '+' || string[0] == '-')
		i++;

	while (i < string.length())
	{
		if (std::isdigit(string[i]) == 0)
			return (false);
		i++;
	}
	return true;
}

static void handleInt(const std::string& str, char& c, int& i, float& f, double& d)
{
//	c = static_cast<int>(i);
	i = std::atoi(str.c_str()); // this is the int
	c = static_cast<int>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
}



//3) --- FLOAT
static bool looksLikeFloat(const std::string str)
{
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;

	size_t i = 0;
	bool dot_found = false;

	if (str.empty() || str[str.length() - 1] != 'f')
		return false;

	if (str[i] == '+' || str[i] == '-')
		++i;

	for (; i < str.length() - 1; ++i) // exclude final 'f'
	{
		if (str[i] == '.')
		{
			if (dot_found)
				return false;
			dot_found = true;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	return dot_found;
}
static void handleFloat(const std::string& str, char& c, int& i, float& f, double& d)
{
	f = static_cast<float>(std::atof(str.c_str())); // this is the float
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
}


//--- DOUBLE
static bool looksLikeDouble(const std::string str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;

	size_t i = 0;
	bool dot_found = false;

	if (str.empty())
		return false;

	if (str[i] == '+' || str[i] == '-')
		++i;

	for (; i < str.length(); ++i)
	{
		if (str[i] == '.')
		{
			if (dot_found)
				return false;
			dot_found = true;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}

	return dot_found;
}
static void handleDouble(const std::string& str, char& c, int& i, float& f, double& d)
{
	d = std::atof(str.c_str());// this is the double
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
}

void ScalarConverter::convert(const std::string& param)
{
	char set_char = 'a';
	int set_int = 0;
	float set_float = 0.0f;
	double set_double = 0.0;

	if (looksLikeChar(param))
		handleChar(param, set_char, set_int, set_float, set_double);
	else if (looksLikeInt(param))
		handleInt(param, set_char, set_int, set_float, set_double);
	else if (looksLikeFloat(param))
		handleFloat(param, set_char, set_int, set_float, set_double);
	else if (looksLikeDouble(param))
		handleDouble(param, set_char, set_int, set_float, set_double);
/*	else if (isPseudoLiteral(param))
		handlePseudo(param);*/
	displayResult(set_char, set_int, set_float, set_double); // pass the conversion to this function
}


