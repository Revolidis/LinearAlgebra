#pragma once
#include <iostream>
#include <array>

template<typename T>
class matrixClass
{
public:
    //constructors / Initialisation
    matrixClass();
   
    //Create and print Matrix Methods
    int* CreateM(unsigned int nRow,unsigned int nCol, T num);
    void printMat(T* mat);
    
    //Access Element Methods
    T getElement(unsigned row, unsigned int col);
    int* setElement(unsigned row, unsigned int col,T el);
    int getRows();
    int getCol();

    
    //destructor
    ~matrixClass();
private:
    int getLinInd(unsigned int row, unsigned int col);
private:
    int* matrix;
    unsigned int m_nRows, m_nCol, nElements;
};
/***************************************************************************************************
******************************************Constructor**********************************************/
template<typename T>
matrixClass<T>::matrixClass()
{
    std::cout << "Linear Algebra Class Loaded" << std::endl << std::endl;
    matrix = new int[1];
    matrix[0] = 0;
    std::cout << "Matrix Initialized" << std::endl << "A = [" << matrix[0] << "]" << std::endl;
}

/**************************************************************************************************
********************************Matrix Creation and print methods**********************************/
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
    return matrix;
}
template<typename T>
void matrixClass<T>::printMat(T* mat)
{
    //print fun
    for (unsigned int row = 0; row < m_nRows; row++)
    {
        for (unsigned int col = 0; col < m_nCol; col++)
        {
            std::cout << mat[col + row * m_nCol] << "  ";
        }
        std::cout << std::endl;
    }
}
/**************************************************************************************
***********************Access Element Methods******************************************/

template<typename T>
T matrixClass<T>::getElement(unsigned row, unsigned int col) //finds and prints an element
{
    int linearIndex = getLinInd(row, col); //Gets linear index of element
    if (linearIndex >=0)
    {
        return matrix[linearIndex]; //returns element
    }
    else
    {
        std::cout << "(getElement) [ERROR]: Unable to get element" << std::endl;
        return 0;
    }
}
template <typename T>
int* matrixClass<T>::setElement(unsigned row, unsigned int col, T el)
{
    int linearIndex = getLinInd(row, col);
        if (linearIndex >= 0)
            matrix[linearIndex] = el;
            else
            std::cout << "<setElement> [ERROR]: Unable to change element." <<std::endl;
        return matrix;
}

template<typename T>
int matrixClass<T>::getRows()
{
    return m_nRows;
}

template<typename T>
int matrixClass<T>::getCol()
{
    return m_nCol;
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
        if (row >= m_nRows)
        {
            std::cout << "(getLinInd) [ERROR]: Row cannot exceed matrix dimensions." << std::endl;
        }
        if (col >= m_nCol) 
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


