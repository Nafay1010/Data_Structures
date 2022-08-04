#include<iostream>
using namespace std;

class node{

	public:
		int data;
		node *next;
		
		node(int val)
		{
			data=val;
			next=NULL;
		}
};

class stack{
	private:
		node *cptr;
		node *bottom;
		int size;
		int top;
	public:
		stack()
		{
			top=-1;
			size=0;
			cptr=NULL;
			bottom=NULL;
		}
		
		void start()
		{
			cptr=bottom;
		}
		
		void next()
		{
			cptr=cptr->next;
		}
		
		bool isEmpty()
		{
			if(top==-1 || size==0)
				return 1;
			else
				return 0;
		}
		
		void get()
		{
			start();
			if(isEmpty())
			{
				cout<<"STACK IS EMTPY"<<endl;
			}
			else
			{
				for(int i=0;i<size;i++)
				{
					cout<<cptr->data<<endl;
					next();
				}
			}
			start();
		}
		
		void print()
		{
			{
				
				cout<<"=============STACK============="<<endl;
				for(int i=size;i>0;i--)
				{
					if(isEmpty())
						{
							break;
						}
						else
						{
							cout<<POP()<<endl;
						}
				}
					cout<<endl;
			}
		}
		
		void clear()
		{
			start();
				for(int i=0;i<size;i++)
				{
					cptr->data=0;
					next();
				}
				size=0;
				top=-1;
			start();
		}
		
		void PUSH(int val)
		{
			start();
			node *n=new node(val);
			
			if(top==-1)
			{
				n->next=bottom;
				bottom=n;
				top++;
				size++;
				start();
			}
			else
			{
				for(int i=1;i<size;i++)
				{
					next();
				}
				n->next=cptr->next;
				cptr->next=n;
				top++;
				size++;
				start();
			}
			
		}

		int POP()
		{
			start();
			if(isEmpty())
			{
				cout<<"STACK IS EMPTY"<<endl;
			}
			else if(top==0 || size==1)
			{
				bottom=cptr->next;
				int Dval=cptr->data;
				delete cptr;
				size--;
				top--;
				return Dval;
			}
			else
			{
				for(int i=1;i<size-1;i++)
				{
					next();
				}
				node *dptr=cptr->next;
				cptr->next=dptr->next;
				int Dval=dptr->data;
				delete dptr;
				size--;
				top--;
				return Dval;
				
			}
			start();
		}
};
int main()
{
	stack s1;
	s1.clear();
	s1.PUSH(1);
	s1.PUSH(2);
	s1.PUSH(3);
	s1.PUSH(4);
	s1.PUSH(5);
	
	
	s1.POP();
	s1.POP();
	
	s1.print();
}
