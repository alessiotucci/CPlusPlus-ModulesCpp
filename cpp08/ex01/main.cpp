/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/19 15:16:53 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/21 16:22:32                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <ctime>

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;

    // Test con 10000 numeri
    Span bigSpan(10000);
    std::srand(std::time(0));
    for (int i = 0; i < 10000; ++i) {
        bigSpan.addNumber(std::rand());
    }

    std::cout << "Big Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Big Longest: " << bigSpan.longestSpan() << std::endl;

    // Test addRange
    std::vector<int> extra(3, 42); // Tre 42
    Span rspan(10);
    rspan.addRange(extra.begin(), extra.end());

    std::cout << "Done!" << std::endl;

    return 0;
}

