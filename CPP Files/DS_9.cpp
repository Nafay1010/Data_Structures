#include<iostream>
#include <string>
#include <sstream>
using namespace std;
#define COUNT 10

class node{
	public:
		int data;
		node *left;
		node *right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
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
  
    // Print current node after space 
    // count 
    cout<<endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout<<root->data<<"\n"; 
  
    // Process left child 
    print2DUtil(root->left, space); 
}
// Wrapper over print2DUtil() 
void print2D(node *root) 
{ 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
}  
class BST{
	public:
		node *root;
		int duplicate;
		int *arr;
		
		BST()
		{
			root=NULL;
			duplicate=0;	
		}
		
		
		int maxdepth(node *n)
		{
			if(n==NULL)
			return -1;
			else
			{
				int l=maxdepth(n->left);
				int r=maxdepth(n->right);
				
				if(l>r)
				return(l+1);
				else
				return(r+1); 
			}
		}
		
		int balance(node *n)
		{
			int left= maxdepth(n->left);
			int ryt= maxdepth(n->right);
			
			cout<<"MAX DEPTH OF LEFT SUBTREES: "<<left<<endl;
			cout<<"MAX DEPTH OF RIGHT SUBTREES: "<<ryt<<endl;
			
			return (left-ryt);
		}

		void insert(node *temp, int val)
		{	
			if(temp==NULL)
			{
				root=new node(val);
				return ;
			}
			else if(temp->data==val)
			{
				if(duplicate==0)
					cout<<val<<" IS ALREADY PRESENT IN BINARY TREE"<<endl;

				duplicate++;
				cout<<"NOTE: You entered this "<<duplicate<<" times."<<endl;
			}
			else if(temp->data>val)
			{
				if( temp->left!=NULL )
				{
					insert(temp->left, val);
					return ;
				}
				else
				{
					temp->left = new node(val);
					return ;
				}
			}
			else if(temp->data<val)
			{
				if( temp->right!=NULL )
				{
					insert(temp->right, val);
					return ;
				}
				else
				{
					temp->right = new node(val);
					return ;
				}
			}
		}
			
		
};

int main()
{
		BST B1;
		node *root = new node(10);
		
		B1.insert(root, 8);
		B1.insert(root, 5);
		B1.insert(root, 2);
		B1.insert(root, 11);
		B1.insert(root, 3);
		B1.insert(root, 6);
		B1.insert(root, 15);
		B1.insert(root, 14);
		B1.insert(root, 18);
		B1.insert(root, 12);
		
		
		print2D(root);
		
		
		cout<<"MAX DEPTH OF "<<root->data<<" IS: "<<B1.maxdepth(root)<<endl;
		cout<<"BALANCE OF " <<root->data<<" IS: "<<B1.balance(root)<<endl;
		
	    

}

