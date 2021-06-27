// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "matrix.h"

int row =3;
int col = 3;
int row1 = 3;
int col1 = 3;
int main()
{
	matrix <double> obj(row, col);
	matrix <double> obj1(row1,col1);
	matrix <double> obj3;
	obj1.setElement(obj1,1.1,0,0);
	obj1.setElement(obj1, 1.2, 0, 1);
	obj1.setElement(obj1, 1.3, 0, 2);
	obj1.setElement(obj1, 1.4, 1, 0);
	obj1.setElement(obj1, 1.5, 2, 0);
	obj1.setElement(obj1, 1.6, 1, 1);
	obj1.setElement(obj1, 1.7, 1, 2);
	obj1.setElement(obj1, 1.8, 2, 2);
	obj1.setElement(obj1, 1.9, 2, 1);
	obj1.printMatrix(obj1);
	obj.setElement(obj, 2.0, 0, 0);
	obj.setElement(obj, 2.0, 0, 1);
	obj.setElement(obj, 2.0, 0, 2);
	obj.setElement(obj, 2.0, 1, 0);
	obj.setElement(obj, 2.0, 2, 0);
	obj.setElement(obj, 2.0, 1, 1);
	obj.setElement(obj, 2.0, 1, 2);
	obj.setElement(obj, 2.0, 2, 2);
	obj.setElement(obj, 2.0, 2, 1);
	obj.printMatrix(obj);
	
	
	double x = obj3.matrixMul(obj1, obj);
	obj.printMatrix(obj3);
	std::cin.get();
}
