#pragma once
#ifndef _ARRAY_H
#define _ARRAY_H
#include <iostream>

const int DEFAULT_CAPACITY = 10;

class ArrayException {};

class Array
{

public:
	int* ptr;

	int size, capacity;

	explicit Array(int startCapacity = DEFAULT_CAPACITY);
	~Array();

	Array(const Array& arr);

	Array& operator =(const Array& arr);

	int& operator [](int index);

	void insert(int index, int element);
	void insert(int element);
	void increaseCapacity(int size);
	void remove(int& index);

	int getSize() const;

};
#endif -
