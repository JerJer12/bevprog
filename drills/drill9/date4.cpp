#include "std_lib_facilities.h"

class Year {
	static constexpr int min = 1800;
	static constexpr int max = 2200;
	int y;
public:
	class Invalid{};
	Year (int x): y{x} { if (x<min || x>max) throw Invalid{}; }
	int year(){ return y; }
	void increment() { y++; }	
};

Year operator++(Year& year)
{
	year.increment();
	return 0;
}

ostream& operator<< (ostream& os, Year year)
{
	return os << year.year();
}

const vector<string> months = 
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

enum class Month {
	jan, feb, mar, apr, may, june, july, aug, sept, oct, nov, dec
};

Month operator++(Month& m)
{
	m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}

class Date {
	Year year;
	Month month;
	int day;
public:
	class Invalid {};
	Date(Year y, Month m, int d): year(y), month(m), day(d) { if (!is_valid()) throw Invalid {}; }
	bool is_valid();
	void add_day(int n);
	Year get_year(){ return year; }
	Month get_month(){ return month; }
	int get_day(){ return day; }
};

bool Date::is_valid()
{
	if (day < 1 || day > 31) return false;
	return true;
}

void Date::add_day(int n)
{
	day += n;
	if (day > 31) 
	{
		++month;
		day -= 31;
		if (month == Month::jan)
		{
			++year;
		}
	}
}

int main()
try {
	Date today {Year{1978}, Month::june, 25};

	Date tomorrow = today;

	//cout << "Date: " << today.get_year() << ". " << today.get_month() << " " << today.get_day() << ".\n";

	tomorrow.add_day(1);

	cout << "Date: " << tomorrow.get_year() << ". " 
		<< tomorrow.get_month() << " " << tomorrow.get_day() << ".\n";

	//Date my_birthday {Year{2020},Month::dec,31};

	//cout << "Date: " << my_birthday.get_year() << ". " << my_birthday.get_month() << " " << my_birthday.get_day() << ".\n";

	//my_birthday.add_day(1);

	//cout << "Date: " << my_birthday.get_year() << ". " << my_birthday.get_month() << " " << my_birthday.get_day() << ".\n";

	Date invalid{Year{2004}, Month::june, -5};
		cout << "Date: " << invalid.get_year() << ". " << invalid.get_month() 
			<< ". " << invalid.get_day() << "." << endl;


	return 0;

} catch (Date::Invalid) {
	cout << "Error: Invalid date\n";
	return 1; 
} catch (Year::Invalid) {
	cout << "Error: Invalid year\n";
	return 2; 
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 3;
}