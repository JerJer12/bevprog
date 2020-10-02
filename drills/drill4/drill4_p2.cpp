#include "std_lib_facilities.h"

int main()
{

double a=0, meter=0;

double max=0, min=0, sum=0, db=0;

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
			{sum=sum+(a/100);
				meter=(a/100);
			
			}
		
		
		if (unit=="ft")
			{sum=sum+(a/3.2808);
			meter=a/3.2808;
			}
		

		if (unit=="in")
			{sum=sum+(a*0.0254);
				meter=(a*0.0254);

			}

		db=db+1;

		if (max==0 && min==0)
		{
			min=meter;
			max=meter;
		}

		if (max<meter)
			max=meter;

		if (min>meter)
			min=meter;


		values.push_back(meter);


	}	
else cout<<"Invalid unit"<<endl;



}

cout<<"The smallest value is: "<<min<<" m"<<endl;
cout<<"The largest value is: "<<max<<" m"<<endl;
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