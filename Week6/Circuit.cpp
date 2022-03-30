#include "Circuit.h"
#include "Weather.h"
#include "Car.h"
#include <iostream>
#include <stdlib.h>


Circuit::Circuit()
{
	length = 0.0f;
	weather = -1;
	count = 0;
	cars = new Car * [10];//(Car**)(malloc(10 * sizeof(Car*)));
	time = new float[10];
	
}


void Circuit::SetLength(float length)
{
	this->length = length;
}

void Circuit::SetWeather(int weather)
{ 
	this->weather = weather;
}


void Circuit::Race()
{
	for (int i = 0; i < count; i++)
	{
		time[i] = cars[i]->RaceCalculator(length, weather);
	}
	Sort();
}

void Circuit::AddCar(Car* c)
{	
	cars[count++] = c;
}

void Circuit::Sort()
{
	for (int i = 0; i < count - 1; i++)
	{ for(int j=i + 1; j < count; j++)
		if( time[i]>time[j])
		{	
		 
          float aux=time[i];
          time[i]=time[j];
          time[j]=aux;
		  Car* auxx(cars[i]);
		   cars[i] = cars[j];
		   cars[j] = auxx;
		}
	}
}



void Circuit::ShowFinalRanks()
{
	for(int i=0; i<count; i++)
	{
		if(time[i]!=-1)
		   printf("%s a terminat intr-un timp de %f\n",cars[i]->getName(), time[i]);
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	//printf("Masinile care nu au terminat sunt:\n ");
	 for(int i = 0; i<count; i++)
	 {
		 if(time[i] == -1)
		    printf("%s nu a terminat\n", cars[i]->getName());
	 }
}