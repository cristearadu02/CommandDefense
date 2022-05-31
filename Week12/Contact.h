#pragma once
#include <string>

using std::string;

class Contact
{
protected:
	string name;
public:
	string getName()
	{
		return name;
	}
	virtual int CeEste() = 0;
	virtual void Print() = 0;
	//Contact();
};

