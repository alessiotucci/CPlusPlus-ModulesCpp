/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: RPN.cpp                                                 ( o.o )    */
/*   Created: 2025/06/21 14:03:45 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/29 10:36:46                                   /         */
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
// Perform operator: pop two values (rhs, lhs), compute lhs op rhs, push result.
int Rpn::performOperation(const std::string &op)
{
    // Check enough operands
    if (_Stack.size() < 2)
    {
        std::cerr << "Error" << std::endl; // insufficient operands
        return -1;
    }

    // Pop rhs then lhs
    int rhs = _Stack.top(); _Stack.pop();
    int lhs = _Stack.top(); _Stack.pop();

    int result = 0;
    if (op == "+")
        result = lhs + rhs;
    else if (op == "-")
        result = lhs - rhs;
    else if (op == "*")
        result = lhs * rhs;
    else if (op == "/")
    {
        if (rhs == 0)
        {
            std::cerr << "Error" << std::endl; // division by zero
            return -1;
        }
        result = lhs / rhs; // integer division
    }
    else
    {
        std::cerr << "Error" << std::endl; // unknown operator (shouldn't happen)
        return -1;
    }

    // Push result
    _Stack.push(result);
    return 0;
}

// Parse token as integer and push. Accepts optional leading + or -.
// Returns 0 on success, -1 on error.
int Rpn::pushNumberToken(const std::string &tok)
{
    if (tok.empty())
    {
        std::cerr << "Error" << std::endl;
        return -1;
    }

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
            std::cerr << "Error" << std::endl;
            return -1;
        }
    }

    // Convert and push
    std::stringstream ss(tok);
    int value = 0;
    ss >> value;
    _Stack.push(value);
    return 0;
}
int Rpn::evaluateToken(const std::string &tok)
{
	if (tok == "+" || tok == "-" || tok == "*" || tok == "/")
	{
		/*std::cout << GREEN << "operation: " << tok << std::endl;
		std::cout << "1) Here you must pop two values from the stack" << std::endl;
		std::cout << "2) compute lhs op rhs" << std::endl;
		std::cout << "3) push result." << std::endl;
		return (0);*/
		return performOperation(tok);
	}

	if (tok.empty())
	{
		std::cout << RED << "Error: " << RESET << "empty token" << std::endl;
		return (-1);
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
		std::cout << RED << "Error: " << RESET << "[" << tok << "]" << "\tnot a digit" << std::endl;
            return -1;
        }
    }

    /* Convert token to int
    std::stringstream ss(tok);
    int value;
    ss >> value;
	//std::cout << YELLOW << "number: " << RESET << value;
    std::cout << " Now push value on stack" << std::endl;*/
    // _Stack.push(value);
	//
	return pushNumberToken(tok);
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


std::ostream& operator<<(std::ostream& os, const Rpn& rpn)
{
    std::stack<int> temp = rpn.getStack();
    const std::size_t maxSize = temp.size();

    // Allocate primitive array
    int* buffer = new int[maxSize];
    std::size_t index = 0;

    // Fill buffer with stack elements
    while (!temp.empty())
	{
        buffer[index++] = temp.top();
        temp.pop();
    }

	/*
    os << CYAN << "Stack State:\n" << RESET;
    os << YELLOW << "Size: " << maxSize << RESET << "\n";
    os << GREEN << "Empty: " << (maxSize == 0 ? "Yes" : "No") << RESET << "\n";
	*/

    if (maxSize > 0)
	{
		/*
        os << RED << "Top: " << buffer[maxSize - 1] << RESET << "\n";
        os << PURPLE << "Contents:\n" << RESET;
		*/

        // Print from bottom to top
        for (std::size_t i = 0; i < maxSize; ++i)
		{
            //os << "| " << YELLOW << " " << RESET << buffer[i];
            os << buffer[i];
        }
    }

    delete[] buffer; // Clean up
    return os;
}

