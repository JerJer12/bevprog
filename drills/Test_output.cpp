#include "std_lib_facilities.h"

int main()
{	
	int birth_year = 2001; 
	cout << showbase << dec << birth_year << "\t(decimal)\n" 
		<< showbase << hex << birth_year << "\t(hexadecimal)\n" 
		<< showbase << oct << birth_year << "\t(octal)\n";

	cout << endl << dec << "Age: " << 19 << endl;

	int a, b, c, d;
	cout << "\nEnter four numbers!" << endl;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << "\nThe first number in decimal:\n" << a 
		<< "\nThe second number in octal:\n" << b 
		<< "\nThe third and the forth numbers in hexadecimal:\n" 
		<< c << '\t' << d << '\n';

	cout << noshowbase << dec;
	cout << '\n' << 1234567.89 << "\t(defaultfloat)\n"
		<< fixed << 1234567.89 << "\t(fixed)\n"
		<< scientific << 1234567.89 << "\t(scientific)\n";
	
	cout << '\n' << '|' << setw(10) << "Bence" << '|' << setw(11) << "Teremi" 
        << '|' << setw(30) << "teremibence@gmail.com"
        << '|' << setw(16) << "(012) 123-5675" << "|\n"
        << '|' << setw(11) << "Bence" << '|' << setw(11) << "Toth"
        << '|' << setw(30) << "tozsy@gmail.com"
        << '|' << setw(16) << "(012) 310-2874" << "|\n"
   		<< '|' << setw(10) << "Gábor" << '|' << setw(12) << "Rostás" 
        << '|' << setw(30) << "gabe@gmail.com"
        << '|' << setw(16) << "(012) 532-4234" << "|\n"
        << '|' << setw(10) << "Ádám" << '|' << setw(12) << "Geccse"
        << '|' << setw(30) << "gecse@gmail.com"
        << '|' << setw(16) << "(012) 387-9853" << "|\n"
    	<< '|' << setw(10) << "Andrea" << '|' << setw(13) << "Lörincz" 
        << '|' << setw(30) << "andishrek@gmail.com"
        << '|' << setw(16) << "(012) 555-8346" << "|\n"
        << '|' << setw(12) << "Petra" << '|' << setw(13) << "Dragos"
        << '|' << setw(31) << "dragos@gmail.com"
        << '|' << setw(16) << "(012) 043-9876" << "|\n"
    	<< '|' << setw(11) << "Viktor" << '|' << setw(13) << "Présel" 
        << '|' << setw(30) << "protolyt@gmail.com"
        << '|' << setw(16) << "(012) 456-7783" << "|\n"
        << '|' << setw(11) << "Kriszti" << '|' << setw(11) << "Gyömbér"
        << '|' << setw(30) << "gykriszti@gmail.com"
        << '|' << setw(16) << "(012) 345-9467" << "|\n";

	return 0;
}