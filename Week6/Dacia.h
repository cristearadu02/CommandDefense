#pragma once
#include "Car.h"
class Dacia : public Car
{
public:
	Dacia();
	//void setFuelCapacity(float) override;
	//void setFuelConsumption(float) override;
	//void setAvgSpeed(int r, int s, int snow) override;
	float RaceCalculator(float circLength, int weatherCondition) override;
	char* getName() override;
};

