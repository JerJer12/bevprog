#include "std_lib_facilities.h"

class Date {
	int year, month, day;			//year, month, day
public:
	Date(int y, int m, int d);		//ellenörzi, hogy létezik-e a dátum
	void add_day(int n);			// n darab nappal növeli a dátumot
	int get_year(){ return year; }
	int get_month(){ return month; }
	int get_day(){ return day; }
};

Date::Date(int y, int m, int d)		//itt írjuk meg a Date függvényt
{
	if (y > 0)
		year = y;

		else error("Invalid year");

	if (m <= 12 && m > 0)
		month = m;

		else error("Invalid month");
	
	if (d > 0 && d < 32)
		day = d;

		else error("Invalid day");
}

void Date::add_day(int n)		//itt írjuk meg az add_day függvényt
{
	day += n;
	if (day > 31)
	{
		month += 1;
		day -= 31;
		if ( month > 12)
		{
			year += 1;
			month -= 12;
		}
	}
}

int main()
{
	try{

		Date today{1978, 6, 25};

		Date tomorrow = today;

		//cout << "Date: " << today.get_year() << ". " << today.get_month() << ". " << today.get_day() << ".\n";

		tomorrow.add_day(1);

		cout << "Date: " << tomorrow.get_year() << ". " 
			<< tomorrow.get_month() << ". " << tomorrow.get_day() << ".\n";

		Date invalid{2004, 13, -5};
		cout << "Date: " << invalid.get_year() << ". " << invalid.get_month() 
			<< ". " << invalid.get_day() << "." << endl;

		return 0;
	}
	catch(exception& e){
		cerr << e.what() << endl;
		return 1;
	}
}