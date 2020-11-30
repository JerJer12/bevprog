#include "std_lib_facilities.h"

vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};		//globális vektor

void f(vector <int> av)			//f függvény
{
	vector<int> lv(10);			//lv vektor felvétele

	for(int i=0; i<10; i++)		//gv vektor elemeinek másolása az lv vektorba
		lv[i]=gv[i];

	for(auto& v :lv )			//lv vektor kiírása
		cout << v << endl;

	vector<int> lv2(10);		//lv2 vektor felvétele
	lv2=av;						//lv2 vektor iniciálása az av vektorra (argument vektorra)

	for(auto& v :lv2 )			//lv2 elemeinek kiírása
		cout << v << endl;


}
//f vége


int fact(int n)					//faktoriális függvény
{
	if ((n==0)||(n==1))	return 1;		//ha az n 0 vagy 1 akkor 1-et ad vissza
   	else	return n*fact(n-1);			//egyébként meg beszorozza az elötte lévő faktoriális számmal
}


int main()
{

	cout<<"f függvény gv vektoron"<<endl;
	f(gv);

	vector<int> vv(10);

	for (int i=0; i<10;i++)				//a vv vektor feltöltése az 1-10 faktoriális számaival
	{
		vv[i] = fact(i+1);					

	}

	cout<<"f függvény vv vektoron"<<endl;
	f(vv);


	return 0;
}