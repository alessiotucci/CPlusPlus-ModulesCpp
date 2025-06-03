#ifndef A_HPP
#define A_HPP

#include "Base.hpp"
#include <string>

class A : public Base
{
private:
public:
	A();
	A(const A& other);
	A& operator=(const A& other);
	~A();

};
#endif


