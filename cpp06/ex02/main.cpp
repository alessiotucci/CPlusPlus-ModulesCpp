/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/03 17:50:04 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/05 17:16:51                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "Function.cpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    for (int i = 0; i < 12; i++) {
        std::cout << "\033[1;33m" << "===== TEST " << i + 1 << " =====" << "\033[0m" << std::endl;
        
        Base* obj = generate();
        std::cout << std::endl;
        
        std::cout << "Identify by pointer: \033[1;36m";
        identify(obj);
        std::cout << "\033[0m";
        
        std::cout << "Identify by reference: \033[1;35m";
        identify(*obj);
        std::cout << "\033[0m" << std::endl;
        
        delete obj;
    }
    
    return 0;
}
