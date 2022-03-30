#include "Car.h"
#include "Mazda.h"
#include "Weather.h"
#include <stdio.h>
#include <string.h>

Mazda::Mazda()
{
	fuelCapacity = 52.5f;
	fuelConsumption = 6.8f;
	avgSpeed[0] = 55;
	avgSpeed[1] = 85;
	avgSpeed[2] = 40;
	name = new char[6];
	memcpy(name, "Mazda", 5);
	name[5] = '\0';
}

//
//void Mazda::setFuelCapacity(float fcpt)
//{
//	fuelCapacity = fcpt;
//}
//
//void Mazda::setFuelConsumption(float fcsm)
//{
//	fuelConsumption = fcsm;
//}
//
//void Mazda::setAvgSpeed(int r, int s, int snow)
//{
//	avgSpeed[0] = r;
//	avgSpeed[1] = s;
//	avgSpeed[2] = snow;
//}

float Mazda::RaceCalculator(float circLength, int weatherCondition)
{
	if (circLength * fuelConsumption / 100 <= fuelCapacity)
		return (circLength / avgSpeed[weatherCondition]);
	else
		return -1;
}

char* Mazda::getName()
{
	return name;
}
