// 11������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(i=1;i<=9;i++)
		{
			cout<<i<<"+"<<j<<"="<<i*j<<'\t';
		}
		for(j=i;j<=i;j++)
		{
		cout<<i<<"+"<<"="<<i+j<<"\t";
		}
		for(j=i+1;j<=9;j++)
		{
			cout<<i<<"*"<<j<<"="<<i*j<<"\t";
		}
		cout<<endl;
	}
	getchar();
	getchar();
}
	