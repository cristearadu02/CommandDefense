#pragma once
#include "Car.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"

class Circuit
{
	float length;
	int weather, count;
	int NumberOfCars;
	Car** cars;
	float* time;
public:
	Circuit();
	void SetLength(float);
	void SetWeather(int);
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void Race();
	void AddCar(Car *c);
	void Sort();
	
};

