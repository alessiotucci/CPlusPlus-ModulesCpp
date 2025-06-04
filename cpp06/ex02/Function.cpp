/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Function.cpp                                            ( o.o )    */
/*   Created: 2025/06/03 18:04:58 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/03 18:05:57                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate()
{
    int r = rand() % 3;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base& p)
{
    try
	{
        A& a = dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
	catch (...) {}

    try
	{
        B& b = dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
	catch (...) {}

    try
	{
        C& c = dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
	catch (...) {}
}

