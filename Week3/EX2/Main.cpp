#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
	Canvas obj(20,20);
	obj.DrawLine(2,3,5,7,'r');
	printf("\n-------------------\n\n");
	obj.DrawCircle(10,10,3,'x');
	printf("\n-------------------\n\n");
	obj.FillCircle(10,10,4,'x');
	printf("\n-------------------\n\n");
	obj.DrawRect(2,3,10,12,'a');
	printf("\n-------------------\n\n");
	obj.FillRect(2, 3, 10, 12, 'a');
	printf("\n-------------------\n\n");
	obj.SetPoint(5, 5, 'y');

	return 0;
}