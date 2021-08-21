#include<iostream>
#include<string.h>
#include"Matrix.hpp"
using namespace std;

int main()
{

	char fname[20];
	int res;
	Matrix m1(4, 4);
	Matrix m2(4, 4);
	Matrix GE(4, 5);
	Matrix GJ(3 ,4);
	Matrix P(3, 3);

	strcpy(fname, "matrix1.txt");
	res = m1.acceptMatrix(fname);
	m1.display();
	strcpy(fname, "matrix2.txt");
	res= m2.acceptMatrix(fname);
	m2.display();

 	
	Matrix m3 = m1.addition(m2);
	cout << "Addition: " << endl;
	m3.display();
    
	Matrix m4 = m1.subtraction(m2);
	cout << "Substraction: " << endl;
	m4.display();

	Matrix m5 = m1.multiplication(m2);
	cout << "Multiplication: " << endl;
	m5.display();	

	strcpy(fname, "matrix3.txt");
	res= GE.acceptMatrix(fname);
	GE.display();
/*
	strcpy(fname, "49l.txt");
	res = l.acceptMatrix(fname);
*/
	GE.Gaussian();

	strcpy(fname, "matrix4.txt");
	res =GJ.acceptMatrix(fname);
      GJ.display();
	  GJ.GaussJacobi();

	  strcpy(fname, "matrix5.txt");
	res= P.acceptMatrix(fname);
	P.display();
	P.PowerMethod();


	//strcpy(fname, "49r.txt");
	//res =GJr.acceptMatrix(fname);
	

	
}

