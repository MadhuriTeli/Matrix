#include<iostream>
#include<fstream>
using namespace std;

Matrix::Matrix()
{
}

Matrix::Matrix(int r , int c)
{
	rows = r;
	columns = c;
	ptr = new long double*[rows];
	for (int i = 0; i < rows; i++)
	{
		ptr[i] = new long double[columns];
	}
}

Matrix::Matrix(const Matrix &m)
{
	int i, j;
	rows = m.rows;
	columns = m.columns;
	
	ptr = new long double*[rows];
	for (i = 0; i < rows; i++)
	{
		ptr[i] = new long double[columns];
	}

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			ptr[i][j] = m.ptr[i][j];
		}
	}
}
void Matrix::display()
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix:: Gaussian()
{
for(int i =0; i<rows; i++)
{
DivideByRowScalar(i, ptr[i][j]);
{
if(i<row)
RowOpearation(i+1);
}
display();
}


void Matrix :: DivideByRowScalar(int RowNumber, long double pivot)
{
for(int j = 0; j<columns; j++)
{
ptr[RowNumber][j] = ptr[RowNumber][j]/ptr[RowNumber][Rownumber];
}
}

void Matrix :: RowOperation(int RowIndex)
{
for(int i= RowIndex; i<RowIndex; i++)
{
ReduceRow(i, RowIndex);
}
}
int Matrix :: ReduceRow(int i, int RowIndex)
{
long double factor = ptr[i][RowIndex-1];
for(int j=0; j<columns; j++)
{
ptr[i][j]=ptr[i][j]+(-1)*factor*[RowIndex-1][j];
}
return ptr[i][j];
}

