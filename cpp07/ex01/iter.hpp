/* ************************************************************************** */
/*                                                                            */
/*   Host: e4r2p4.42roma.it                                           /_/     */
/*   File: iter.hpp                                                ( o.o )    */
/*   Created: 2025/06/17 14:47:26 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/17 15:30:03                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */
#ifndef ITER_HPP
#define ITER_HPP

/*
 Implement a function template iter that takes 3 parameters and returns nothing
• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be called on every element of the array
*/

template <typename T, typename U>
void iter(const T *array, int lenght, void (*func)(U))
{
	if (array == NULL || lenght <= 0 || func == NULL)
		return ;
	for (int i = 0; i < lenght; i++)
	{
		func(array[i]);
	}
}
#endif
