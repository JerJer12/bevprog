#include "std_lib_facilities.h"

struct Point{
	int x;
	int y;
};

bool differ(vector<Point> v, vector<Point> u)
{	
	if (v.size() != u.size())	//comparing the size of two vectors
		return true;

	int el = 0;
	while(el != u.size())
	{
		if ( v[el].x != u[el].x || v[el].y != u[el].y ) //comparing the elements of two vectors
			return true;
			break;
		el += 1;
	}

	return false;
}

int main()
{
	try{

		vector<Point> original_points;

		cout << "Please enter seven (x,y) pairs!" << endl;
		int z = 0;
		while(z < 7)
		{	
			int x, y;
			cin >> x >> y;
			original_points.push_back(Point{x, y});
			z += 1;
		}

		cout << "Please enter the name of the output file (preferably with .txt suffix!): ";
		string oname;
		cin >> oname;
		ofstream ost{oname};
		if (!ost) error("can't open output file ", oname);

		for (const auto& p: original_points)
			ost << p.x << ' ' << p.y << "\n";

		ost.close();

		cout << "Please enter input file name: ";
		string iname;
		cin >> iname;

		ifstream ist {iname};

		if (!ist) error ("can't open input file ", iname);

		vector<Point> processed_points;
		int x;
		int y;
		while (ist >> x >> y){
			processed_points.push_back(Point{x, y});
		}

		for (const auto& p: original_points)
			cout << p.x << ' ' << p.y << "\n";

		cout << endl;

		for (const auto& p: processed_points)
			cout << p.x << ' ' << p.y << "\n";

		if(differ(original_points, processed_points))
			cout << "Something's wrong!" << endl;

		
		
		return 0;
	}
	catch(runtime_error& e){
		cout << "Error: " << e.what() << endl;
		return 1;
	}
	catch(...){
		cout << "Some error happened\n";
		return 2;
	}
}
