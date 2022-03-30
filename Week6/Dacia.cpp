#include "Car.h"
#include "Dacia.h"
#include "Weather.h"
#include <stdio.h>
#include <string.h>

Dacia::Dacia()
{
	fuelCapacity = 50.0f;
	fuelConsumption = 5.5f;
	avgSpeed[0] = 50;
	avgSpeed[1] = 80;
	avgSpeed[2] = 30;
	name = new char[6];
	memcpy(name,"Dacia",5);
	name[5] = '\0';
}

//void Dacia::setFuelCapacity(float fcpt)
//{ 
//	fuelCapacity = fcpt;
//}
//
//void Dacia::setFuelConsumption(float fcsm)
//{
//	fuelConsumption = fcsm;
//}
//
//void Dacia::setAvgSpeed(int r, int s, int snow)
//{
//	avgSpeed[0] = r;
//	avgSpeed[1] = s;
//	avgSpeed[2] = snow;
//}

float Dacia::RaceCalculator(float circLength, int weatherCondition)
{
	if (circLength * fuelConsumption / 100 <= fuelCapacity)
		return (circLength / avgSpeed[weatherCondition]);
	else
		return -1;
}

char* Dacia::getName()
{
	return name;
}

