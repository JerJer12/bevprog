#include "std_lib_facilities.h"

//-------------------------------------------

//Nevek rendelelése a karakterekhez

constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char square_root = '@';
constexpr char power = 'T';

const string declkey = "let";
const string sqrtkey = "sqrt";
const string powkey = "pow";
const string exitkey = "exit";

//-------------------------------------------

double expression();			//létrehozzuk az expression függvényt
double primary();				//létrehozzuk a primaryfüggvényt

class Variable{					//változóhoz szükséges struktúra létrehozása
public:
	string name;
	double value;
};

vector<Variable> var_table;

//-------------------------------------------

bool is_declared(string var){		//megadja, hogy létezik-e az adott változó 
	for (const auto& v : var_table)
		if (v.name == var) return true;
	return false;
}

//-------------------------------------------

double define_name(string var, double val)		//beleteszi a vektorba a változót
{		
	if (is_declared(var)) error("Variable is already declared: ", var);
	var_table.push_back(Variable{var,val});
	return val;
}

//-------------------------------------------

double get_value(string s){				//a már létrehozott változó értékét adja vissza
	for (const auto& v : var_table)
		if ( v.name == s ) return v.value;
	error("get: variable not defined", s);
	return 2;
}

//-------------------------------------------

void set_value(string s, double d){		//értéket rendel az adott változóhoz
	for ( auto& v : var_table )
		if ( v.name == s )
		{
			v.value = d;
			return;
		}
	error( "set: variable not defined", s);
}

//-------------------------------------------

class Token 			//létrehozza a kód során használatos token típusokat
{
public:
	char kind;
	double value;
	string name;
	Token (): kind(0) {}
	Token (char ch): kind(ch), value(0) {}
	Token (char ch, double val): kind(ch), value(val) {}
	Token (char ch, string n): kind(ch), name(n) {}
};

//-------------------------------------------

class Token_stream		//létrehozza a token streamben használatos függvényeket
{
public:
	Token_stream();
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

//-------------------------------------------

Token_stream::Token_stream(): full(false), buffer(0) {}

void Token_stream::putback(Token t)		//visszateszi a tokent a token streambe
{
	if (full) error("Token_stream buffer full");
	buffer = t;
	full = true;
}

//-------------------------------------------

Token Token_stream::get()		
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch(ch)
	{
		case 'q':
		case ';':
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
		case ',':
			return Token(ch);
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token(number, val);
		}

		default:
		{
			if (isalpha(ch))
			{
				string s;
				s += ch;
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
				cin.putback(ch);
				if (s == declkey ) return Token{let};
				else if ( s == sqrtkey ) return Token{square_root};
				else if ( s == powkey ) return Token{power};
				else if (is_declared(s))
					return Token(number, get_value(s));
				return Token{name,s};
			}

			error("Bad token");
		}
	}
	return 1;
}

//-------------------------------------------

void Token_stream::ignore(char c)		//adott karakterig megy, ha azt eléri akkor visszatér
{
	if ( full && c == buffer.kind ){
		full = false;
		return;
	}

	full = false;

	char ch = 0;
	while ( cin >> ch )
		if ( ch == c ) return;


}

Token_stream ts;		//létrehozzuk a ts nevű token streamet

//-------------------------------------------

double calc_sqrt()		//négyzetgyököt számolás
{
	char ch;
	if (cin.get(ch) && ch != '(') error("'(' expected");		
	cin.putback(ch);
	double d = primary();
	if (d < 0) error("sqrt: negative value");
	return sqrt(d);
}

//-------------------------------------------

double calc_power()		//hatványozás
{
	char ch;
	if (cin.get(ch) && ch != '(') error("'(' expected");		
	cin.putback(ch);
	double d = expression();
	return d;
}

//-------------------------------------------

double primary()		//lekezeli a zárójelezést és a negatív számokat
{
	Token t = ts.get();
	switch(t.kind)
	{	
		case square_root:
			return calc_sqrt();
		case power:
			return calc_power();
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error ("')' expected");
			return d;
		}
		case number:
			return t.value;
		case '-':
			return - primary();
		case '+':
			return primary();
		default:
			error ("primary expected");
			return 0;
	}
}

//-------------------------------------------

double term()		//lekezeli a szorzást, az osztást és a maradékképzést
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch(t.kind)
		{
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if ( d == 0 )error("division by zero");
				left /= d;
				t = ts.get();
				break;
			}
			
			case '%':
			{
				double d = primary();
				if ( d==0 ) error("divide by zero");
				left = fmod(left, d);
				t = ts.get();
				break;
			}

			default:
				ts.putback(t);
				return left;
		}
	}
}

//-------------------------------------------

double expression()		//lekezeli az összeadást és a kivonást
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch(t.kind)
		{
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			case ',':
			{
				double i = expression();
				i = narrow_cast<int>(i);
				left = pow(left, i);
				return left;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

//-------------------------------------------

void clean_up_mess(){		//hívja az ignore függvényt, ami eltekint a felesleges ';'-őktől
	ts.ignore(print);
}

//-------------------------------------------

double declaration(){		//inicializálja a beírt változót
	Token t = ts.get();
	if ( t.kind != name ) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if ( t2.kind != '=') error("= expected in declaration");

	double d = expression();
	define_name(var_name, d);
	return d;
}

//-------------------------------------------

double statement(){		//változó esetén a declaration, más esetben az expression függvényt hívja meg
	Token t = ts.get();
	switch(t.kind){
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}

//-------------------------------------------

void calculate()		//elvégezteti a számolást függvényekkel
{
	while (true)
		try
		{
			Token t = ts.get();

			while ( t.kind == print ) t = ts.get();
			if (t.kind == quit) {
				return;
			}
			ts.putback(t);
			cout << '=' << statement() << endl;
		} catch(exception& e){
			cerr << e.what() << endl;
			clean_up_mess();
		}
}

//-------------------------------------------

int main()			//hívja a calculate függvényt, illetve inputot ad
{
	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers." <<
		"\nThe available operators are: '+', '-', '*', '/', '%', sqrt(), pow().\nTo print write ';', to exit write 'q'!\nYou can also use pi, e and k!" << 
		" If you want to declare a variable write 'let' (for example: let x = 15)\nWe can only raise a number to the power of an integer!\n" << endl;
	try
	{	
		define_name("pi", 3.1415926535);
		define_name("e", 2.7182818284);
		define_name("k", 1000);
		calculate();

		return 0;

	}
		catch(exception& e){
			cerr << e.what() << endl;
			return 1;
		}

		catch(...){
			cerr << "exception" << endl;
			return 2;
		}
}

//-------------------------------------------