#pragma once
#include "Contact.h"
#include "Prieten.h"
#include <string>

using namespace std;

class Agenda
{
	Contact** v; // Contact* v[100];
	int count;
	int maxcount;
public:
	Agenda();
	bool FindName(string name);
	Prieten** Prieteni();
	void DeleteContact(string name);
	void Add(Contact* x);
	void ListAll();
};

Agenda::Agenda()
{
	count = 0;
	maxcount = 10;
	v = new Contact * [10];

}

void Agenda::Add(Contact* x)
{
	if (count < maxcount)
		v[count++] = x;
}

bool Agenda::FindName(string name)
{
	for (int i = 0; i < count; i++)
		if (v[i]->getName() == name)
			return true;
	return false;

}

void Agenda::DeleteContact(string name)
{
	for (int i = 0; i < count-1; i++)
		if (v[i]->getName() == name)
		{
			for (int j = i; j < count; j++)
				v[j] = v[j + 1];
			count--;
		}
	if (v[count - 1]->getName() == name)
		count--;

}

Prieten** Agenda::Prieteni()
{
	Prieten *x[10];
	int cont = 0;
	for (int i = 0; i < count; i++)
		if (v[i]->CeEste() == 0)
			x[cont++] =	(Prieten*) v[i];

	return x;
}

void Agenda::ListAll()
{
	cout << "Agenda este: " << endl;
	 for (int i = 0; i < count; i++)
		 v[i]->Print();

}