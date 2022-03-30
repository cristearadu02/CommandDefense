#include "Car.h"
#include "Toyota.h"
#include "Weather.h"
#include <stdio.h>
#include <string.h>

Toyota::Toyota()
{
	fuelCapacity = 55.0f;
	fuelConsumption = 6.2f;
	avgSpeed[0] = 60;
	avgSpeed[1] = 90;
	avgSpeed[2] = 45;
	name = new char[7];
	memcpy(name, "Toyota", 6);
	name[6] = '\0';
}

//
//void Toyota::setFuelCapacity(float fcpt)
//{
//	fuelCapacity = fcpt;
//}
//
//void Toyota::setFuelConsumption(float fcsm)
//{
//	fuelConsumption = fcsm;
//}
//
//void Toyota::setAvgSpeed(int r, int s, int snow)
//{
//	avgSpeed[0] = r;
//	avgSpeed[1] = s;
//	avgSpeed[2] = snow;
//}

float Toyota::RaceCalculator(float circLength, int weatherCondition)
{
	if (circLength * fuelConsumption / 100 <= fuelCapacity)
		return (circLength / avgSpeed[weatherCondition]);
	else
		return -1;
}

char* Toyota::getName()
{
	return name;
}
