#pragma once
#include <string.h>
#include "Contact.h"

using namespace std;

class Prieten : public Contact
{
	string nrT, adresa, dataN;
	//date dataN;
public:
	Prieten(string name, string nrT, string adresa, string dataN);
	int CeEste() override;
	void Print();
};

int Prieten::CeEste()
{
	return 0;
}

Prieten::Prieten(string name, string nrT, string adresa, string dataN)
{
	this->name = name;
	this->nrT = nrT;
	this->adresa = adresa;
	this->dataN = dataN;

}

void Prieten::Print()
{
	cout << "Prietenul " << name << " are nr. de telefon " << nrT << " locuieste la adresa " << adresa << " si e nascut la data de " << dataN << endl;
}