#include "std_lib_facilities.h"

ostream& print_array(ostream& os, int* a, int n)
{
	for(int i = 0; i < n; ++i)
		os << a[i] << endl;
	return os;
}


int main()
{
	try{

		int a = 7;
		int* p1 = &a;

		cout << "Value of p1: " << p1 << endl;		//p1 értéke
		cout << "Content of p1: " << *p1 << endl;	//int amire p1 mutat értéke
		
		int* p2 = new int[7] {1, 2, 4, 8, 16, 32, 64};

		cout << "Value of p2: " << p2 << endl;
		cout << "Content of p2: " << endl;
		print_array(cout, p2, 7);

		int* p3 = p2;
		p1 = p2;
		p3 = p2;

		cout << "Value of p1: " << p1 << endl;	
		//cout << "Content of p1: " << *p1 << endl;
		cout << "Content of p1: "<<endl;
		print_array(cout, p1, 7);

		cout << "Value of p2: " << p2 << endl;	
		//cout << "Content of p2: " << *p2 << endl;
		cout << "Content of p2: " <<endl;
		print_array(cout, p2, 7);

		delete[] p2;

		p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};		//új 10 tagu int felvétele p1-be megadott tagokkal
		p2 = new int [10];										//új 10 tagu int felvéttele/hely foglalása p2-be

		for (int i=0; i<10; i++)					//p1 átmásolása p2-be
		{
			p2[i]=p1[i];
		}

		/*
		cout <<"Content of p2: "<<endl;			//p2 kiírása
		print_array(cout, p2, 10);
		*/

		vector<int> v1(10);
		int x=1;
		for(int& v : v1)
			{
				v=x;
				x=x*2;		
			}

		/*for(int i: v1)				//v1 elemeinek kiírása
			cout<< i <<endl;
		*/

		vector<int> v2(10);

		for (int i=0; i<10; i++)				//v1 másolása v2-be			
		{
			v2[i]=v1[i];
		}

		/*for(int i: v2)					//v2 elemeinek kiírása						
			cout<< i <<endl;*/				


		delete[] p1;
		delete[] p2;




	return 0;

	}
	catch(exception& e)
	{
    	cerr << "Exception: " << e.what() << '\n';
   		return 1;
	}
	catch(...) 
	{    		
		cerr << "Unknown exception\n";
    	return 2;
    }
}