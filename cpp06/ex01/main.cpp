/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/05/30 15:27:19 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/03 13:13:06                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int	main() {
	std::cout << "=== TESTING Serializer ===\n";

	// --- Test 1 ---
	std::cout << "\n[TEST 1] Data(4, 2)\n";
	Data d1(4, 2);
	std::cout << "Original object: " << d1;

	uintptr_t raw1 = Serializer::serialize(&d1);
	Data* ptr1 = Serializer::deserialize(raw1);

	std::cout << "Deserialized pointer: " << ptr1 << "\n";

	if (ptr1 == &d1)
		std::cout << "✅ Pointers match.\n";
	else
		std::cout << "❌ Pointers do not match.\n";

		// --- Test 2 ---
	std::cout << "\n[TEST 2] Data(99, -1)\n";
	Data d2(99, -1);
	std::cout << "Original object: " << d2;

	uintptr_t raw2 = Serializer::serialize(&d2);
	Data* ptr2 = Serializer::deserialize(raw2);

	std::cout << "Deserialized pointer: " << ptr2 << "\n";

	if (ptr2 == &d2)
		std::cout << "✅ Pointers match.\n";
	else
		std::cout << "❌ Pointers do not match.\n";

	// --- Test 3 ---
	std::cout << "\n[TEST 3] Data(0, 0)\n";
	Data d3(0, 0);
	std::cout << "Original object: " << d3;

	uintptr_t raw3 = Serializer::serialize(&d3);
	Data* ptr3 = Serializer::deserialize(raw3);

	std::cout << "Deserialized pointer: " << ptr3 << "\n";

	if (ptr3 == &d3)
		std::cout << "✅ Pointers match.\n";
	else
		std::cout << "❌ Pointers do not match.\n";
	std::cout << "\n=== END OF TESTS ===\n";
	return 0;
}

