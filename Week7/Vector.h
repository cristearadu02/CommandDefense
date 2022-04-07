#pragma once

#include <iostream>
#include <stdlib.h>  

template <class T>
class Vector
{
	T* v;
	int count;
	int maxElements;
public:
	Vector();
	Vector(int);
	void push(T);
	T pop();
	bool remove(int);
	bool insert(int index, T element);
	void sort(bool (*callback)(T&, T&) = nullptr);
	T& get(int) const;
	void set(int index, T element);
	int countt();
	void print();
	void resize();
	int firstIndexOf(T WhatToFind, bool (*callback)(T&, T&) = nullptr);
};

template <class T>
Vector<T>::Vector()
{
	count = 0;
	v = nullptr;
}

template <class T>
Vector<T>::Vector(int x)
{
	count = 0;
	v = new T[x];
	maxElements = x;
}

template <class T>
void Vector<T>::push(T x)
{
	if (count < maxElements)
	{
		v[count++] = x;
		//printf("\n count: %d max: %d\n", count, maxElements);
	}
	else
	{
		resize();
		v[count++] = x;
	}
}

template <class T>
T Vector<T>::pop()
{
	if (count >= 0)
		return v[count-1];
		
}

template <class T>
bool Vector<T>::remove(int x)
{	
	if (x<0 || x>count)
		return false;
	for (int i = x-1; i < count; i++)
		v[i] = v[i + 1];
	count--;
	return true;
}

template <class T>
bool Vector<T>::insert(int x, T element)
{	
	if (x<0 || x>count)
		return false;
	count++;
	for (int i = count; i > x; i--)
		v[i] = v[i] - 1;
	v[x] = element;
	return true;
}

template <class T>
void Vector<T>::sort(bool (*callback)(T&, T&))
{
	if (callback == nullptr)
	{ for(int i = 0; i<count-1; i++)
		for(int j = i+i; j<count; j++)
			if (v[i] > v[j])
			{
				T aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
	}
	else
		for (int i = 0; i < count - 1; i++)
			for (int j = i + i; j < count; j++)
				if (callback(v[i], v[j]) == true)
				{
					T aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}
}


template <class T>
T& Vector<T>::get(int x) const
{
	if(x>0 && x<count)
		return v[x-1];
}

template <class T>
void Vector<T>::set(int index, T element)
{
	if (index > 0 && index < count)
		v[index-1] = element;
}

template <class T>
int Vector<T>::countt()
{
	return this->count;
}

template <class T>
void Vector<T>::print()
{
	for (int i = 0; i < count; i++)
		std::cout << v[i] << ' ';
	std::cout << std::endl;
}

template <class T>
void Vector<T>::resize()
{
	maxElements *= 2;
	v = (T*)realloc(v, maxElements * sizeof(T));
	//printf("\n AM REALOCAT: %d\n", maxElements);
}

template <class T>
int Vector<T>::firstIndexOf(T WhatToFind, bool (*callback)(T&, T&))
{
	if (callback == nullptr)
	{
		for (int i = 0; i < count; i++)
			if (v[i] == WhatToFind)
				return i+1;
	}
	else
		for (int i = 0; i < count; i++)
			if (callback(v[i], WhatToFind) == true)
				return i+1;
	
	 return -1;
}