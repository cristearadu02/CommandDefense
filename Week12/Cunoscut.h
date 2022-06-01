#pragma once
#include "Contact.h"
#include <string>
#include <iostream>

using namespace std;

class Cunoscut : public Contact
{
	string nrT;
public:
	Cunoscut(string name, string nrT);
	void Print();
};

Cunoscut::Cunoscut(string name, string nrT)
{
	CeEstee = cunoscut;
	this->name = name;
	this->nrT = nrT;
}

void Cunoscut::Print()
{
	cout << "Cunoscutul " << name << " are nr de telefon " << nrT << endl;
}