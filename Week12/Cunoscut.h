#pragma once
#include "Contact.h"
#include <string>

using namespace std;

class Cunoscut : public Contact
{
	string nrT;
public:
	int CeEste() override;
	Cunoscut(string name, string nrT);
	void Print();
};

Cunoscut::Cunoscut(string name, string nrT)
{
	this->name = name;
	this->nrT = nrT;
}

int Cunoscut::CeEste()
{
	return 1;
}

void Cunoscut::Print()
{
	cout << "Cunoscutul " << name << " are nr de telefon " << nrT << endl;
}