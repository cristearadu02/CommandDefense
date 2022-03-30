#include "Car.h"
#include "Ford.h"
#include "Weather.h"
#include <stdio.h>
#include <string.h>

Ford::Ford()
{
	fuelCapacity = 20.0f;
	fuelConsumption = 21.1f;
	avgSpeed[0] = 55;
	avgSpeed[1] = 92;
	avgSpeed[2] = 42;
	name = new char[5];
	memcpy(name, "Ford", 4);
	name[4] = '\0';
}

//
//void Ford::setFuelCapacity(float fcpt)
//{
//	fuelCapacity = fcpt;
//}
//
//void Ford::setFuelConsumption(float fcsm)
//{
//	fuelConsumption = fcsm;
//}
//
//void Ford::setAvgSpeed(int r, int s, int snow)
//{
//	avgSpeed[0] = r;
//	avgSpeed[1] = s;
//	avgSpeed[2] = snow;
//}

float Ford::RaceCalculator(float circLength, int weatherCondition)
{
	if (circLength * fuelConsumption / 100 <= fuelCapacity)
		return (circLength / avgSpeed[weatherCondition]);
	else
		return -1;
}

char* Ford::getName()
{
	return name;
}
