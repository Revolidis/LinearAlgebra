#pragma once
#include <iostream>
#include<array>

template<typename T>
class matrixClass
{
public:
    //constructors
    matrixClass()
    {
        std::cout << "Class Loaded" << std::endl << std::endl;
    }
    //Methods
    int* CreateM(unsigned int nRow,unsigned int nCol, T num);

   
    //destructor
    ~matrixClass();
private:
    int* matrix;
};

//Methods
template<typename T>
int* matrixClass<T>::CreateM(unsigned int nRow, unsigned int nCol, T num)
{
    /*this will eventually return a pointer to the (first element of the array by default)
    to be used in a function in the source code*/
    //memory allocation
    matrix = new int[nRow * nCol];
    for (unsigned int y = 0; y < nRow; y++)
    {
        for (unsigned int x = 0; x < nCol; x++)
        {
            matrix[x + y * nRow] = num;   //data loop
            num += 1;
        }
    }

    //print fun
    for (unsigned int i = 0; i < nRow; i++)
    {
        for (unsigned int j = 0; j < nCol; j++)
        {
            std::cout << matrix[j + i * nRow] << "  ";
        }
        std::cout << std::endl;
    }
    return matrix;
}

//Destructor
template<typename T>
matrixClass<T>::~matrixClass()
{
    delete[] matrix;
}


