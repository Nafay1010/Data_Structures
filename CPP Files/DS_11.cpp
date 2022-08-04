#include<iostream>
#include<math.h>
#define COUNT 10

using namespace std;


struct node{

	int value;
	node* left;
	node* right;

};

void print2DUtil(node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current Node after space 
    // count 
    cout<<endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout<<root->value<<"\n"; 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
// Function to print the binary tree
void print2D(node *root) 
{ 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
} 


class CBT {
	int Num_curNodes; //n will use to calculate num of half nodes that can accumudate in a level 
public:
	node *root,*temp,*last,*P_last;
	int level;

	CBT()
	{
		root=temp=NULL;
		Num_curNodes=level=0;
	}


	void insert (node *& point, int num,int L,int n){

		if(root==NULL){
			
			
			root=new node;
			root->value=num;
			root->left=NULL;
			root->right=NULL;
			level++;

			P_last=root;
			last=root;
			return;
		}

		//-------------

		if(Num_curNodes == pow(2,level)){
		
			level++;
			Num_curNodes=0;
		
		}


		if( n-1 == 0 ){
		
			if(point->left==NULL){
			
				point->left=new node;
				point->left->value=num;
				point->left->left=NULL;
				point->left->right=NULL;
				
				P_last=point;
				last=point->left;
			}

			else {
			

				point->right=new node;
				point->right->value=num;
				point->right->left=NULL;
				point->right->right=NULL;

				P_last=point;
				last=point->right;			
			}

			Num_curNodes++;
			
			if(Num_curNodes == pow(2,level)){
			
				level++;
				Num_curNodes=0;
			}

	
			return;
		}

		//--------------------
	
		if(Num_curNodes < (pow(2,L) - pow(2,n-1))){

				
			insert(point->left,num,L-1,n-1);
		
		}
		else {
		
			

			insert(point->right,num,L,n-1);
		
		}
	
	}


	//---------Insertion----------

	

	//---------Delete---------

	void del_node(node* point,int num){
	
		temp=NULL;
		search(point,num);  //search ka function temp ko us number p khara kr da ga jisa delete krna ha 


		if(temp==NULL){
			cout<<"NUMBER NOT FOUND"<<endl;
			return;
		
		}

		else{
			cout<<"Search ki value :"<<temp->value<<endl;
		
			if(temp == root && root->left == NULL && root->right == NULL){
			
				root=NULL;
				last=NULL;
				P_last=NULL;

			}

			if(temp != last){
			
				temp->value=last->value;
			}
	
			if(P_last->left==last){
				
					P_last->left=NULL;
			}
			else{
				
					P_last->right=NULL;
			}

				delete last;
				last=temp=NULL;
			

				Num_curNodes--;


			if(Num_curNodes==0){
				cout<<"Level decreased"<<endl;
				level--;
				if(level >= 0){
					Num_curNodes=pow(2,level);
				}
				}
		
				
			
		}

		cout<<"Number of curent nodes after deletion: "<<Num_curNodes<<endl;

	
		if(root==NULL){
		
			last=NULL;
			P_last=NULL;
		}
		else{
			temp=last=P_last=root;
			int lev=level;
			setLast(lev,lev);
		}

		
	}


	//---------Delete---------


	//--------Set Last pointer-------
	//Set last pointer to last node and P_last pointer to its parent;

	void setLast(int n,int L){
	
		
		if( n == 0 ){
			
			last=temp;
			cout<<"parent :"<<P_last->value<<endl;
			cout<<"last :"<<last->value<<endl;

			return;
		}

		//--------------------
	
		P_last=temp;

		if(Num_curNodes <= (pow(2,L) - pow(2,n-1))){

				temp=temp->left;
			setLast(n-1,L-1);
		
		}
		else {
		
			
			temp=temp->right;
			setLast(n-1,L);
		
		}

	}


	//--------Set Last pointer-------
	//--------Search---------------


	void search (node *point,int num){
	
		if(root==NULL){
		
			cout<<"Tree is empty "<<endl;
			return;
		}


		if(point->value==num){
		
			temp=point;
			return;
		
		}

		if(point->left != NULL){
		
			search(point->left,num);

		}
		
		if(point->right != NULL){
		
			search(point->right,num);

		}


	}

	//--------Search---------------

	//---------traverse-------------
	void traverse (node *point){
	
		if(point==NULL){
		
			cout<<"Tree is empty"<<endl;
			return;
		
		}

			cout<<point->value<<endl;

		if(point->left!=NULL){
		
			
			traverse(point->left);
		}

	

		if(point->right!=NULL){
		
			
			traverse(point->right);
		}

	}

	//---------traverse-------------

	
	void dekh(){

	cout<<"parent: "<<P_last->value<<endl;
	cout<<"last: "<<last->value<<endl;

	}
};


class heap {
	public:
		int *h;
		int maxsize; //maxsize of the array
		int n; //current number of elements
		
		heap(int m)
		{
			maxsize=m;
			h = new int[maxsize];
			n=0;
			//initializing heap array
			for(int i=0; i<maxsize; i++)
			{
				h[i]=0;
			}
		}
		
		//function to convert a tree heap to an array heap
	void treeHeap_2_ArrHeap(node *root, int i)
	{
		if(root==NULL)
		{
			cout<<"Tree is empty"<<endl;
			return;
		}
		
		h[i] = root->value;	
		n++;
			
		if(root->left!=NULL)
		{
			
			treeHeap_2_ArrHeap(root->left, 2*i);
		}

		if(root->right!=NULL)
		{
			treeHeap_2_ArrHeap(root->right , (2*i)+1);
		}
	}
	
	//function to print heap array
	void printHeap()
	{
		cout<<"HEAP ARRAY"<<endl;
		for(int i=0; i<maxsize; i++)
		{
			cout<<h[i]<<"\t";
		}
		cout<<endl;
	}
	
	//insertion function for the heap array
	void insert_heap(int val)
	{
		if(n == maxsize)
		{
			cout<<"Heap array is full !"<<endl;
			return; 
		}
		
		n++;
		int i;
		for(i = n; i > 1; i = i/2)
		{
			cout<<"Comparing "<<val<<" & "<<h[i/2]<<" : "<<endl;
			if(val >= h[i/2])
			{
				break;
			}
			cout<<"Replacing "<<h[i]<<" with "<<h[i/2]<<endl;			
			h[i] = h[i/2]; 
			printHeap();
			cout<<endl;
			
		}
		cout<<"Changing "<<h[i]<<" to "<<val<<endl;
		h[i] = val;
		printHeap();
		cout<<endl;
	}

};	
	
	
int main(){

	CBT obj;
	
	obj.insert(obj.root, 13 ,obj.level,obj.level);
	obj.insert(obj.root, 21 ,obj.level,obj.level);
	obj.insert(obj.root, 16 ,obj.level,obj.level);
	obj.insert(obj.root, 24 ,obj.level,obj.level);
	obj.insert(obj.root, 31 ,obj.level,obj.level);
	obj.insert(obj.root, 19 ,obj.level,obj.level);
	obj.insert(obj.root, 68 ,obj.level,obj.level);
	obj.insert(obj.root, 65 ,obj.level,obj.level);
	obj.insert(obj.root, 26 ,obj.level,obj.level);
	obj.insert(obj.root, 32 ,obj.level,obj.level);
	

	cout<<"Binary Tree"<<endl;
	print2D(obj.root);
	heap H1(15);
	int i=1;
	H1.treeHeap_2_ArrHeap(obj.root, i);
	cout<<endl;
	H1.printHeap();

	cout<<"==============INSERT(14)=============="<<endl;
	H1.insert_heap(14);
	H1.printHeap();
	
	cout<<"==============INSERT(15)=============="<<endl;
	H1.insert_heap(15);
	H1.printHeap();

//	cout<<"Last is : "<<obj.last->value<<endl;
//
//	obj.traverse(obj.root);
//
//
//	obj.del_node(obj.root,9);
//	cout<<"Last is : "<<obj.last->value<<endl;
//	obj.traverse(obj.root);
//
//	obj.del_node(obj.root,1);
//	cout<<"Last is : "<<obj.last->value<<endl;
//	obj.traverse(obj.root);
//	
//	cout<<"\n\n\n";
//	obj.insert(obj.root,48,obj.level,obj.level);
//	obj.dekh();
//
//	obj.traverse(obj.root);
//
//	obj.del_node(obj.root,6);
//	cout<<"Last is : "<<obj.last->value<<endl;
//	obj.traverse(obj.root);
//	
//	


}
