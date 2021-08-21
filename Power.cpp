#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
int i , j ,rows, columns;
long double d=0, temp,   matrix[3][3], X[rows], c[rows];
cout<<"enter the no of rows and columns of matrix";
cin>>rows >>columns;
cout<<"rows ="<<rows<<"columns"<<columns;
cout<<"enter the elements of matrix";
for(i=0; i<rows; i++)
{
    for(j=0; j<columns; j++)
    {
        cin>>matrix[i][j];
    }
}
cout<<"enter the X0 matrix";
for(i=0; i<rows; i++)
{
    cin>>X[i];
}
do
    {
        for(i=0;i<rows;i++)
        {
            c[i]=0;
            for( j=0;j<columns;j++)
                c[i]+=matrix[i][j]*X[j];
        }
        for( i=0;i<rows;i++)
           X[i]=c[i];
            
        temp=d;
        d=0;
        
        for(i=0;i<rows;i++)
        {
            if(fabs(X[i])>fabs(d))
                d=X[i];
        }
        for(int i=0;i<rows;i++)
            X[i]/=d;
            
    }while(fabs(d-temp)>0.001);
cout<<"eigen values "<<d<<endl;
cout<<"eigen vectors:";
for(i = 0; i<rows; i++)
{
cout<<X[i]<<endl;
}
}