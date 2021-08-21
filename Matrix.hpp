
#include<iostream>
using namespace std;
class Matrix
{
private:int rows, columns;
long double **ptr;
public: Matrix();
	Matrix(int, int);
	Matrix(const Matrix &m);
	int acceptMatrix(char *);
	//int write(char *);
	void display();
	void Gaussian();
	void DivideRowByScalar(int RowNumber, long double);
	void RowOperations(int RowIndex);
	void ReduceRow( int i , int RowIndex);
	long double Backsub();
    void GaussJacobi();
	void PowerMethod();
	//void isDiagonallyDominant();
    //void MakeMatrixDiagonallyDominant();
	//void AssignValues();
	//long double iteration();
	Matrix addition(Matrix );
	Matrix subtraction(Matrix );
	Matrix multiplication(Matrix );

	//int operator[][](int , int );
	//bool operator==(Matrix&);
	
};

