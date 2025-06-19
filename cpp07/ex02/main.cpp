/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/13 13:36:10 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/19 12:39:50                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

// Custom test class
class Point {
private:
    int _x;
    int _y;
public:
    Point() : _x(0), _y(0) {}
    Point(int x, int y) : _x(x), _y(y) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p._x << "," << p._y << ")";
        return os;
    }
};

int main() {
    std::cout << "\n\033[1;36m===== TEST 1: Basic Int Array =====\033[0m\n";
    {
        Array<int> arr(5);
        std::cout << "Size: " << arr.size() << std::endl;
        
        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i * 10;
        
        std::cout << "Elements: ";
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        
        try {
            std::cout << "Trying to access index 5: ";
            std::cout << arr[5] << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what();
        }
    }

    std::cout << "\n\033[1;36m===== TEST 2: Copy and Assignment =====\033[0m\n";
    {
        Array<std::string> names(3);
        names[0] = "Alice";
        names[1] = "Bob";
        names[2] = "Charlie";
        
        // Copy constructor
        Array<std::string> namesCopy(names);
        names[1] = "Robert";
        
        std::cout << "Original[1]: " << names[1] << std::endl;
        std::cout << "Copy[1]: " << namesCopy[1] << std::endl;
        
        // Assignment operator
        Array<std::string> namesAssigned;
        namesAssigned = names;
        names[0] = "Alex";
        
        std::cout << "Original[0]: " << names[0] << std::endl;
        std::cout << "Assigned[0]: " << namesAssigned[0] << std::endl;
        
        // Self-assignment test
        namesAssigned = namesAssigned;
        std::cout << "Self-assignment test: " << namesAssigned[0] << std::endl;
    }

    std::cout << "\n\033[1;36m===== TEST 3: Custom Class (Point) =====\033[0m\n";
    {
        Array<Point> points(4);
        for (unsigned int i = 0; i < points.size(); i++)
            points[i] = Point(i, i*2);
        
        std::cout << "Points: ";
        for (unsigned int i = 0; i < points.size(); i++)
            std::cout << points[i] << " ";
        std::cout << std::endl;
        
        // Test const access
        const Array<Point> constPoints(points);
        std::cout << "Const access: " << constPoints[2] << std::endl;
    }

    std::cout << "\n\033[1;36m===== TEST 4: Empty Array =====\033[0m\n";
    {
        Array<double> empty;
        std::cout << "Empty size: " << empty.size() << std::endl;
        
        try {
            std::cout << "Access empty array: ";
            std::cout << empty[0] << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what();
        }
    }

    std::cout << "\n\033[1;36m===== TEST 5: Exception Handling =====\033[0m\n";
    {
        Array<int> arr(3);
        
        try {
            std::cout << "Negative index test: ";
            std::cout << arr[-1] << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what();
        }
        
        try {
            std::cout << "Out-of-bound index test: ";
            std::cout << arr[10] << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what();
        }
    }

    std::cout << "\n\033[1;36m===== TEST 6: Float Array =====\033[0m\n";
    {
        Array<float> floats(4);
        for (unsigned int i = 0; i < floats.size(); i++)
            floats[i] = i + 0.5f;
        
        std::cout << "Floats: ";
        for (unsigned int i = 0; i < floats.size(); i++)
            std::cout << floats[i] << " ";
        std::cout << std::endl;
        
        // Test assignment
        Array<float> floats2 = floats;
        floats2[0] = 99.9f;
        std::cout << "Original[0]: " << floats[0] << std::endl;
        std::cout << "Assigned[0]: " << floats2[0] << std::endl;
    }

    std::cout << "\n\033[1;32mALL TESTS COMPLETED SUCCESSFULLY!\033[0m" << std::endl;
    return 0;
}
