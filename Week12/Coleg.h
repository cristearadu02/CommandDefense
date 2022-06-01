#pragma once
#include "Contact.h"
#include <string>
#include <iostream>

using namespace std;

class Coleg : public Contact
{
	string nrT, firma, adresa;
public:
	Coleg(string name, string nrT, string firma, string adresa);
	void Print();
};

 Coleg::Coleg(string name, string nrT, string firma, string adresa)
{	
	 CeEstee = coleg;
	this->name = name;
	this->nrT = nrT;
	this->firma = firma;
	this->adresa = adresa;
	
}

void Coleg::Print()
{
	cout << "Colegul " << name << " are nr. de telefon " << nrT << " locuieste la adresa " << adresa << " si lucreaza la firma " << firma << endl;
}
