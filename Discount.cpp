#include <iostream> 
using namespace std;

int main()
{
	double sum;
	
	cout<<"input sum";
	cin>>sum;
	
	if(sum>=1000)
	{
		sum*=0.7;
	}
	else if(sum>=900)
	{
		sum*=0.75;	
	}
	else if(sum>=800)
	{
		sum*=0.8;	
	}
	else if(sum>=700)
	{
		sum*=0.85;	
	}
	else if(sum>=600)
	{
		sum*=0.9;	
	}
	
	cout<<sum;
	
	
	int i;
	
	cout<<"input i:";
	cin>>i;
	
	switch(i)
	{
		case 1:
		cout<<"һ";break;
		case 2:cout<<"��";break;
		case 3:cout<<"��";break;
		case 4:cout<<"��";break;
		case 5:cout<<"��";break;
		case 6:cout<<"��";break;
		case 7:cout<<"��";break;
		case else :cout<<"error";
	}
	getchar ();
	return 0;
} 
