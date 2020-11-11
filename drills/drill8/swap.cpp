#include "std_lib_facilities.h"

void swap_v(int a,int b)	//Ez a függvény tulajdonképpen nem csinál semmit xD
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int x = 7;
	int y = 9;

	cout << "x=" << x << " y=" << y << endl;

	swap_v(x,y);

	cout << "x=" << x << " y=" << y << endl;

	swap_v(7,9);

	const int cx = 7;
	const int cy = 9;

	cout << "x=" << cx << " y=" << cy << endl;

	swap_v(cx,cy);

	cout << "x=" << cx << " y=" << cy << endl;

	swap_v(7.7,9.9);

	double dx = 7.7;
	double dy = 9.9;

	cout << "x=" << dx << " y=" << dy << endl;

	swap_v(dx,dy);

	cout << "x=" << dx << " y=" << dy << endl;

	swap_v(7.7,9.9);

	return 0;
	}