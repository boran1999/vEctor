#include <iostream>
#include "Array.h"

using namespace std;

Array::Array(int startapacity)
{
	if (startapacity <= 0)
		capacity = DEFAULT_CAPACITY;
	else
		capacity = startapacity;
	ptr = new int[capacity];
	size = 0;
}

Array::~Array()
{
	delete[] ptr;
}

Array::Array(const Array &arr)
{
	ptr = new int[arr.capacity];
	size = arr.size;
	capacity = arr.capacity;
	for (int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
}

Array& Array::operator =(const Array& arr)
{
	if (this == &arr)
		return *this;
	if (capacity != arr.capacity)
	{
		delete[] ptr;
		ptr = new int[arr.capacity];
		capacity = arr.capacity;
	}
	size = arr.size;
	for (int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
	return *this;
}

int& Array::operator [](int index)
{
	if (index >= size || index < 0)
		throw ArrayException();
	else
		return ptr[index];
}

void Array::increaseCapacity(int newCapacity)
{
	capacity = newCapacity < capacity * 2 ? capacity * 2 : newCapacity;
	int* newPtr = new int[capacity];
	for (int i = 0; i < size; i++)
		newPtr[i] = ptr[i];
	delete[] ptr;
	ptr = newPtr;
}

void Array::insert(int index, int element)
{
	if (index < 0 || index > size)
		throw ArrayException();
	if (size == capacity)
		increaseCapacity(size + 1);
	for (int j = size - 1; j >= index; j--)
		ptr[j + 1] = ptr[j];
	size++;
	ptr[index] = element;
}

void Array::insert(int elem)
{
	insert(size, elem);
}

void Array::remove(int& index)
{
	if (index < 0 && index >= size)
		throw ArrayException();
	for (int i = index; i < size - 1; i++)
		ptr[i] = ptr[i + 1];
	ptr[size - 1] = 0;
	size--;
}

int Array::getSize() const
{
	return size;
}


