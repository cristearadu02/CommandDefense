#pragma once
#include<string.h>
#include <stdio.h>
class Car
{
protected:
	float fuelCapacity, fuelConsumption, avgSpeed[3];
	
	char* name;
public:
	Car()
	{
		fuelCapacity = 0.0f;
		fuelConsumption = 0.0f;
		avgSpeed[0] = 0;
		avgSpeed[1] = 0;
		avgSpeed[2] = 0;
	};
	Car(const Car &a)
	{
		fuelCapacity = a.fuelCapacity;
		fuelConsumption = a.fuelConsumption;
		avgSpeed[0] = a.avgSpeed[0];
		avgSpeed[1] = a.avgSpeed[1];
		avgSpeed[2] = a.avgSpeed[2];
		name = new char[strlen(a.name)+1];
		memcpy(name, a.name, strlen(a.name) + 1);
	}
	//virtual void setFuelCapacity(float);
	//virtual void setFuelConsumption(float);
	//virtual void setAvgSpeed(int r, int s, int snow);
	virtual float RaceCalculator(float circLength, int weatherCondition) = 0;
	virtual char* getName() = 0;
	 Car& operator =(const Car & a){
		fuelCapacity = a.fuelCapacity;
		fuelConsumption = a.fuelConsumption;
		avgSpeed[0] = a.avgSpeed[0];
		avgSpeed[1] = a.avgSpeed[1];
		avgSpeed[2] = a.avgSpeed[2];
		name = new char[strlen(a.name) + 1];
		memcpy(name, a.name, strlen(a.name) + 1);
		return *this;
	}
};

