#pragma once
#include "Car.h"
class Mazda : public Car
{
public:
	Mazda();
	//void setFuelCapacity(float) override;
	//void setFuelConsumption(float) override;
	//void setAvgSpeed(int r, int s, int snow) override;
	float RaceCalculator(float circLength, int weatherCondition) override;
	char* getName() override;
};

