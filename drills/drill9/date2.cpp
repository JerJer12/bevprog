#include "std_lib_facilities.h"


struct Date{
	int year, month, day;
	Date(int y, int m, int d);
	void add_day(int n);
};

Date::Date(int y, int m, int d)   //itt megírjuk a Date függvényt, ami a dátumot ellenőrzi
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

void Date::add_day(int n)		//itt írjuk meg az add_day függvényt, ami n darab napot ad a dátumhoz
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

		Date today{1978, 6, 25};		//felvesszük a today dátumot

		Date tomorrow = today; 			//felvesszük a tomorrow változott és értéket adunk neki

		//Date my_birthday {2020,12,31};

		//cout << "Date: " << today.year << ". " << today.month << ". " << today.day << ".\n";

		tomorrow.add_day(1);			//egy napot hozzá adunk a tommorrow vátozohoz

		cout << "Date: " << tomorrow.year << ". " 
			<< tomorrow.month << ". " << tomorrow.day << ".\n";

		//my_birthday.day++;

		//cout << "Date: " << my_birthday.year << ". " << my_birthday.month << ". " << my_birthday.day << ".\n";
		
		Date invalid{2004, 13, -5};			//hiba ellenőrzés
		cout << "Date: " << invalid.year << ". " << invalid.month << ". " << 
		invalid.day << "." << endl;

		return 0;
	}
	catch(exception& e){
		cerr << e.what() << endl;
		return 1;
	}
}