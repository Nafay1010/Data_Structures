#include<iostream>
using namespace std;


//****************Q1**********************

//int main()
//{
//	int a, b;
//	int *ptrA, *ptrB;
//	
//	cout<<"Enter A: ";
//	cin>>a;
//	cout<<"Enter B: ";
//	cin>>b;
//	
//	ptrA=&a;
//	ptrB=&b;
//	
//	cout<<"Value of PTRA: "<<*ptrA<<endl;
//	cout<<"Value of PTRB: "<<*ptrB<<endl;
//}


//****************Q2**********************


//int main()
//{
//	int *val=new int;
//	
//	cout<<"Enter value: ";
//	cin>>*val;
//	
//	cout<<"VALUE IS "<<*val<<endl;
//	
//	delete val;
//	
//}


//****************Q3**********************

//int main()
//{
//	int size;
//	cout<<"ENTER SIZE OF ARRAY: ";
//	cin>>size;
//	char *C=new char[size];
//	
//	cout<<"-------------INPUT OF ARRAY-------------"<<endl;
//	
//	for(int i=0;i<size;i++)
//	{
//		cout<<"ENTER VALUE FOR C["<<i<<"]: ";
//		cin>>C[i];
//	}
//	
//	cout<<"-------------OUTPUT OF ARRAY-------------"<<endl;
//	
//	for(int i=0;i<size;i++)
//	{
//		cout<<"VALUE OF C["<<i<<"]: ";
//		cout<<C[i]<<endl;
//	}
//
//	delete[] C;
//}


//****************Q4**********************

//void output(int **A, int R, int C)
//{
//	cout<<"-------------OUTPUT OF ARRAY-------------"<<endl;
//	
//	for(int i=0;i<R;i++)
//	{
//		for(int j=0; j<C; j++)
//		{
//		cout<<"VALUE OF  I["<<i<<"]["<<j<<"]: ";
//		cout<<A[i][j]<<endl;
//		}
//	}
//}
//
//int main()
//{
//	int row, col;
//	cout<<"ENTER ROW OF ARRAY: ";
//	cin>>row;
//	cout<<"ENTER COLUMN OF ARRAY: ";
//	cin>>col;
//	int** I=new int*[row];
//	
//	for(int i=0;i<row;i++)
//	{
//		I[i]=new int[col];
//	}
//	
//	cout<<"-------------INPUT OF ARRAY-------------"<<endl;
//	
//	for(int i=0;i<row;i++)
//	{
//		for(int j=0;j<col;j++)
//		{
//		cout<<"ENTER VALUE FOR I["<<i<<"]["<<j<<"]: ";
//		cin>>I[i][j];
//		}
//	
//	}
//	
//	output(I, row, col);
//	
//	delete[] I;
//}
