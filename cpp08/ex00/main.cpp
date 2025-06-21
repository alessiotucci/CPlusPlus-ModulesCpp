/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/19 15:16:27 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/21 16:15:39                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::cout << "TEST 1: Container: std::vector<int>" << std::endl;
	std::vector<int> my_vector;
	for (int i = 0; i < 5; i++)
	{
		my_vector.push_back(i * 3);
	}

	std:: cout << "[ ";
	std::vector<int>::iterator it;
	for (it = my_vector.begin(); it != my_vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std:: cout << " ]";
	std::cout << std::endl;

	std::cout << "Looking for 3 in vector: ";
	std::cout << ((easyfind(my_vector, 3)) ? "FOUND\n" : "NOT FOUND\n");
	std::cout << "Looking for 42 in vector: ";
	std::cout << ((easyfind(my_vector, 42)) ? "FOUND\n" : "NOT FOUND\n");

//
	std::cout << "TEST 2: Container: std::deque<int>" << std::endl;
	std::deque<int> my_deque;
	for (int i = 44; i < 50; i++)
	{
		my_deque.push_back(i + 11);
	}

	std:: cout << "[ ";
	std::deque<int>::iterator it2;
	for (it2 = my_deque.begin(); it2 != my_deque.end(); ++it2)
	{
		std::cout << *it2 << " ";
	}
	std:: cout << " ]";
	std::cout << std::endl;

	std::cout << "Looking for 35 in deque: ";
	std::cout << ((easyfind(my_deque, 55)) ? "FOUND\n" : "NOT FOUND\n");
	std::cout << "Looking for 1000 in deque: ";
	std::cout << ((easyfind(my_deque, 1000)) ? "FOUND\n" : "NOT FOUND\n");

//
	std::cout << "TEST 3: Container: std::list<int>" << std::endl;
	std::list<int> my_list;
	for (int i = -10; i < -5; i++)
	{
		my_list.push_back(i * 11);
	}
	std:: cout << "[ ";
	std::list<int>::iterator it3;
	for (it3 = my_list.begin(); it3 != my_list.end(); ++it3)
	{
		std::cout << *it3 << " ";
	}
	std:: cout << " ]";
	std::cout << std::endl;

	std::cout << "Looking for 249 in list: ";
	std::cout << ((easyfind(my_list, 249)) ? "FOUND\n" : "NOT FOUND\n");

	std::cout << "Looking for 999 in list: ";
	std::cout << ((easyfind(my_list, -110)) ? "FOUND\n" : "NOT FOUND\n");


	return (0);
}

