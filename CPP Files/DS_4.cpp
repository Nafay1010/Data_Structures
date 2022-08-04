#include<iostream>
using namespace std;

struct node{
int value;
node *next;
};

class LinkedList{
private:
	node *head,*temp,*temp2; //head will always point to first element, temp and temp2 will be used for moving and adding new nodes in the list
public:
	LinkedList(){

		head=NULL;
		temp=NULL;
		temp2=NULL;

	}

    //you can take value using user input within function or by passing value to the add function using a parameter
    //assuming you will use user input within function
	void add(){
	
                
        //code for checking whether the first element exists or not
        //if 1st element doesn't exists, write code to create 1st element
        //first element will always be pointed by head pointer
        int val;
		cout<<"ENTER A VALUE TO BE ADDED: ";
        cin>>val;
        
        temp=head;
      	node *n=new node;
		if(head==NULL)
		{
			n->value=val;
			n->next=NULL;
			head=n;
			temp=head;
			return ;
		}
		
        //if first element already exsist, move the temp pointer to the last element
        
		//		cout<<"ENTER IF STATEMENT"<<endl;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			
        node *n2=new node;//create a new node
		n2->value=val; //assign it a value
        n2->next=NULL;//make it's next pointer null
        temp->next=n2;//the newly created node will be poined by the next pointer of last node
        
	}

    //function to add a new value after an existing value
    //you can take value using user input within function or by passing value to the add function using a parameter
    //assuming you will use user input within function
	void addAfterSomeValue(int val){ //val parameter is for the value after which we want to add another value
	
		temp=head;
		int v;
		node *n3=new node;
		//write code to find the value after which you want to add the new value
        //create a new node,assign it value
        //assign the address of the next pointer of the node which is pointed by temp to the next pointer of newly created node 
        //assign the address of newly created node to the next pointer of node pointed by temp
		//your code goes here
		
		if(head==NULL)
		{
			cout<<"LIST IS EMPTY"<<endl;
		}
		else
		{
			while(temp!=NULL)
			{
				
				if(temp->value==val)
				{
					cout<<"ENTER A VALUE TO BE INSERTED: ";
					cin>>v;
					n3->value=v;
					n3->next=temp->next;
					temp->next=n3;
			//		cout<<"TEMP: "<<temp->next->value<<endl;
					return ;
				}
				else if(temp->value!=val && temp->next==NULL)
				cout<<val<<" NOT FOUND IN LIST"<<endl;
				temp=temp->next;
			}
			
		}
		
					
}

	void del_1st(int val){//val contains the value to be deleted, if the value exists multiple times in the list, then delete it's first occurence
	temp=head;
	temp2=head;
    cout<<"VALUE TO BE DELETED: "<<val<<endl;
    //check whether the list is empty or not, if list is empty, prompt a message and return
	//your code goes here
	if(head==NULL)
	{
		cout<<"LIST IS EMPTY"<<endl;
	}
    
    //first check if the first node contains the desired value or not, if yes then delete it and point the head to next element.
    //return from the function	
    //your code goes here     
	if(temp->value==val)
	{
		head=temp->next;
		delete temp;
		return ;
	}

	//write code to find the node having the desired value,if first element doesn't containws the desired value
    //hint: you need to check value of each next node while staying on the previous node
    //once node with desired value is found, first make arrangement for next pointer
    //delete the node with the value
    //return
    //your code goes here
    	int flag=0;

			
		while(temp->next!=NULL)
		{
//			cout<<"TEMP2: "<<temp2->value<<endl;
//			cout<<"TEMP: "<<temp->value<<endl;
			temp2=temp;
			temp=temp->next;
			
			if (temp->value == val)
			{
				temp2->next=temp->next;
				delete temp;
				flag=1;
			 	return;
			}
			else if (temp->value == val && temp->next == NULL)
			{
				temp2->next=NULL;
				delete temp;
				flag=1;
				return;
			}
		}
		


	//if no node contauins the desired value, prompt the user with appropriate message and return
	//your code goes here
		if(flag==0)
		cout<<val<<" VALUE NOT FOUND"<<endl;


	}//function end

	void print(){ //function to print all the values of the list
		temp=head;
        if(head==NULL)
    	{
    		cout<<"LIST IS EMPTY"<<endl;
		}
		else
		{
			cout<<"LIST: "<<endl;
			while(temp!=NULL)
			{
				cout<<temp->value<<"\t";
				temp=temp->next;
			}
		}
		cout<<endl;
    	
	}
	
};




int main(){

LinkedList obj;

obj.add();//1

obj.add();//2
obj.add();//3
obj.add();//4
obj.add();//3
obj.print();
cout<<"After Value.."<<endl;

obj.addAfterSomeValue(5);//3
//cout<<"\n\n\n\n\n";
obj.print();

cout<<"\nDelete"<<endl;

obj.del_1st(1);

obj.print();

obj.del_1st(2);

obj.print();

obj.del_1st(10);

obj.print();

system("pause");
}
