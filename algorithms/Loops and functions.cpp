// 11杨茜茸.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
//#include<math.h>
using namespace std;




//
//bool prime(int n)
//{
//	int i;
//	for(i=2;i<=sqrt(n*1.0);i++)
//	{
//		if(n%i==0)
//		{
//			break;
//		}
//	}
//	if(i<=sqrt(n*1.0))
//	{
//		return false;
//	}
//	else if(i>sqrt(n*1.0))
//	{
//		return true;
//	}
//
//}



int maxab;(int a,int b)
{
	int i;
	if(a<b)
	{
		i=a;
		a=b;
		b=i;
	}
	
	for(i=a;i>1;i--)
	{
		if((a%i==0)&&(b%i==0))
		{
			break;
		}
	}
	
	return i;
}


int minab(int i,int b)
{
	int i;
	if(a<b)
	{
		i=a;
		a=b;
		b=i;
	}
	for(i=1;i<=a;i++)
	{
		if((b*i)%a==0)
		{
			break;
		}
	}
	return b*i;
}

int main()
{
	
	/*int n;
	bool p;
	while(1)
	{
		cout<<"input n:"<<endl;
		cin>>n;
		p=prime(n);


		if(n<2) 
		{
			break;
		}

		if(p==true)
		{
			cout<<"is"<<endl;
		}
		else
		{
			cout<<"isn't"<<endl;
		}*/
	



	//int a,b,t,n;
	//bool p;
	//cout<<"input a"<<endl;
	//cin>>a;
	//cout<<"input b"<<endl;
	//cin>>b;

	//if(a>b)
	//{
	//	t=a;
	//	a=b;
	//	b=t;
	//}

	//for(n=a;n<=b;n++)
	//{
	//	p=prime(n);

	//	if(p==true)
	//	{
	//		cout<<n<<" "<<"is"<<endl;
	//	}
	//}

	int a,b;
	cout<<"input a";
	cin>>a;
	couty<<"input b";
	cin>>b;
	cout<<"max "<<maxab(a,b)<<"min "<<minab(a,b);






	

	getchar();
	getchar();
	return 0;
}
