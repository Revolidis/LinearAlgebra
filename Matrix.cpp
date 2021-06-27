// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "matrix.h"

int row =3;
int col = 3;
int row1 = 3;
int col1 = 3;
int main()
{
	matrix <int> obj(row, col);
	matrix <int> obj1(row1,col1);
	matrix <int> obj3(row,col);
	obj1.setElement(obj1,1,0,0);
	obj1.setElement(obj1, 1, 0, 1);
	obj1.setElement(obj1, 1, 0, 2);
	obj1.setElement(obj1, 1, 1, 0);
	obj1.setElement(obj1, 1, 2, 0);
	obj1.setElement(obj1, 1, 1, 1);
	obj1.setElement(obj1, 1, 1, 2);
	obj1.setElement(obj1, 1, 2, 2);
	obj1.setElement(obj1, 1, 2, 1);
	obj1.printMatrix(obj1);
	obj.setElement(obj, 2, 0, 0);
	obj.setElement(obj, 2, 0, 1);
	obj.setElement(obj, 2, 0, 2);
	obj.setElement(obj, 2, 1, 0);
	obj.setElement(obj, 2, 2, 0);
	obj.setElement(obj, 2, 1, 1);
	obj.setElement(obj, 2, 1, 2);
	obj.setElement(obj, 2, 2, 2);
	obj.setElement(obj, 2, 2, 1);
	obj.printMatrix(obj);
	
	
	int x = obj3.matrixMul(6, obj);
	obj3.printMatrix(obj3);
	std::cin.get();
}
