#include "Canvas.h"
#include <cmath>
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height)
{
	n = width;
	m = height;
	 mat = new char* [width];
	for (int i = 0; i < width; ++i)
		mat[i] = new char[height];
	Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	Clear();
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if ((pow(i - x, 2) + pow(j - y, 2) >= ray * (ray - 1)) && (pow(i - x, 2) + pow(j - y, 2) <= ray * (ray + 1)))
				mat[i][j] = ch;		
	Print();
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	Clear();
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray) || (pow(i - x, 2) + pow(j - y, 2) >= ray * (ray - 1)) && (pow(i - x, 2) + pow(j - y, 2) <= ray * (ray + 1)))
				mat[i][j] = ch;
	Print();
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	Clear();
	int i, j;
	
	for (i = top; i <= bottom; i++)
	{
		mat[i][left] = mat[i][right] = ch;
	}

	for (j = left; j < right; j++)
	{
		mat[top][j] = ch;
		mat[bottom][j] = ch;
	}
	Print();

}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	Clear();
	int i, j;
	for (i = top; i < bottom; i++)
		for (j = left; j < right; j++)
			mat[i][j] = ch;
	Print();
}

void Canvas::SetPoint(int x, int y, char ch)
{
	Clear();
	mat[x][y] = ch;
	Print();
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	Clear();
	int dx = x2 - x1;
	int dy = y2 - y1;
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int D = (2 * dy) - dx;
	int y = y1;
	int i;
	for (i = x1; i < x2; i++)
	{
		mat[i][y] = ch;
		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2 * dy;
	}
	Print();
}

void Canvas::Print()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << mat[i][j] << ' ';
		cout << endl;
	}
}

void Canvas::Clear()
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			mat[i][j] = ' ';
}
