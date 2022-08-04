#include<iostream>
using namespace std;

class sort{
	public:
		int *A;
		int size;
	
	sort(int s)
	{
		size=s;
		A=new int[size];
		
		for(int i=0;i<size;i++)
		{
			A[i]=0;
		}
	}
	
	void input()
	{
		for(int i=0;i<size;i++)
		{
			cout<<"Enter No: ";
			cin>>A[i];
		}
			cout<<endl;
	}
	
	void print()
	{
		
		for(int i=0;i<size;i++)
		{
			cout<<A[i]<<"\t";
		}
		cout<<endl;
	}
	
	//sorting techniques
	
	void selection_sort()
	{
		for(int i=0; i<size-1; i++)
		{
			int min=i;
			
			for(int j=i; i<size-1; j++)
			{
				if(A[min]>A[j+1])
				min=j+1;
			}
			
			swap(A[min], A[i]);
		}
	}
	
	void bubble_sort()
	{
		for(int i=0; i<size-1; i++)
		{
			for(int j=1; j<size-i; j++)
			{
				if(A[j-1]>A[j])
				swap(A[j-1], A[j]);
			}
		}
	}
	void merge(int l, int m, int r)
	{
		int i, j, k;
		int n1 = m-l+1;
		int n2 = r-m;
		
		int L[n1], R[n2];
		
		for(int i=0 ; i<n1; i++)
		{
			L[i] = A[l+i];
		}
		for(int j=0 ; j<n2; j++)
		{
			R[j] = A[m+1+j];
		}
		
		i=0;
		j=0;
		k=l;
		
		while(i<n1 && j<n2)
		{
			if(L[i] <= R[j])
			{
				A[k] = L[i];
				i++;
			}
			else
			{
				A[k] = R[j];
				j++;
			}
		 k++;
		}
		
		while(i<n1)
		{
			A[k] = L[i];
			i++;
			k++;
		}
		while(j<n2)
		{
			A[k] = R[j];
			j++;
			k++;
		}
		
	}
	void mergesort(int left, int right)
	{
		if(left<right)
		{
			int m=(left+right)/2;
			mergesort(left, m);
			mergesort(m+1, r);
			
			merge(left, m, right);
		}
	}
	
	void insertion_sort(int n)
	{
		int i, key, j;
		
		for(int i=1; i<n; i++)
		{
			key = A[i];
			j = i-1;
			
			while(j >= 0 && A[j] > key)
			{
				A[j+1] = A[j];
				j = j - 1;
			}
			A[j+1] = key;
		}
		
	}
};

int main()
{
	sort S(5);
	
	S.input();
	S.print();
}
