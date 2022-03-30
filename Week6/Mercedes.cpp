#include "Car.h"
#include "Mercedes.h"
#include "Weather.h"
#include <stdio.h>
#include <string.h>

Mercedes::Mercedes()
{
	fuelCapacity = 80.0f;
	fuelConsumption = 9.5f;
	avgSpeed[0] = 90;
	avgSpeed[1] = 130;
	avgSpeed[2] = 60;
	name = new char[9];
	memcpy(name, "Mercedes", 8);
	name[8] = '\0';
}

//
//void Mercedes::setFuelCapacity(float fcpt)
//{
//	fuelCapacity = fcpt;
//}
//
//void Mercedes::setFuelConsumption(float fcsm)
//{
//	fuelConsumption = fcsm;
//}
//
//void Mercedes::setAvgSpeed(int r, int s, int snow)
//{
//	avgSpeed[0] = r;
//	avgSpeed[1] = s;
//	avgSpeed[2] = snow;
//}

float Mercedes::RaceCalculator(float circLength, int weatherCondition)
{
	if (circLength * fuelConsumption / 100 <= fuelCapacity)
		return (circLength / avgSpeed[weatherCondition]);
	else
		return -1;
}

char* Mercedes::getName()
{
	return name;
}
