#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Sort.h"
using namespace std;

int main()
{
	char c1[] = "209,73,900,85,6"; 
	Sort a(c1); // din sir de caractere
	a.Print();
	a.BubbleSort();
	a.Print();
	a.QuickSort();
	a.Print();
	a.InsertSort();
	a.Print();
	printf("\n%d\n%d", a.GetElementsCount(), a.GetElementFromIndex(2));
	
	printf("\n");
	int v[] = { 101, 202,76, 21,9001, 10,-2, 13 };
	int nr = sizeof(v) / sizeof(v[1]);
	Sort b(v,nr); // din alt vector
	b.Print();
	b.BubbleSort();
	b.Print();
	b.QuickSort();
	b.Print();
	b.InsertSort();
	b.Print();
	printf("\n%d\n%d", b.GetElementsCount(), b.GetElementFromIndex(2));

	printf("\n");
	Sort c(10, -200, 7000); // din interval random
	c.Print();
	c.BubbleSort();
	c.Print();
	c.QuickSort();
	c.Print();
	c.InsertSort();
	c.Print();
	printf("\n%d\n%d", c.GetElementsCount(), c.GetElementFromIndex(2));

	printf("\n");
	Sort d(7, -23, 1, -45, 203, 67, 16); // din variadic parameters
	d.Print();
	d.BubbleSort();
	d.Print();
	d.QuickSort();
	d.Print();
	d.InsertSort();
	d.Print();
	printf("\n%d\n%d", d.GetElementsCount(), d.GetElementFromIndex(2));

	printf("\n");
	Sort e; // din lista de initializare
	e.Print();
	e.BubbleSort();
	e.Print();
	e.QuickSort();
	e.Print();
	e.InsertSort();
	e.Print();
	printf("\n%d\n%d", e.GetElementsCount(), e.GetElementFromIndex(2));

	return 0;
}