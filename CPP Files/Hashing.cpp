#include<iostream>
using namespace std;

class HashTable{
	private:
		int *H;
		int *temp;
	
		
	public:
		double length;
		int maxsize;
		HashTable(int m)
		{
			maxsize=m;
			length=0;
			H = new int[maxsize];
			//initializing array
			for(int i=0; i<maxsize; i++)
			{
				H[i]=-1;
			}
		}
		
		void print()
		{
			cout<<"HASH TABLE"<<endl;
			for(int i=0; i<maxsize; i++)
			{
				cout<<H[i]<<endl;
			}
			cout<<endl;
		}
		
		int Check_Length()
		{
			int L;
			L = (length/maxsize)*100;
			return L;
		}
		
		void rehashing()
		{
				temp = new int[maxsize];//making a temp array
				for(int i=0; i<maxsize; i++)
				{
					temp[i] = H[i];//copying previous array data to temp array
				}
				
				maxsize = maxsize*2;
				H = new int[maxsize];
				//initializing array
				for(int i=0; i<maxsize; i++)
				{
					H[i] = -1;
				}
				
				for(int i=0; i<maxsize/2; i++)
				{
					if(temp[i] != -1)
					{
						int L = temp[i] % maxsize;
						H[L]=temp[i];
					}
				}
				
				delete temp;
			
		}
	
		void insert(int val, int loc)
		{
		
			if(Check_Length()>70)//checking whether the array is within the threshold
			{
						rehashing();
						loc = val%maxsize;
						insert(val, loc);
						return ;
			}
			else 
			{
				cout<<"VAL: "<<val<<" LOC: "<<loc<<endl;
				//There is space in the array
				cout<<"MAXSIZE: "<<maxsize<<endl;
				if(loc == maxsize-1 && H[loc] != -1)//if end of array is reached
				{
					loc = 0;
					H[loc] = val;
					length++;
					return ;
				}
				if(H[loc] == -1)//if empty slot
				{
					H[loc] = val;
					length++;
					return ;
				}			
				else
				{
					loc++;
					insert(val, loc);
				}
			}	
		}

		bool search(int val, int loc)
		{
			
			if(val == H[loc])
			return true;
			else if(H[loc] == -1)
			return false;
			else if(loc == maxsize-1 && H[loc] != -1)
			{
				loc=0;
				search(val, loc);
			}
			else
			search(val, ++loc);
		}
};

int main()
{

	int val;
	char quit = 'N';
	
	HashTable H1(7);
	
	while(quit != 'q')
	{
		cout<<"ENTER A VAL TO BE INSERTED IN THE HASH TABLE [Must be within 0--999]: ";
		cin>>val;
		if(val >= 0 && val <=999)
		{
			H1.insert(val, val%H1.maxsize);
			H1.print();
			cout<<"Enter 'q' to quit: ";
			cin>>quit;
		}
		else
		{
			cout<<"Value NOT in range, Try Again"<<endl;
		}
	}	
	


		cout<<"ENTER A VAL TO BE SEARCHED IN THE HASH TABLE [Must be within 0--999]: ";
		cin>>val;
		
		if(H1.search(val, val%H1.maxsize))
		cout<<"Value found"<<endl;
		else
		cout<<"Value NOT found"<<endl;
		
}
