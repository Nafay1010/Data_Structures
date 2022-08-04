#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//************************Q2********************
//int recursion(int l, int n1, int s)
//{
//	if(n1!=l)
//	{
//		n1++;
//		s+=n1;
//		
//	}
//	else
//	return s;
//	
//	recursion(l, n1, s);
//}
//
//
//int main()
//{
//	int limit;
//	cout<<"ENTER LIMIT: ";
//	cin>>limit;
//	int num=0;
//	
//	cout<<"ANSWER: "<<recursion(limit, num, num)<<endl;
//}

//*******************Q3********************************

//int fact(int n)
//{
//	if(n==1)
//	{
//		return 1;		
//	}	
//	
//	return n*fact(n-1);
//}
//
//int main()
//{
//	int num;
//	cout<<"Enter a number: ";
//	cin>>num;
//	
//	cout<<"FACTORIAL OF "<<num<<" is: "<<fact(num)<<endl;
//}

//**************************Q4 PART 1**************************
//
//int find(string s, char c)
//{
//	for(int i=0;i<s.length();i++)
//	{
//		if(s[i]==c)
//		{
//			return i;
//		}
//	}
//}
//bool elfish(char *s, char *elf, int i)
//{
//	if(elf[i]=='\0')
//		return 1;
//	if(find(s,elf[i]))
//    	return elfish(s,elf,i+1);                 
//    else
//        return 0;
//}
//
//int main()
//{
//	char word[1000];
//	char elf[4]="elf";
//	int r;
//	cout<<"ENTER A WORD: ";
//	cin>>word;
//	r=elfish(word, elf, 0);
//	if(r==1)
//	{
//		cout<<"YOUR WORD IS ELFISH"<<endl;
//	}
//	else
//	{
//		cout<<"YOUR WORD IS NOT ELFISH"<<endl;
//	}
//}

//**************************Q4 PART 2**************************
//int find(string s, char c)
//{
//	for(int i=0;i<s.length();i++)
//	{
//		if(s[i]==c)
//		{
//			return 1;
//		}
//	}
//}
//bool xish(char *w1, char *w2, int i)
//{
//	if(w1[i]=='\0')
//		return 1;
//	if(find(w2,w1[i]))
//    	return xish(w1,w2,i+1);                 
//    else
//        return 0;
//}
//
//int main()
//{
//	char word1[100];
//	char word2[100];
//	int r;
//	cout<<"ENTER 1st word: ";
//	cin>>word1;
//	cout<<"ENTER 2nd word: ";
//	cin>>word2;
//	r=xish(word1, word2, 0);
//	if(r==1)
//	{
//		cout<<"All characters from first word are in second"<<endl;
//	}
//	else
//	{
//		cout<<"All characters from first word are NOT in second"<<endl;
//	}
//}

//********************Q5*************************

//int multiply(int a, int b, int i, int sum)
//{
//	if(i!=b)
//	{
//		i++;
//		sum+=a;
//		multiply(a, b, i, sum);
//	}
//	else
//		return sum;
//}
//
//int main()
//{
//	int a,b;//2 numbers
//	int i=0;//index
//	int r=0;//result
//	cout<<"ENTER A: ";
//	cin>>a;
//	cout<<"ENTER B: ";
//	cin>>b;
//	cout<<"MULTIPLICATION OF "<<a<<"&"<<b<<" is "<<multiply(a,b,i,r)<<endl;
//}

//***********************Q1*********************
//void reverse(string *w,string *r, int s)
//{
//	for(int i=s;i>=0;i--)
//	{
//		r[i-3]=w[i];
//	}
//}
//
//int main()
//{
//	int size;
//	cout<<"ENTER SIZE: ";
//	cin>>size;
//	string *word=new string[size];
//	string *rev=new string[size];
//	for(int i=0;i<size;i++)
//	{
//		cout<<"ENTER WORD: ";
//		cin>>word[i];
//	}
//	reverse(word, rev, size);
//	cout<<"WORD ARRAY: "<<endl;
//	for(int i=0;i<size;i++)
//	{
//		cout<<word[i];
//	}
//	cout<<endl;
//	cout<<"REVERSE ARRAY: "<<endl;
//	for(int i=0;i<size;i++)
//	{
//		cout<<rev[i];
//	}
//	delete[] word;
//	delete[] rev;
//}
