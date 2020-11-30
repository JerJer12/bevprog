#include "std_lib_facilities.h"

int ga[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};	//globális int változó

void f(int array[], int n)				//f függvény
{
	int la[10];

	for (int i=0; i<n; i++ )			//la feltöltése ga elemeivel/ ga elemeinek másolása a la-ba
		la[i]=ga[i];

	for (int i=0; i<n; i++ )			//la elemeinek kiírása
		cout<< la[i] <<endl;

	int* p = new int[n];				//p pointer felvétele

	for (int i=0; i<n; i++ )			//array másolása a p-be
		p[i]=array[i];

	for(int i = 0; i < n; ++i)			//free store array elemeinek kiírása
		cout << p[i] << endl;

	delete[] p;
	
}
//f vége

int main()
{

	cout<<"f függvény a ga tömbön"<<endl;

	f(ga, 10);

	int aa[] {1, 1*2, 1*2*3, 1*2*3*4, 1*2*3*4*5, 1*2*3*4*5*6, 1*2*3*4*5*6*7, 1*2*3*4*5*6*7*8, 1*2*3*4*5*6*7*8*9, 1*2*3*4*5*6*7*8*9*10};

	cout<<"f függvény az aa tömbön"<<endl;

	f(aa,10);


	return 0;
}