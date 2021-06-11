/*
    AUTHOR : Renad Ahmed AbdelBaky / 20190214
*/
#include "MatrixCalculator.h"
#include "Matrix.h"
#include<iostream>
using namespace std;
void MatrixCalculator::problem()
{

    int choice,type;
    cin >> choice;
    cout<<"Enter the type of the matrix:"<<endl<<"1-Integer"<<endl<<"2-Decimal"<<endl;
    cin>>type;
    switch (choice)
    {
    case (1):
        if(type==1){
        matrix <int>mat1, mat2;
        cout << "Enter First Matrix : " << endl;
        cin >> mat1;
        cout << "Enter Second Matrix : " << endl;
        cin >> mat2;
        if (mat2.getrow() == mat1.getrow() && mat2.getcol() == mat1.getcol()) {//checking sizes
            cout << "Matrix 1 + Matrix 2 = \n" << (mat1 + mat2);
        }
        else    cout << "Invalid dimensions";
        break;
        }
        else if(type==2){

        matrix <double>mat1, mat2;
        cout << "Enter First Matrix : " << endl;
        cin >> mat1;
        cout << "Enter Second Matrix : " << endl;
        cin >> mat2;
        if (mat2.getrow() == mat1.getrow() && mat2.getcol() == mat1.getcol()) {//checking sizes
            cout << "Matrix 1 + Matrix 2 = \n" << (mat1 + mat2);
        }
        else    cout << "Invalid dimensions";
        break;
        }


    case (2):

        if(type=1){
        matrix <int>mat1, mat2;
        cout << "Enter First Matrix : " << endl;
        cin >> mat1;
        cout << "Enter Second Matrix : " << endl;
        cin >> mat2;
        if (mat2.getrow() == mat1.getrow() && mat2.getcol() == mat1.getcol()) {//checking sizes
            cout << "Matrix 1 - Matrix 2 = \n" << (mat1 - mat2);
        }
        else    cout << "Invalid dimensions";
        break;
        }

        if(type=2){
        matrix <double>mat1, mat2;
        cout << "Enter First Matrix : " << endl;
        cin >> mat1;
        cout << "Enter Second Matrix : " << endl;
        cin >> mat2;
        if (mat2.getrow() == mat1.getrow() && mat2.getcol() == mat1.getcol()) {//checking sizes
            cout << "Matrix 1 - Matrix 2 = \n" << (mat1 - mat2);
        }
        else    cout << "Invalid dimensions";
        break;
        }


    case (3):

        if(type ==1){
        matrix <int>mat1, mat2;
        cout << "Enter First Matrix : " << endl;
        cin >> mat1;
        cout << "Enter Second Matrix : " << endl;
        cin >> mat2;
        if (mat2.getcol() == mat1.getrow()) {

            cout << "Matrix 1 * Matrix 2 =\n " << (mat1 * mat2);
        }
        else    cout << "Invalid dimensions";
        break;
        }
        if(type ==2){
        matrix <double>mat1, mat2;
        cout << "Enter First Matrix : " << endl;
        cin >> mat1;
        cout << "Enter Second Matrix : " << endl;
        cin >> mat2;
        if (mat2.getcol() == mat1.getrow()) {

            cout << "Matrix 1 * Matrix 2 =\n " << (mat1 * mat2);
        }
        else    cout << "Invalid dimensions";
        break;
        }
    case (4):
        if (type == 1)
        {
        matrix <int>mat1;
        cout << "Enter Your Matrix : " << endl;
        cin >> mat1;
        cout << "transposed Matrix : " << endl;
        mat1.transpose(mat1);
        }
        else if (type == 2)
        {
        matrix <double>mat1;
        cout << "Enter Your Matrix : " << endl;
        cin >> mat1;
        cout << "transposed Matrix : " << endl;
        mat1.transpose(mat1);
        }
    }
}
