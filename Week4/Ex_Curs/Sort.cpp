#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#include "Sort.h"

using namespace std;

Sort::Sort(int countt, int minn, int maxx)
{
	count = countt;
	v = (int*)(malloc(count * sizeof(int)));

	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < count; i++) {
		v[i] = minn + rand() % (minn - maxx + 1);
	}
	
}

Sort::Sort(int count, ...)
{	
	this->count = count;
	v = (int*)(realloc(v, count * sizeof(int)));

	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
	{
		v[i] = va_arg(vl, int);
	}
	va_end(vl);
}

Sort::Sort(char* c)
{
	count = 0;
	char* p;

	char* aux;
	int size = strlen(c);
	aux = new char[size];
	memcpy(aux, c, strlen(c));
	aux[strlen(c)] = '\0';

	p = strtok(aux, ",");
	while(p)
	{
		count++;
		p = strtok(NULL, ",");
	}

	v = (int*)(realloc(v, count * sizeof(int)));

	memcpy(aux, c, strlen(c));
	aux[strlen(c)] = '\0';

	p = strtok(aux, ",");
	count = 0;
	while(p)
	{
		int x = 0;
		for (int i = 0; i < strlen(p); i++)
			x = x * 10 + p[i]-'0';
		v[count++] = x;
		p = strtok(NULL,",");
	}

}

Sort::Sort(int* x, int count)
{
	this->count = count;
	v = (int*)(realloc(v, count * sizeof(int)));
	for (int i = 0; i < count; i++)
		v[i] = x[i];

}

Sort::Sort(): v(new int [7] {16,20,8,17,-2,2,200})
{
	count = 7;
}

void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	for (i = 1; i < count; i++)
	{
		key = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > key)
		{
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void Sort::QuickSort(bool ascendent)
{
	quickSort(v,0,count-1);
}

void Sort::BubbleSort(bool ascendent)
{
	
		int i, j;
		for (i = 0; i < count; i++)
			for (j = 0; j < count - i - 1; j++)
				if (v[j] > v[j + 1])
				 swap(v[j], v[j + 1]);
	
}

void Sort::Print()
{	
	int i;
	printf("\n");
	for (i = 0; i < count; i++)
		printf("%d  ", v[i]);
}

int Sort::GetElementsCount()
{
	return count;
}

int Sort::GetElementFromIndex(int index)
{
	return v[index-1];
}
