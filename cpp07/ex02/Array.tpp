/* ************************************************************************** */
/*                                                                            */
/*   Host: e3r12p1.42roma.it                                          /_/     */
/*   File: Array.tpp                                               ( o.o )    */
/*   Created: 2025/06/18 16:24:50 | By: atucci <atucci@student.42  > ^ <      */
/*   Updated: 2025/06/18 16:39:00                                   /         */
/*   OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

// Array.tpp
template<typename T>
/*Construction with no parameter: Creates an empty array.*/
Array<T>::Array()
{
	//empty array
}

/*Construction with an unsigned int n as a parameter:
 * Creates an array of n elements initialized by default*/
Array<T>::Array(unsigned int n) : _size(n)
{
	// allocate memory
}

Array<T>::Array(const Array &other)
{
	*this = other;
}

Array& Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		for(int i = 0; i < _size; i++)
		{
			this->_array[i] = other->_array[i];
		}
	}
	return (*this);
}

Array<T>::~Array()
{
	// delete memory
}

/*Elements can be accessed through the subscript operator: [ ].*/

/*A member function size() that returns the number of elements in the array. This
member function takes no parameters and must not modify the current instance.*/
int Array<T>::size() const
{
	return (_size);
}



const char *Array<T>::what() const throw()
{
	return ("Array custom exception: out of bounds!\n");
}
