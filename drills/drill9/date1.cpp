#include "std_lib_facilities.h"

struct Date{
	int y; //year
	int m; //month
	int d; //day
};

void init_date(Date& dd, int y, int m, int d)	//dátum ellenörzés
{
	if (y > 0)
		dd.y = y;					//év ellenörzés (nagyobb-e mint 0)
		
		else error("Invalid year");
	if (m <= 12 && m > 0)			//hónap ellenőrzés (0 és 12 közé esik-e a szám)
		dd.m = m;
		
		else error("Invalid month");
	
	if (d > 0 && d <=31)			//nap ellenörzés (0 és 31 közé esik-e)
		dd.d = d;
		
		else error("Invalid day");
}

void add_day(Date& dd, int n) 		//megadott számú napokat ad egy dátumhoz
{
	dd.d += 1;
	if (dd.d > 31)
	{
		dd.m += 1;
		dd.d -= 31;
		if ( dd.m > 12)
		{
			dd.y += 1;
			dd.m -= 12;
		}
	}
}

int main()
{	

	Date today{1978, 6, 25};		//a mai dátum
	init_date(today, 1978, 6, 25);
	Date tomorrow;					//felvesszök a tommorrow változót
	tomorrow = today;				//értéket adunk a tommorrow vátozónak
	add_day(tomorrow, 1);			//1 napot adunk a tommorrowhoz tartozó dátumhoz
	cout << "Date: " << tomorrow.y << ". " << tomorrow.m << ". " << 
		tomorrow.d << "." << endl;

	Date invalid{2004, 13, -5};
	init_date(invalid, 2004, 13, -5);
	cout << "Date: " << invalid.y << ". " << invalid.m << ". " << 
		invalid.d << "." << endl;

	return 0;	
}