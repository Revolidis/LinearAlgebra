// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "matrix.h"

int row = 1;
int col = 1;
int row1 = 3;
int col1 = 3;
int main()
{
	matrix <int> obj(row, col);
	matrix <int> obj1(row1,col1);
	obj1.setElement(obj1,0,0,0);
	obj1.setElement(obj1, 0, 0, 1);
	obj1.setElement(obj1, 0, 0, 2);
	obj.setElement(obj, 5, 0, 0);
	obj1.setElement(obj1, 0, 1, 0);
	obj1.setElement(obj1, 0, 2, 0);
	obj1.setElement(obj1, 0, 1, 1);
	obj1.setElement(obj1, 0, 1, 2);
	obj1.setElement(obj1, 0, 2, 2);
	obj1.setElement(obj1, 0, 2, 1);
	obj.printMatrix(obj);
	obj.printMatrix(obj1);
	std::cin.get();
}
