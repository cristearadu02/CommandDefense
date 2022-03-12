#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
	Math obj;
	int x, y, z;
	float a, b, c;
	
	cout << "x,y,z = " << endl;
	cin >> x >> y >> z;
	cout << "a,b,c = " << endl;
	cin >> a >> b >> c;

	printf("X + Y = %d\n",obj.Add(x, y));
	printf("X + Y + Z = %d\n", obj.Add(x, y, z));
	printf("a + b = %f\n",obj.Add(a, b));
	printf("a + b + c = %f\n", obj.Add(a, b, c));
	printf("Variadic parameters => %d\n",obj.Add(5, 1, 2, 3, 4, 5));
	printf("X * Y = %d\n", obj.Mul(x, y));
	printf("X * Y * Z = %d\n", obj.Mul(x, y, z));
	printf("a * b = %f\n", obj.Mul(a, b));
	printf("a * b * c = %f\n", obj.Mul(a, b, c));
	printf("S + T = %s\n", obj.Add("Vasile","Popescu"));

	return 0;
}