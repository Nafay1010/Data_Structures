#include<iostream>
using namespace std;

int Precursion(string a, int s)
{
	if(s==a.length())
	{
		return s;	
	}
	cout<<a[s]<<endl;
	Precursion(a,s+1);
	
}

int Nrecursion(string a, int s)
{
	if(s==a.length())
	{
	//	cout<<a[s]<<endl;
		return s;	
	}

	Nrecursion(a,s+1);
	cout<<a[s]<<endl;
}


int factorial(int n)
{
	if(n==1)
	{
		return 1;		
	}	
	
	return n*factorial(n-1);
}


int main()
{
	//=================POINTERS======================
//	int x=10;
////	cout<<"Address of X: "<<&x<<endl;
////	cout<<"Value stored at that address: "<<x<<endl;
//	
////	cout<<endl;
//	
//	int *ptr=&x;//single pointer, used for pointing at variables
//	cout<<"Value pointed by ptr: "<<*ptr<<endl;
//	cout<<"Address stored in ptr: "<<ptr<<endl;
//	cout<<"Address of ptr: "<<&ptr<<endl;
//	
//	cout<<endl;
//	
//	int **ptr2=&ptr;//double pointer, used to point at pointers
//	cout<<"Value pointed by ptr2: "<<**ptr2<<endl;//prints the value stored at ptr(ptr2 points to the address of ptr)
//	cout<<"Address stored in ptr2: "<<ptr2<<endl;//prints the address stored at ptr2
//	cout<<"Address of ptr2: "<<&ptr2<<endl;//ptr2 own address in memory
//	
//	//comparing pointers (address)
//	if(ptr==*ptr2)
//	{
//		cout<<"EQUAL ADDRESS"<<endl;
//	}
//	else
//	{
//		cout<<"DIFFERENT ADDRESS"<<endl;
//	}
//	
//	int y = 5;
//	int *ptr3 = &y;
//	//comparing pointers (VALUES)
//	if(*ptr==*ptr3)
//	{
//		cout<<"EQUAL VALUES "<<endl;
//	}
//	else
//	{
//		cout<<"DIFFERENT VALUES"<<endl;
//	}
//	
//	cout<<endl;
//	
//	int *newptr= new int;// *newptr stored in stack while value is stored in heap
//	*newptr=30;
//	
//	cout<<"Value pointed by newptr: "<<*newptr<<endl;
//	cout<<"Address stored in newptr: "<<newptr<<endl;
//	cout<<"Address of newptr: "<<&newptr<<endl;
//	
//	delete newptr;
//	
//	cout<<"Value pointed by newptr AFTER DELETE: "<<*newptr<<endl;//newptr is a dangling pointer (points at garbage values)
//	return 0;
	
	
	//RECURSION
	string name="NAFAY";
	Precursion(name, 0);//FORWARD TRACKING
	cout<<endl;
	Nrecursion(name, 0);//BACKWARD TRACKING
	cout<<endl;
	int num=4;
	cout<<"FACTORIAL OF "<<num<<" is: "<<factorial(num)<<endl;
	
	
}
