#include<iostream>
using namespace std;
int main()
{
	char n;
	
	while(1)
	{
		cout<<"input a character :"; 
		cin>>n;
		
		if(n>='A'&&n<='Z')
		{
			n=n+32;
			cout<<n<<endl;
		}
		else if(n>='a'&&n<='z')
		{
			n=n-32;
			cout<<n<<endl;
		}
		else
		{
			cout<<"input wrong!";
			break;
		}
	}
} 
