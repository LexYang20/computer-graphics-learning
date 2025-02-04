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
		cout<<"一";break;
		case 2:cout<<"二";break;
		case 3:cout<<"三";break;
		case 4:cout<<"四";break;
		case 5:cout<<"五";break;
		case 6:cout<<"六";break;
		case 7:cout<<"日";break;
		case else :cout<<"error";
	}
	getchar ();
	return 0;
} 
