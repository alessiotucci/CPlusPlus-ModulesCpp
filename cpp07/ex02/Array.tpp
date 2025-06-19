template<typename T>
Array<T>::Array() : _size(0), _array(NULL) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]()) {}

template<typename T>
Array<T>::Array(const Array<T> &other) : _size(other._size), _array(NULL)
{
	if (other._size > 0)
	{
		_array = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			_array[i] = other._array[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		else
			_array = NULL;
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
T & Array<T>::operator[](int index)
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw ArrayOutOfBoundException();
	return _array[index];
}

template<typename T>
const T & Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw ArrayOutOfBoundException();
	return _array[index];
}

template<typename T>
const char *Array<T>::ArrayOutOfBoundException::what() const throw()
{
	return "Array custom exception: out of bounds!\n";
}
