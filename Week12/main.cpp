#include <iostream>
#include <string>
#include "Agenda.h"
#include "Contact.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Prieten.h"

using namespace std;

int main()
{
	Agenda x;
	
	x.Add(new Prieten("Radu", "0757641022", "Tecuci", "17.05.2002"));
	x.Add(new Prieten("Roxana", "0757641022", "Iasi, str. Aleea Plopilor", "16.04.2002"));
	x.Add(new Cunoscut("Gigel", "0730128148"));
	x.Add(new Coleg("Marian", "0790106781", "FII", "Str. Fierarilor"));
	
	x.ListAll();
	
	if (x.FindName("Radu") == true)
		cout << "L am gasit pe Radu" << endl;
	else
		cout << "Nu l am gasit Radu" << endl;
	cout << endl;

	x.DeleteContact("Radu");
	x.ListAll();
	
	if (x.FindName("Radu") == true)
		cout << "L am gasit pe Radu" << endl;
	else
		cout << "Nu l am gasit Radu" << endl;
	
	 cout << endl;

	 Prieten** y; // = x.Prieteni();
	 y = new Prieten * [10];
	 y = x.Prieteni();
	 y[0]->Print();

	return 0;
}