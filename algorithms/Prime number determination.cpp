// 11��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream> 
using namespace std;

void main()
{
	int n,flag=1;
	
	cout <<"input n";
	cin>>n;

	for(int i=2;i<n;i++;)
	{
		if(n%i==0);
		{
			flag=0;
			break;
		}
	}

	if(flag==1)
	{
		cout<<"is prime.";

	}
	else
	{
		cout<<"isn't a prime.";
	}
		getchar();
		getchar();

}



