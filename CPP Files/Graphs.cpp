#include<iostream>
using namespace std;

class node{
	public:
		
	char data;
	node *next;
	
	node(char val)
	{
		data=val;
		next=NULL;
		
	}
};

class graph{
	private:
		int size;
		int len;
	public:
		node** v;
		graph(char S)
		{
			size=S;
			len=0;
			//initializing array
			v = new node*[size];
			for(int i=0; i<S; i++)
			{
				v[i]->data = '0';
			}
		}
		
		void input()
		{
			node* v;
			char val;
			for(int i=0; i<size; i++)
			{
				cout<<"Enter Vertix: ";
				cin>>val;
				v = new node(val);
			}
		}
		
		void print()
		{
			for(int i=0; i<size; i++)
			{
				cout<<v[i]->data<<endl;
			}
		}
		
};

int main()
{
	graph G1(5);
	
	G1.input();
	G1.print();
}
