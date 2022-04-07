#include <iostream>
#include "Vector.h"

template <class T>
bool compare(T& a, T& b)
{
	//printf("Am apelat callback\n");
	return a > b;
}

template <class T>
bool equal(T& a, T& b)
{
	return a == b;
}

int main()
{
	Vector<int> v(6);
	v.push(200);
	v.push(500); 
	v.push(100);
	v.push(572);
	v.push(200);
	v.push(17);

	v.print();
	printf("Nr de elemente din vectorul curent este: %d\n", v.countt());
	printf("Operatia de pop pe vectorul curent: %d\n", v.pop());
	
	v.remove(1);
	v.print();
	printf("Nr de elemente din vectorul curent este: %d\n", v.countt());
	printf("Operatia de pop pe vectorul curent: %d\n", v.pop());

	v.set(2,69);
	v.print();

	printf("Am luat elementul: %d\n", v.get(3));
	printf("Vectorul are %d elemente.\n", v.countt());

	v.sort(&compare);
	v.print();

	printf("Prima data apare pe pozitia: %d\n",v.firstIndexOf(200,&equal));

	return 0;
}