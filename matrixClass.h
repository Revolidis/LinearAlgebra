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
    //Create Matrix Methods
    int* CreateM(unsigned int nRow,unsigned int nCol, T num);

    //Access Element Methods
    

   
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
    for (unsigned int row = 0; row < nRow; row++)
    {
        for (unsigned int col = 0; col < nCol; col++)
        {
            matrix[col + row * nCol] = num;   //data loop
            num += 1;
        }
    }

    //print fun
    for (unsigned int row = 0; row < nRow; row++)
    {
        for (unsigned int col = 0; col < nCol; col++)
        {
            std::cout << matrix[col + row * nCol] << "  ";
        }
        std::cout << std::endl;
    }
    return matrix;
}


/**************************************************************************************
***********************Access Element Methods******************************************/


//Destructor
template<typename T>
matrixClass<T>::~matrixClass()
{
    delete[] matrix;
}


