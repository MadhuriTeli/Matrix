#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
	


int acceptMatrix(char *filename) 
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
int AgumentedMatrix()

 int i,j;
    for ( i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
           cout ptr[i][j]
        }cout<<ptr[i][0]);
    }
 
    
    }
	display
    return 0;
}
int main()
{
	char fname[20];
	int res;
	Matrix m1(49, 49);
	Matrix m2(49, 1);
	strcpy(fname, "49l.txt");
	res =GJl.acceptMatrix(fname);

    
	strcpy(fname, "49r.txt");
	res =GJr.acceptMatrix(fname);
}