# include "std_lib_facilities.h"

int main()
{

double a=0;
double min=0, max=0;


cout<<"Please write in a number"<<endl;
cin>>a;
min=a;
cout<<"Please write in the number again"<<endl;

while (cin>>a)
{
	

	cout<<"a="<<a<<endl;


	if (a<min)
		{cout<<"The smallest so far"<<endl;
		min=a;

		}

    if (a>max)
	{cout<<"The largest so far"<<endl;
		max=a;


	}
	
	



}





return 0;

}