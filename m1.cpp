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
};

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

int Matrix::acceptMatrix(char *filename) 
{
	ifstream file;
	int i, j;

	file.open(filename);	
	
		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < columns; j++)
			{
				if (!file.eof())	//handling incomplete matrix
				{
					file >> ptr[i][j];
				}
			}
		}
	
		file.close();
		return 1;
}







int main()
{
    char fname[20];
	int res;
	Matrix l(49, 49);
	Matrix r(49, 1);


    strcpy(fname, "49l.txt");
    res =l.acceptMatrix(fname);
    strcpy(fname, "49r.txt");
    res = r.accpetMatrix(fname);
}

