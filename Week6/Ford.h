#pragma once
#include "Car.h"
class Ford : public Car
{
public:
	Ford();
	//void setFuelCapacity(float) override;
	//void setFuelConsumption(float) override;
	//void setAvgSpeed(int r, int s, int snow) override;
	float RaceCalculator(float circLength, int weatherCondition) override;
	char* getName() override;
};

