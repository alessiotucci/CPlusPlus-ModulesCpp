/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: RPN.cpp                                                 ( o.o )    */
/*   Created: 2025/06/21 14:03:45 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/19 17:53:01                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn()
{

}

Rpn::~Rpn()
{

}

Rpn::Rpn(const Rpn& other)
{
	*this = other;
	return;
}

std::stack<int> Rpn::getStack() const
{
	return (_Stack);
}

Rpn& Rpn::operator=(const Rpn& other)
{
	if (this != &other)
	{
		this->_Stack = other.getStack();
	}
	return (*this);
}

int Rpn::evaluateToken(const std::string &tok)
{
    // If token is a single operator among + - * /
    if (tok == "+" || tok == "-" || tok == "*" || tok == "/")
    {
        // Here you must pop two values from the stack, compute lhs op rhs, push result.
        return 0;
    }

    if (tok.empty())
    {
        std::cerr << "Error" << std::endl;
        return -1;
    }

    //TODO: Accept optional leading plus/minus? The subject's numbers are < 10 and positive,
	//
    // but here we accept an optional sign. Adjust to your needs.
    std::size_t i = 0;

    if (tok[0] == '+' || tok[0] == '-')
	{
        if (tok.size() == 1)
		{
			std::cerr << "Error" << std::endl;
			return -1;
		}
        i = 1;
    }
    for (; i < tok.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(tok[i])))
        {
            std::cerr << "Error" << std::endl; // invalid token
            return -1;
        }
    }

    // Convert token to int
    std::stringstream ss(tok);
    int value;
    ss >> value;
    // Could check for extra garbage, but we validated chars already

    // Now push value on stack (placeholder commented)
    // _Stack.push(value);

    // For now, we return success so splitInput can continue.
	//
    return 0;
}

int Rpn::splitInput(const std::string &phrase)
{
	std::stringstream ss(phrase);
	std::string tok;

	if (phrase.empty())
	{
		std::cout << RED << "Error: " << RESET << "empty string" << std::endl;
		return (-1);
	}
	while (ss >> tok)
	{
		std::cout << "DEBUG: " << tok << std::endl;
		if (evaluateToken(tok) != 0)
			return (-1);
	}

	// After processing all tokens, in a full implementation you should
	// check that exactly one value remains on the stack and print it:
	//
	// if (_Stack.size() != 1)
	// {
	// 	std::cerr << "Error" << std::endl;
	// 	return -1;
	// 	}
	// std::cout << _Stack.top() << std::endl;
	//
	// For now, we simply return success.

	return (0);
}
