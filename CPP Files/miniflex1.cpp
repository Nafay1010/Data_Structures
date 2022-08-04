#include<iostream>
using namespace std;
#include <sstream> 
  
int main() 
{ 
    int list[10]={1,2,3,4,5,6,7,8,9,10};
    int i;
    for(int i=0;i<5;i++)
    {
    	int temp= list[i];
    	list[i]=list[9-i];
    	list[9-i]=temp;
	}
	for(int i=0;i<10;i++)
	{
		cout<<list[i]<<"\t";
	}
}
