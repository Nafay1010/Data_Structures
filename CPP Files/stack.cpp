#include<iostream>
using namespace std;

class stack{
	private:
		int *arr;
		int size;
		int top;
	public:
		stack(int s)
		{
			size=s;
			top=-1;
			arr=new int[size];
		}
	
	bool isEmpty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}
	
	void clear()
	{
		for(int i=0;i<size;i++)
		{
			arr[i]=0;
		}
	}
	bool isFull()
	{
		if(top==size-1)
			return 1;
		else
			return 0;
	}
	
	void PUSH(int val)
	{
		if(isFull())
		{
			cout<<"STACK OVERFLOW"<<endl;
		}
		arr[++top]=val;
	//	int ele=top+1;
		//cout<<"ELEMENTS: "<<ele<<endl;
	}
	
	void POP()
	{
		if(isEmpty())
		{
			cout<<"STACK UNDERFLOW"<<endl;
		}
		arr[top--]=0;
		//return arr[top];
		
	}
	
	void get()
	{
		cout<<"=============STACK============="<<endl;
		for(int i=size-1;i>=0;i--)
		{
			cout<<arr[i]<<endl;
		}
		cout<<endl;
	}
};

int main()
{
	stack S1(5);
	S1.clear();
	S1.PUSH(1);
	S1.PUSH(2);
	S1.PUSH(3);
	S1.PUSH(4);
	S1.PUSH(5);
	S1.POP();
	S1.POP();
	S1.get();
}
