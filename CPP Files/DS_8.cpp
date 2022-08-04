#include<iostream>
#include<cstddef>
using namespace std;

class node{
		public:

		int data;
		node *next;
		node *pre;
	
		node(int val)
		{
			data=val;
			next=NULL;
			pre=NULL; 
		}
};

class list{
	private:
		node *head;
		node *tail;
		int size;
	public:
		list()
		{
			head=NULL;
			size=0;
		}
		int Return_size()
		{
			return size;
		}
		void get() //prints in normal order
		{
			node *ptr= head;
			if(empty()==0)
				cout<<"LIST IS EMPTY"<<endl;
			else
			{
			cout<<"LIST"<<endl;
			for(int i=0; i<size; i++)
			{
				cout<<ptr->data<<"\t";
				ptr=ptr->next;
			}
			}
			cout<<endl;
		}
		void rget() //prints in reverse order
		{
			node *ptr=head;
			cout<<"REVERSE LIST"<<endl;
			if(empty()==0)
			cout<<"LIST IS EMPTY"<<endl;
			else
			{
				for(int i=0;i<size-1;i++)
				{
					ptr=ptr->next;
				}
				for(int i=0;i<size;i++)
				{
					cout<<ptr->data<<"\t";
					ptr=ptr->pre;
				}
			}
			cout<<endl;
		}
		void circular()
		{
			node *ptr=head;
			for(int i=0;i<size-1;i++)
			{
				ptr=ptr->next;
			}
			ptr->next=head;
		}
		bool empty()
		{
			if(size==0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		void insert(int val, int pos)
		{
		//	cout<<"VAL :"<<val<<" POS: "<<pos<<endl;
			node *n= new node(val);
			if(pos==1)
			{
			//	cout<<"HEADER POINTER "<<head<<endl;
				
				n->pre=NULL;
				n->next=head;
				head=n;
				head->pre=n;
		
				size++;
				
			}
			else if(pos>1 || pos<size+1)
			{
				node *cptr= head;
				
				for(int i=1; i<pos-1;i++)
					cptr=cptr->next;
				
					
				n->next=cptr->next;
				n->pre=cptr;
				
				
				cptr->next=n;
				cptr->next->pre=n->pre;
				
				size++;			
			}
			
			else
			{
				cout<<"INVALID POSITION"<<endl;
			}
			circular();
		}
		int search(int val)
		{
			if(empty()==0)
			{
				cout<<"LIST IS EMPTY"<<endl;
			}
			int pos=1;
			node *cptr=head;
			int i=0;
			while(i<Return_size())//runs till current pointers address is NULL
			{
				if(cptr->data==val)
				{
					return pos;//value found
				}
				cptr=cptr->next;
				pos++;
				i++;
			}
			return -1;//value not found
		
			
		}
		void deletion(int val)
		{
			if(search(val)==-1)
				cout<<"VALUE NOT IN LIST"<<endl;
			else
			{
			int pos=search(val);
			node *cptr=head;
			if(pos==1)
			{
				head=cptr->next;
				delete cptr;
				size--;
			}
			else if(pos>1 || pos<size)
			{
				for(int i=1; i<pos-1;i++)
				{
					cptr=cptr->next;
				}
				node *dptr= cptr->next;
				dptr->next->pre=cptr;
				cptr->next=dptr->next;
				delete dptr;
				size--;
			}
			else if(pos==size)
			{
				for(int i=1; i<pos-1;i++)
				{
					cptr=cptr->next;
				}
				node *dptr= cptr->next;
				cptr->next->pre=cptr;
				cptr->next=dptr->next;
				delete dptr;
				size--;
			}
			 else if(pos==0)
			{
				cout<<"LIST IS EMPTY"<<endl;
			}
			}
			circular();
		}
		
};
int main()
{
	list l1;
	int val;
	cout<<"ENTER VALUE TO BE INSERTED: ";
	cin>>val;
	int pos=1;
	while(val!=-1)
	{
		l1.insert(val, pos);
		cout<<"ENTER VALUE TO BE INSERTED[ENTER '-1' to quit]: ";
		cin>>val;
		pos++;
	}
	
	l1.get();
//	l1.rget();  prints the list in reverse order (to check previous ptr)
	
	while(l1.empty()!=0)
	{
		cout<<"ENTER VALUE TO BE DELETED: ";
		cin>>val;
		l1.deletion(val);
		l1.get();
//		l1.rget();   prints the list in reverse order (to check previous ptr)
	}
		
}

