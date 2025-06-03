#ifndef B_HPP
#define B_HPP

#include "Base.hpp"
#include <string>

class B : public Base
{
private:
public:
	B();
	B(const B& other);
	B& operator=(const B& other);
	~B();

};
#endif


