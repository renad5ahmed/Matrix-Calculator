/*
    AUTHOR : Renad Ahmed AbdelBaky / 20190214
*/
#include "matrix.h"
#include <iostream>
#include "MatrixCalculator.h"
using namespace std;
void menu() {
    cout << "Welcome to your Matrix Calculator" << endl << "----------------------------------------" << endl;
    cout << "(1)Matrices Addition" << "\n(2)Matrices Subtraction."<< "\n(3)Matrices Multiplication." << "\n(4)Matrix Transpose." << endl;
}
int main()
{
    menu();
    MatrixCalculator test;
    test.problem();
return 0;
}
