#include "std_lib_facilities.h"

void swap_v(int a, int b)
	{ int temp; temp = a, a = b; b = temp; }

void swap_r(int& a, int& b)
	{ int temp; temp = a, a = b; b = temp; }

/*void swap_cr(const int& cx, const int& cy)
	{ int temp; temp = cx, cx = cy; cy = temp; }*/

void swap_d(double& a, double& b)
	{ double temp; temp = a, a = b; b = temp; }

void swap_d1(double a, double b)
	{ double temp; temp = a, a = b; b = temp; }

int main()
{
	int x = 7;
	int y =9;
	swap_r(x,y);

	cout<< x <<endl;
	cout<< y <<endl;

	swap_v(7,9);

	cout<< x <<endl;
	cout<< y <<endl;

	/*const int cx = 7;
	const int cy = 9;
	swap_v(cx,cy);
	
	cout<< cx <<endl;
	cout<< cy <<endl;*/

	swap_d1(7.7,9.9);

	
	
	double dx = 7.7;
	double dy = 9.9;
	swap_d(dx,dy);

	cout<< dx <<endl;
	cout<< dy <<endl;

	
	swap_d1(7.7,9.9);

	cout<< dx <<endl;
	cout<< dy <<endl;



	return 0;
}