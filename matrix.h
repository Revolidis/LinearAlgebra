#pragma once
#include <iostream>
#include <array>

template<typename T>
class matrix
{
public:
    /**************************************************constructors*******************************************************/
    matrix()
    {
        std::cout << "<matrix> Creating 1x1 matrix" << std::endl;
        tmatrix = new int[1];
    }

    matrix(unsigned int nRow, unsigned int nCol)
    {
        std::cout << "<matrix> Initializing" << std::endl;
        rows = nRow;
        cols = nCol;
        tmatrix = new T[rows * cols];
        std::cout << "<matrix>" << " " << rows << "x" << cols << " " << "Matrix has Initialized" << std::endl;
    }
    matrix(unsigned int nSize)
    {
        std::cout << "<matrix> Initializing" << std::endl;
        int size = nSize;
        tmatrix = new T[rows * cols];
        std::cout << "<matrix> <<" << size << "x" << size << " Matrix has Initialized" << std::endl;
    }

    matrix(const matrix& other)
    {
        rows = other.rows;
        cols = other.cols;

        T* matrix = new T[rows * cols];
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                matrix[row * cols + col] = other.tmatrix[row * cols + col];
            }

        }
    }
    
    /***********************************Print method***********************************/

    void printMatrix(const matrix& other)
    {
        rows = other.rows;
        cols = other.cols;
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                std::cout<< other.tmatrix[row * cols + col];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
    }

    /***********************************Element Access method***********************************/
    T getElement(const matrix& other, unsigned int row, unsigned int col)
    {
        cols = other.cols;
        T element = other.tmatrix[row * cols + col];
        return element;
    }

    T* setElement(const matrix& other, T element, unsigned int row, unsigned int col)
    {
        cols = other.cols;
        tmatrix[row * cols + col] = element;
        return tmatrix;
    }

private:
    T* tmatrix;
    int rows, cols;
};
    