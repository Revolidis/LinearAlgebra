#pragma once
#include <iostream>
#include <array>

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
    T getElement(unsigned row, unsigned int col);

    int m_nRows, m_nCol, nElements;
    //destructor
    ~matrixClass();
private:
    int getLinInd(unsigned int row, unsigned int col);
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
    matrixClass::m_nRows = nRow;
    matrixClass::m_nCol = nCol;
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

template<typename T>
T matrixClass<T>::getElement(unsigned row, unsigned int col)
{
    int linearIndex = getLinInd(row, col); //Gets linear index of element
    if (linearIndex >=0)
    {
        return matrix[linearIndex]; //returns element
    }
    else
    {
        std::cout << "(getElement) [ERROR]: Unable to get element" << std::endl;
        return 0.0;
    }
}

/**************************************************************************************
**************************Private Methods**********************************************/
template<typename T>
int matrixClass<T>::getLinInd(unsigned int row, unsigned int col)
//This methods returns the linear index of an element 
{ 
    if ((row >= 0) && (row < m_nRows) && (col >= 0) && (col < m_nCol))
    {
        return(row * m_nCol + col); //linear index
    }
    else
    {
        if (row > m_nRows) 
        {
            std::cout << "(getLinInd) [ERROR]: Row cannot exceed matrix dimensions." << std::endl;
        }
        if (col > m_nCol) 
        {
            std::cout << "(getLinInd) [ERROR]: Collumn cannot exceed matrix dimensions." << std::endl;
        }
        return -1;
    } 
}
//Destructor
template<typename T>
matrixClass<T>::~matrixClass()
{
    delete[] matrix;
}


