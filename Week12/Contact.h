#pragma once
#include <string>
#include "ContactType.h"
#include <iostream>

using namespace std;

class Contact
{
protected:
	string name;
	ContactType CeEstee;
public:
	string getName()
	{
		return name;
	}
	ContactType CeEste()
	{
		return CeEstee;
	}
	virtual void Print() = 0;
	//Contact();
};

