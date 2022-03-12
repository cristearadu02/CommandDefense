#include "Math.h"
#include <stdarg.h> // pt va_start
#include <string.h> // pt strcpy
#include <stdlib.h> // pt malloc

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

double Math::Add(double x, double y)
{
	return x + y;
}

double Math::Add(double x, double y, double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

double Math::Mul(double x, double y)
{
	return x * y;
}

double Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...)
{
	int x, s = 0;
	va_list vl; // Am creat o lista 
	va_start(vl, count); // Alocam spatiul pt lista
	for (int i = 0; i < count; i++)
	{
		x = va_arg(vl, int); // Citim un parametru din functie (tipul lui fiind int)
		s += x;
		// se trece la urmatorul parametru
	}
	return s;
}

char* Math::Add(const char* sir1, const char* sir2)
{
	if (sir1 == nullptr || sir2 == nullptr)
		return nullptr; // daca un sir e nullptr, returnam nullptr
	int SizeToRealloc;
	SizeToRealloc = strlen(sir1) + strlen(sir2) + 1; // calculam cata memorie alocam pentru returnarea concatenarii (+1 pt caracterul de final)
	char* Concat = nullptr; // nu e neaparat sa-l initializam

		Concat = (char*)malloc(SizeToRealloc); // alocam memorie pentru variabila concat, specificand ca este de tipul char* (facem cast, implicit malloc e de tip void *)
		memset(Concat, 0, SizeToRealloc); // umplem Concat cu un caracter null
		if (Concat != nullptr)
		{
			memcpy(Concat, sir1, strlen(sir1)); // copiem sir1 in Concat
			memcpy(Concat + strlen(sir1), sir2, strlen(sir2)); // copiem sir2 in Concat

		}
	
	return Concat;
}
