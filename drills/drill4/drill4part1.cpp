#include "std_lib_facilities.h"

int main()

{

double a=0, b=0;

cout<<"Enter a and b"<<endl;

while (cin >> a >> b)
{

cout<<"a="<<a<<"  b="<<b<<endl;

if (a<b)
cout<<"a is smaller " <<a<<endl<<"b is bigger "<<b<<endl;

if (b<a)
cout<<"b is smaller "<<b<<endl<<"a is bigger "<<a<<endl;

if(a==b) 
cout<< "a and b is equal"<<endl;

if (abs(a-b)<=0.01 && a!=b) cout<<"The numbers are almost equal"<<endl;

}



	return 0;
}
