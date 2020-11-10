#include "std_lib_facilities.h"

int main()
{

double a=0, meter=0;

double sum=0, db=0;
double cm=100;
double ft=3.2808;
double in=0.0254;

string unit;

vector<double> values;

cout<<"Enter a measurment in m, cm, ft or in"<<endl;

while (cin>>a>>unit)
{



if (unit=="m" || unit=="cm" || unit=="ft" || unit=="in")
	{
		

		cout<<"You entered "<<a<<" "<<unit<<endl;

		if (unit=="m")
			{sum=sum+a;
				meter=a;

			}
		
		
		if (unit=="cm")
			{sum=sum+(a/cm);
				meter=(a/cm);
			
			}
		
		
		if (unit=="ft")
			{sum=sum+(a/ft);
			meter=a/ft;
			}
		

		if (unit=="in")
			{sum=sum+(a*in);
				meter=(a*in);

			}

		db=db+1;

		


		values.push_back(meter);


	}	
else cout<<"Invalid unit"<<endl;



}

sort(values.begin(), values.end());

cout<<"The smallest value is: "<<values[0]<<" m"<<endl;
cout<<"The largest value is: "<<values[db-1]<<" m"<<endl;
cout<<"The sum of the values are: "<<sum<<endl;
cout<<"The the number of values are: "<<db<<endl;

sort(values.begin(), values.end());

cout<<"The values in increasing order:"<<endl;


for(int i=0;i<values.size();i++)
{

cout<<values[i]<<" m"<<endl;

}



	return 0;
}
