#pragma once
#include "Contact.h"
#include <string>

using std::string;

class Coleg : public Contact
{
	string nrT, firma, adresa;
public:
	Coleg(string name, string nrT, string firma, string adresa);
	int CeEste() override;
	void Print();
};

 Coleg::Coleg(string name, string nrT, string firma, string adresa)
{
	this->name = name;
	this->nrT = nrT;
	this->firma = firma;
	this->adresa = adresa;
	
}

int Coleg::CeEste()
{
	return 2;
}

void Coleg::Print()
{
	cout << "Colegul " << name << " are nr. de telefon " << nrT << " locuieste la adresa " << adresa << " si lucreaza la firma " << firma << endl;
}
