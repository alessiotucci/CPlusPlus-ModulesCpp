/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/05/30 15:27:19 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/03 13:07:07                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"
int	main()
{
	std::cout << "TESTING\n";

	Data ita(4, 2);
	uintptr_t raw;
	std::cout << ita;

	raw = Serializer::serialize(&ita);
	Serializer::deserialize(raw);
//TODO: FROM THE SUBJECT
/*Use serialize() on the address of the Data object and pass its return value to
deserialize().
Then, ensure the return value of deserialize() compares equal to the
original pointer.*/
	return (0);
}
