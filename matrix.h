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
        rows1 = 0;
        cols1 = 0;
        rows = nRow;
        cols = nCol;
        tmatrix = new T[rows * cols];
        std::cout << "<matrix>" << " " << rows << "x" << cols << " " << "Matrix has Initialized" << std::endl;
    }
    matrix(unsigned int nSize)
    {
        std::cout << "<matrix> Initializing" << std::endl;
        int size = nSize;
        tmatrix = new T[nSize];
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
                std::cout<< other.tmatrix[row * cols + col]<<" ";
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
    /****************************************operations*****************************************/
    T matrixSum(const matrix& other, const matrix& mat)
    {
        /*******************************************************ADDITION*******************************************/

        static int nRows=other.rows;
        static int nCols=other.cols;
        static int nRows1 = mat.rows;
        static int nCols1 = mat.cols;

        if ((nRows == nRows1) && (nCols == nCols1))
        {
            tmatrix = new T[long(nRows * nCols)];
            for (int row = 0; row < nRows; row++)
            {
                for (int col = 0; col < nCols; col++)
                {
                    tmatrix[row * nCols + col] = other.tmatrix[row * nCols + col]+ mat.tmatrix[row * nCols1 + col];
                }

            }
        }
        else
        {
            std::cout << "<matrixSum> [ERROR]: Matric dimension must match!" << std::endl;
        }
        return  *tmatrix;
    }

    T matrixSub(const matrix& other, const matrix& mat)
    {
        /*******************************************************SUBTRACTION*******************************************/
        static int nRows = other.rows;
        static int nCols = other.cols;
        static int nRows1 = mat.rows;
        static int nCols1 = mat.cols;

        if ((nRows == nRows1) && (nCols == nCols1))
        {
            tmatrix = new T[long(nRows * nCols)];
            for (int row = 0; row < nRows; row++)
            {
                for (int col = 0; col < nCols; col++)
                {
                    tmatrix[row * nCols + col] = other.tmatrix[row * nCols + col] - mat.tmatrix[row * nCols + col];
                }

            }
        }
        else
        {
            std::cout << "<matrixSub> [ERROR]: Matric dimension must match!" << std::endl;
        }
        return  *tmatrix;
    }

    T matrixMul(T num,const matrix& mat)
    {
        static int nRows = mat.rows;
        static int nCols = mat.cols;
        tmatrix = new T[nRows * nCols];
        for (int row = 0; row < nRows; row++)
        {
            for (int col = 0; col < nCols; col++)
            {
                tmatrix[row * nCols + col] = num * mat.tmatrix[row * nCols + col];
            }

        }
        return *tmatrix;
    }
  
private:
    T* tmatrix;
    int rows, cols, rows1, cols1;
};
    