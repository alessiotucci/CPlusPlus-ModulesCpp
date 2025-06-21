/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: Span.hpp                                                ( o.o )    */
/*   Created: 2025/06/19 15:44:14 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/21 16:26:55                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

// Span.hpp
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm> // sort, min_element, max_element
#include <iterator>  // distance

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    ~Span();

    void addNumber(int n);
    int shortestSpan() const;
    int longestSpan() const;

};

#endif

