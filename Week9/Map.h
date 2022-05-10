#pragma once
#include "Camp.h"

template <class A, class B>
class MyIterator
{
//public:
	camp<A, B> v[100];
	int index; 
	int cont;
public:
	MyIterator(camp<A,B> vec[], int index_param, int count)  {
		index = index_param;
		cont = count;
		for (int i = 0; i < cont; i++)
		{
			v[i].key = vec[i].key;
			v[i].value = vec[i].value;
			v[i].index = vec[i].index;
			//std::cout << v[i].key << "     "<<v[i].value<<std::endl;
		}
	}
	bool operator!=(const MyIterator& other) const
	{
		return this->index != other.index;
	}

	MyIterator& operator++()
	{
		++index;
		return *this;
	}

	/*A& operator*() 
	{
			return v[index].key;
	}*/
	
	/*B& operator*()
	{
		return v[index].value;
	}*/
	
	camp<A, B>& operator*()
	{
		return v[index];
	}
};

template <class A, class B>
class Map
{
//public:
	camp<A, B> v[100];
	int count;
	//int max_count;
public:
	Map(int size);
	Map();
	B& operator [](A key);
	MyIterator<A, B> begin();
	MyIterator<A, B> end();
	void Set(A key, B value);
	int Count();
	void Clear();
	void resize();
};

template<class A, class B>
inline Map<A, B>::Map(int size)
{	
	count = 0;
	//max_count = size;
	//v = new camp<A, B>[size];
}

template<class A, class B>
inline Map<A, B>::Map()
{
	count = 0;
	//max_count = 1;
	//v = new camp<A, B>[10];
}

template<class A, class B>
B& Map<A, B>::operator[](A key)
{
	int i = 0;
	v[count].index = count;
	for (i = 0; i < count; i++)
		if (v[i].key == key)
			return v[i].value;
	/*if (count > max_count)
		resize();*/
	v[count++].key = key;
	return v[count - 1].value;

}

template<class A, class B>
 inline MyIterator<A,B> Map<A, B>::begin() 
 {
	//std::cout << "begin" << std::endl;
	return { v, 0, count };
}

template<class A, class B>
inline MyIterator<A, B> Map<A, B>::end() 
{
	//std::cout << "end" << std::endl;
	return { v, count, count };
}

template<class A, class B>
void Map<A, B>::Set(A key, B value)
{
	int i = 0;
	v[count].index = count;
	for (i = 0; i < count; i++)
		if (v[i].key == key)
			 v[i].value=value;
	v[count++].key = key;
	v[count - 1].value=value;
}

template<class A, class B>
inline int Map<A, B>::Count()
{
	return count;
}

template<class A, class B>
 void Map<A, B>::Clear()
{
	
	count = -1;
	delete[] v;
}

template<class A, class B>
inline void Map<A, B>::resize()
{
	//max_count *= 2;
	//v = (camp<A,B>*)realloc(v, max_count * sizeof(camp<A, B>));
}

