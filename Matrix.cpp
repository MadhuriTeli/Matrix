#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include"Matrix.hpp"
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
/*
int Matrix :: operator[][](int i, int j)
{
return ptr[i][j];
}

int Matrix :: operator==(Matrix& a)
{

}
*/

void Matrix :: GaussJacobi()
{
	
		//isDiagonallyDominant();
int i, j;
long double x[columns] ,sum =0;

		for(int i=1;i<=rows;i++)
    x[i]=0;

for(i=1;i<=columns;i++)
        {
            sum=0;
            for(j=1;j<=columns;j++)
             {
               if(i!=j)
                  sum=sum+ptr[i][j]*x[j];
              }
            x[i]=(ptr[i][columns+1]-sum)/ptr[i][i];
        }
cout<<x[i];
}
/*
void Matrix :: isDiagonallyDominant( )
{
	//int i ,j ;
	//long double sum = 0;
for(int  i= 0 ; i<rows; i++)
{
	long double  sum =0;
	for(int j=0 ; j<columns; j++)
	
	sum = sum + ptr[i][j];
	sum -= ptr[i][i];

	if(ptr[i][i] > sum)
	{
	AssignValues();               	//cout<<"Matrix is Diagonally Domiant \n";
	}
	else
	{
	MakeMatrixDiagonallyDominant();                   	 //cout<<"Matrix is not Diagonally dominanr \n";
	}
}
}
void Matrix :: MakeMatrixDiagonallyDominant()
{
	for(int i =0 ; i<rows; i++)
	{
		for(int k= i+1; k<rows; k++)

		{
			if(ptr[i][i]<ptr[k][i])
			{
				for(int j=0; j<columns; j++)
				{
				swap(ptr[i][j], ptr[k][i]);
				}
			}
			
		}
	}
	isDiagonallyDominant();
}


*/

void Matrix::PowerMethod()
{
int i, j;
long double  x[columns], c[columns], d=0, temp;
	cout<<"enter xo matrix \n";
	for(i=0; i<rows; i++)
	cin>>x[i];
	 do
    {
        for(i=0;i<rows;i++)
        {
            c[i]=0;
            for( j=0;j<columns;j++)
                c[i]+=ptr[i][j]*x[j];
        }
        for( i=0;i<rows;i++)
            x[i]=c[i];
            
        temp=d;
        d=0;
        
        for(i=0;i<rows;i++)
        {
            if(fabs(x[i])>fabs(d))
                d=x[i];
        }
        for(int i=0;i<rows;i++)
            x[i]/=d;
            
    }while(fabs(d-temp)>0.001);
cout<<"eigen values "<<d<<endl;
cout<<"eigen vectors:";
for(i = 0; i<rows; i++)
{
cout<<x[i];
}
}



void Matrix :: Gaussian()
{

for(int i=0; i<rows; i++)
{
DivideRowByScalar(  i, ptr[i][i]);
if(i<rows-1)
{
RowOperations( i+1);
}
}
                     //cout<<"after triangularization \n";
display();

Backsub();
}

void Matrix :: DivideRowByScalar( int RowNumber,long double pivot)
{

for(int i=0; i<columns; i++)
{
ptr[RowNumber][i]= ptr[RowNumber][i]/pivot;
}
}

void Matrix :: RowOperations(int RowIndex)
{

for(int i=RowIndex; i<rows; i++)
{		
ReduceRow( i, RowIndex);
}
}

void Matrix :: ReduceRow( int i , int RowIndex)
{
long double factor= ptr[i][RowIndex-1];
for(int j=0; j<columns; j++)
{
ptr[i][j]=ptr[i][j] + (-1)*factor*ptr[RowIndex-1][j];
}

//return result;
}

long double Matrix :: Backsub()
{					
long double x[rows];
x[rows-1]= ptr[rows-1][columns-1];
cout<<x[rows-1  ]<<"\n";
for (int i=rows-1;i>=0;i--)               
    {                        
         x[i]=ptr[i][rows];                
        for (int j=i+1;j<columns-1;j++)
            if (j!=i)          
                x[i]=x[i]-ptr[i][j]*x[j];
        x[i]=x[i]/ptr[i][i];           
    }
for (int i=0;i<rows;i++)
        cout<<x[i]<<endl;            // Print the values of x, y,z,....    
    return 0;
}


Matrix Matrix :: addition(Matrix m2)
{
	Matrix result(rows, columns);
	
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			result.ptr[i][j] = this->ptr[i][j] + m2.ptr[i][j];
		}
	}
	return result;
}

Matrix Matrix :: subtraction(Matrix m2)
{
	Matrix result(rows, columns);
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			result.ptr[i][j] = ptr[i][j] - m2.ptr[i][j];
		}
	}
	return result;
}


Matrix Matrix::multiplication(Matrix m2)
{
	Matrix result(rows, m2.columns);
	int i,j,k;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < m2.columns; j++)
		{
			result.ptr[i][j] = 0;
			for (k = 0; k < columns; k++)
			{
				result.ptr[i][j] = result.ptr[i][j] + (ptr[i][k] * m2.ptr[k][j]);
			}
		}
}
return result;
}



