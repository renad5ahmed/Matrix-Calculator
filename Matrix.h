/*
    AUTHOR : Renad Ahmed AbdelBaky / 20190214
*/
#pragma once
#include <iostream>
using namespace std;
template <class T>
class matrix
{
    T** mat;
    int row, col;
public:
    matrix();
    matrix(int row, int col, T input[]);//Constructors
    matrix(int row, int col);

    int getrow();//getters
    int getcol();

    matrix<T> operator+(matrix<T>& secondMatrix);//4 functions to perform 4 different operations
    matrix<T> operator-(matrix<T>& secondMatrix);
    matrix<T> operator*(matrix<T>& secondMatrix);
    void transpose(matrix<T>& transposedMatrix);

    template<class T2>
    friend ostream& operator<< (ostream& out, const matrix<T2>& matrixOutput);//insertion
    template<class T2>
    friend istream& operator>> (istream& in, matrix<T2>& matrixInput);//extraction

    ~matrix();
};

template<class T>
inline matrix<T>::matrix()
{
}

template<class T>
inline matrix<T>::matrix(int row, int col, T input[])
{
    this->row = row;
    this->col = col;
    mat = new T * [row];

    for (int i = 0; i < row; i++)
        mat[i] = new T[col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat[i][j] = input[i * col + j];
}

template<class T>
inline int matrix<T>::getrow()
{
    return row;
}

template<class T>
inline int matrix<T>::getcol()
{
    return col;
}

template <class T>
matrix<T>::matrix(int row, int col)
{
    this->row = row;
    this->col = col;
    mat = new T * [row];
    for (int i = 0; i < row; i++)
        mat[i] = new T[col];
}

template<class T>
inline matrix<T> matrix<T>::operator+(matrix<T>& secondMatrix)
{
    matrix<T> sum(row, col);				//setting number of rows and cols in object mat
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            sum.mat[i][j] = 0;                // initialize all values equal 0

    for (int i = 0; i < sum.row; i++)
    {
        for (int j = 0; j < sum.col; j++)
        {
            sum.mat[i][j] = (mat[i][j] + secondMatrix.mat[i][j]);    //get the sum(all values mat1+ all values in mat2) and put it in mat
        }
    }
    return sum;
}

template<class T>
inline matrix<T> matrix<T>::operator-(matrix<T>& secondMatrix)
{
    matrix<T> diff(row, col);				//setting number of rows and cols in object mat
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            diff.mat[i][j] = 0;                // initialize all values equal 0

    for (int i = 0; i < diff.row; i++)
    {
        for (int j = 0; j < diff.col; j++)
        {
            diff.mat[i][j] = (mat[i][j] - secondMatrix.mat[i][j]);    //get the sum(all values mat1+ all values in mat2) and put it in mat
        }
    }
    return diff;
}

template<class T>
inline matrix<T> matrix<T>::operator*(matrix<T>& secondMatrix)
{
    matrix<T> multiply(row, secondMatrix.col);				//setting number of rows and cols in object mat
    for (int i = 0; i < row; i++)
        for (int j = 0; j < secondMatrix.col; j++)
            multiply.mat[i][j] = 0;                // initialize all values equal 0

    for (int i = 0; i < row; i++)
        for (int j = 0; j < secondMatrix.col; j++)
            for (int k = 0; k < col; k++)
            {
                multiply.mat[i][j] +=( mat[i][k] * secondMatrix.mat[k][j]);   //get the production
            }
    return multiply;
}

template<class T>
inline void matrix<T>::transpose(matrix<T>& transposedMatrix)
{

    matrix<T> mat1(transposedMatrix.col, transposedMatrix.row);

    for (int i = 0; i < transposedMatrix.row; i++)
        for (int j = 0; j < transposedMatrix.col; j++)
            mat1.mat[j][i] = transposedMatrix.mat[i][j];     //put all values in the rotated matrix

    for (int i = 0; i < transposedMatrix.col; i++) {
        for (int j = 0; j < transposedMatrix.row; j++) {
            cout << mat1.mat[i][j] << " ";
        }
        cout << endl;
    }
}


template <class T2>
ostream& operator<<(ostream& out, const matrix<T2>& matrixOutput)
{

    for (int i = 0; i < matrixOutput.row; i++)
    {
        out << endl;
        for (int j = 0; j < matrixOutput.col; j++)
            out << matrixOutput.mat[i][j] << "  ";
    }
    out << endl << endl;

    return out;
}

template <class T2>
istream& operator>>(istream& in, matrix<T2>& matrixInput)
{
    cout << "Enter matrix dimensions:" << endl;
    in >> matrixInput.row >> matrixInput.col;  // Take rows and cols from the user

    matrixInput.mat = new T2 * [matrixInput.row];

    for (int i = 0; i < matrixInput.row; i++)
        matrixInput.mat[i] = new T2[matrixInput.col];

    for (int i = 0; i < matrixInput.row; i++)
        for (int j = 0; j < matrixInput.col; j++)
            in >> matrixInput.mat[i][j]; // Enter Elements one by one
    return in;
}

template<class T>
inline matrix<T>::~matrix()
{
    /*
        for (int i = 0; i < row; i++) {
            delete[] mat[i];
        }
        delete[] mat;
        mat = NULL;*/
}
