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
		int count;
		int *arr;
		int ele;
		int index;
		int size;
		BST()
		{
			root=NULL;
			duplicate=0;
			count=0;
			ele=0;
			index=0;
			size=0;
		}
		void search(node *temp, int val)
		{
			if(root=NULL)
			{
				cout<<"TREE IS EMPTY"<<endl;
				return ;
			}
			else if(temp->data==val)
			{
				cout<<val<<" IS PRESENT IN TREE"<<endl;
				return ;
			}
			else if(temp->data>val)
			{
				if( temp->left!=NULL )
				{
					search(temp->left, val);
				}
				
			}
			else if(temp->data<val)
			{
				if( temp->right!=NULL )
				{
					search(temp->right, val);
				}
				
			}
			if(count==0)
			{
				cout<<val<<" IS NOT PRESENT IN TREE"<<endl;
			}
			count++;
			return ;
		}
		
		node* Find(node*root, int data) 
		{
			if(root == NULL) 
			return NULL;
			else if(root->data == data) 
			return root;
			else if(root->data < data) 
			return Find(root->right,data);
			else 
			return Find(root->left,data);
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
		void deletion(node *temp, node *root, int val)
		{
			
			if(temp==NULL)
			{
				return ;
			}
			else if(temp->data==val)
			{
				//value found
				node *p= parent(root, temp, NULL);
		//		cout<<"PARENT OF "<<temp->data<<" IS: "<<p->data<<endl;//deleted node's parent
			
			//CASE 1 (NODE IS A LEAF)
				if(temp->left==NULL && temp->right==NULL) //if the right child of p is val
				{
					
					if(p->right->data==temp->data)
					{
						p->right=NULL;
						delete temp;
						return ;
					}
					else if(p->left->data==temp->data)
					{
						p->left=NULL;
						delete temp;
						return ;
					}					
				}
			//CASE 2 (NODE HAS 1 CHILD)
				else if(temp->left!=NULL && temp->right==NULL)
				{
					if(p->right->data==val)
					{
						p->right=temp->left;
						delete temp;
						return ;
					}
					else if(p->left->data==val)
					{
						p->left=temp->left;
						delete temp;
						return ;
					}
				}
				else if(temp->right!=NULL && temp->left==NULL)
				{
					if(p->right->data==val)
					{
						p->right=temp->right;
						delete temp;
						return ;
					}
					else if(p->left->data==val)
					{
						p->left=temp->right;
						delete temp;
						return ;
					}
				}
				//CASE 3 (NODE HAS 2 CHILD)
			else if (temp->left != NULL && temp->right != NULL)
				{
				    node* t; 
				    if(p == NULL || p->left==temp)
				    {  
				        t = temp->right;
				        while(t->left!=NULL)
				            t = t->left;
				        if(p!=NULL)
				            p->left = temp->right;
				        else
				            root = temp->right;
				        t->left = temp->left;
				        temp->left = temp->right=NULL;
				        delete temp;

   					 } 

				    else if(p->right==temp)
				    {
				        t = temp->left;
				        while(t->right!=NULL)
				            t = t->right;
				        p->right=temp->left;
				        t->right = temp->right;
				        temp->left = temp->right=NULL;
				        delete temp;
				    }
  			}
			}
			else if(temp->data>val)
			{
				if( temp->left!=NULL )
				{
					deletion(temp->left , root , val);
					return ;
				}
				else
				return ;
				
			}
			else if(temp->data<val)
			{
				if( temp->right!=NULL )
				{
					deletion(temp->right , root , val);
					return ;
				}
				else
				return ;
			}
			
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
			
		void inorder(node *n, node *root)
		{
			if(n==NULL)
			{
				return ;
			}
			inorder(n->left, root);
			cout<<n->data<<" ";
			inorder(n->right, root);
		}
		
		node *parent(node *curr, node *p, node *par)
		{
			if(curr==NULL)
			return NULL;
			else if(curr==p)
			return par;
			else
			{
				node *t= NULL;
				t= parent(curr->left , p , curr);
				if(t!=NULL)
					return t;
				else
				{
					t=parent(curr->right , p , curr);
					return t;
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
		
		
		cout<<B1.maxdepth(root->left->left)<<endl;
		
	    

}

