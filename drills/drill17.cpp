#include "std_lib_facilities.h"

ostream& print_array10(ostream& os, int* a) //kiírja az int a elemeit (tegyük fel, hogy 10 elem van)
{
	for(int i = 0; i < 10; ++i)
		os << a[i] << endl;
	return os;
}

ostream& print_array(ostream& os, int* a, int n) //-||- (tegyük fel hogy n elem van)
{
	for(int i = 0; i < n; ++i)
		os << a[i] << endl;
	return os;
}

ostream& print_vector(ostream& os, vector<int>& v)
{
	for(int x : v)
		os << x << endl;
	return os;
}

int main()
{	
	try{
		int* a = new int[10];
		print_array10(cout, a);
		delete[] a;
		
		int* b = new int[10] { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
		print_array10(cout, b);
		delete[] b;

		int* c = new int[11] { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
		print_array(cout, c, 11);
		delete[] c;

		int* d = new int[20] { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
		print_array(cout, d, 20);
		delete[] d;

		
		vector<int> v1(10);			//vektor felvétel és feltöltés
		int y = 100;
	    for (int& v : v1) {
	        v = y;
	        ++y;
	    }
	    print_vector(cout, v1);

	    
	    vector<int> v2(11);
	    int z = 100;
	    	for (int& v : v2) 
	    	{
	        	v = z;
	        	++z;
	    	}
		print_vector(cout, v2);   

		
		vector<int> v3(20);
		int x = 100;
	    	for (int& v : v3) 
	    	{
	        	v = x;
	        	++x;
	    	}
		print_vector(cout, v3);

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