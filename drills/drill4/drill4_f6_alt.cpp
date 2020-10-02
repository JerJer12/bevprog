# include "std_lib_facilities.h"

int main()
{

double a=0, b=0;
double min=0, max=0;
int i=0;

cout<<"Please write in a number"<<endl;
cin>>b;
min=b;
cout<<"Please write in the number again"<<endl;

while (cin>>a)
{
	
	if (i==0) 
	{
		if(a!=b)
			error("The numbers do not match");

	}
     
	cout<<"a="<<a<<endl;


	if (a<min)
		{cout<<"The smallest so far"<<endl;
		min=a;

		}

    if (a>max)
	{cout<<"The largest so far"<<endl;
		max=a;


	}
	
	i++;



}





return 0;

}