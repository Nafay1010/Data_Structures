#include<iostream>
#include<cstddef>
using namespace std;

class queue{
	public:
		
		int front;
		int rear;
		
		int *q;
		int *ptr;
		
		int size;
		int len;
		
		queue(int s)
		{
			front=0;
			rear=-1;
			size=s;
			len=0;
			q=new int[size];
			ptr=q;			
		}
	
		void PrintQueue()
		{
			if (isEmpty())
				cout<<"QUEUE IS EMPTY"<<endl;
			else if(rear >= front)
		    {
		    	cout<<"===========QUEUE==========="<<endl;
		        for (int i=front; i<=rear; i++)
		        	cout<<q[i]<<" "<<endl;
		    }
			else 
		    {
		      cout<<"===========QUEUE==========="<<endl;
		      for (int i=0; i<=rear; i++)
		      {
		    	cout<<q[i]<<" "<<endl;
			  }
		      for (int i=front; i<size; i++)
		      {
		    	cout<<q[i]<<" "<<endl;
			  }
			  
		    }
		    cout<<endl;
		}
		bool isFull()
		{
			//if((size==len)||(front==0 && rear==size-1)||(rear==front-1))
			if(len==size)
			return 1;
			else
			return 0;
		}
		bool isEmpty()
		{
			if(len==0)
			return 1;
			else
			return 0;
		}
		void enqueue(int val)
		{
			if(isFull()==1)
			{
				cout<<"QUEUE OVERFLOW"<<endl;
				return ;
			}
			else if(rear==size-1)
			{
				rear=0;
				q[rear]=val;
				len++;
			}
			else
			{
				q[++rear]=val;
				len++;
			}
		//	cout<<"REAR: "<<rear<<endl;
		}
		void dequeue()
		{
			if(isEmpty())
			{
				cout<<"QUEUE UNDERFLOW"<<endl;
			}
			else
			{
				int val=q[front];
				q[front]=0;
				
				if(front==size-1)
				{
					front=0;	
				}
				else
				{
					front++;
				}
				len--;
			//	return val;
			}
		//	cout<<"LEN: "<<len<<endl;
		
		}
};

int main()
{
	queue q1(5);
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.dequeue();
	q1.dequeue();
	q1.enqueue(6);
	q1.enqueue(7);
	q1.dequeue();
	q1.enqueue(8);

	q1.PrintQueue();
	
}
