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

    }

    matrix(unsigned int nRow, unsigned int nCol)
    {
        std::cout << "<matrix> Initializing" << std::endl;
        rows = nCol;
        cols = nRow;
        int size = rows * cols;
        tmatrix = new T[size];
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

    void printMatrix(const matrix& mat)
    {

        const int prows = mat.rows;
        const int pcols = mat.cols;
       
        if ((prows != 0) && (pcols != 0))
        {
            for (int row = 0; row < prows; row++)
            {
                for (int col = 0; col < pcols; col++)
                {
                   
                    std::cout << mat.tmatrix[row * pcols + col] << " ";
                }
                std::cout << std::endl;
            }
           
        }
    
        else
        {
            std::cout << "<printMatrix>[ERROR]: NULL" << std::endl << std::endl;
        }
    std::cout << std::endl;


}

    /***********************************Element Access method***********************************/
    T getElement(const matrix& mat, unsigned int row, unsigned int col)
    {
        cols = mat.cols;
        T element = mat.tmatrix[row * cols + col];
        return element;
    }

    T* setElement(const matrix& mat, T element, unsigned int row, unsigned int col)
    {
        cols = mat.cols;
        tmatrix[row * cols + col] = element;
        return tmatrix;
    }
    /****************************************operations*****************************************/
    T matrixSum(const matrix& mat1, const matrix& mat2)
    {
        /*******************************************************ADDITION*******************************************/

        static int sRows=mat1.rows;
        static int sCols=mat1.cols;
        static int sRows1 = mat2.rows;
        static int sCols1 = mat2.cols;

        if ((sRows == sRows1) && (sCols == sCols1))
        {
            tmatrix = new T[long(sRows * sCols)];
            for (int row = 0; row < sRows; row++)
            {
                for (int col = 0; col < sCols; col++)
                {
                    tmatrix[row * sCols + col] = mat1.tmatrix[row * sCols + col]+ mat2.tmatrix[row * sCols1 + col];
                }

            }
        }
        else
        {
            std::cout << "<matrixSum> [ERROR]: Matric dimension must match!" << std::endl;
        }
        return  *tmatrix;
    }

    T matrixSub(const matrix& mat1, const matrix& mat2)
    {
        /*******************************************************SUBTRACTION*******************************************/
        static int bRows = mat1.rows;
        static int bCols = mat1.cols;
        static int bRows1 = mat2.rows;
        static int bCols1 = mat2.cols;

        if ((bRows == bRows1) && (bCols == bCols1))
        {
            tmatrix = new T[long(bRows * bCols)];
            for (int row = 0; row < bRows; row++)
            {
                for (int col = 0; col < bCols; col++)
                {
                    tmatrix[row * bCols + col] = mat1.tmatrix[row * bCols + col] - mat2.tmatrix[row * bCols + col];
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
        static int mnRows = mat.rows;
        static int mnCols = mat.cols;
        tmatrix = new T[mnRows * mnCols];
        for (int row = 0; row < mnRows; row++)
        {
            for (int col = 0; col < mnCols; col++)
            {
                tmatrix[row * mnCols + col] = num * mat.tmatrix[row * mnCols + col];
            }

        }
        return *tmatrix;
    }
    
    T matrixMul(matrix& mat1, matrix& mat2)
    {
        static int nRows = mat1.rows;
        static int nCols = mat1.cols;
        static int nRows1 = mat2.rows;
        static int nCols1 = mat2.cols;
        rows = nRows1;
        cols = nCols;
        int size = rows * cols;
        if (nCols = nRows1)
        {
            tmatrix = new T[size];
            for (int mat1row = 0; mat1row < rows; mat1row++)
            {
                for (int mat2col = 0; mat2col < cols; mat2col++)
                {
                    T sum = 0;
                    for (int mat1col = 0; mat1col < nCols1; mat1col++)
                    {
                        int mat1LinearIndex = (mat1row * nCols + mat1col);
                        int mat2LinearIndex = (mat1col * nCols1 + mat1col);
                        sum += (mat1.tmatrix[mat1LinearIndex]) * (mat2.tmatrix[mat2LinearIndex]);;
                    }

                    tmatrix[mat1row * cols + mat2col] = sum;
                }

            }

            return *tmatrix;
           
        }
        else
        {
            std::cout << "<matrixMul>[ERROR]: Rows of 1st matrix != Columns of 2nd Matrix" << std::endl << std::endl;
            return 0;
        }
        
        
    }
private:
    T* tmatrix;
    int rows, cols;
};
    