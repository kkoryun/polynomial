#pragma once
#include <string>
using namespace std;
class monom
{

protected:
	int a;
	int sv;
	monom * next;

public:
#pragma region constructors
	monom() {
		a = 0;
		sv = -1;
		next = 0;
	}
	monom(int _a, int _sv)
	{
		a = _a;
		sv = _sv;
	};
	monom(string _str, int maxSt = 10, int nx = 10)
	{
		int * pow = new int[nx];
		string  variable = "";
		for (int i = 0; i < nx; i++)
		{
			pow[i] = 0;
			variable = "x" + to_string(i + 1);
			int l = _str.find(variable, 0);
			if (l >= 0)
			{
				_str.erase(l, variable.length());
				if (l < _str.length() && _str[l] == '^')
				{
					_str.erase(l, 1);
					string h = "";
					while ((_str.length() > 0) && (l < _str.length()) && (_str[l] >= '0') && (_str[l] <= '9'))
					{
						h = h + _str[l];
						_str.erase(l, 1);
					}
					pow[i] = stoi(h);
				}
				else
				{
					pow[i] = 1;
				}
			}

		}
		if (_str.length() == 0)
		{
			a = 1;
		}
		else
		{
			if (_str == "-")
			{
				a = -1;
			}
			else
			{
				a = stoi(_str);
			}
		}

		sv = 0;
		for (size_t i = 0; i < nx - 1; i++)
		{
			sv = (sv + pow[i])* maxSt;
		}
		sv += pow[nx - 1];

	};
	monom(monom & tmp)
	{
		a = tmp.a;
		sv = tmp.sv;
		next = 0;
	};
#pragma endregion

	monom & operator=(monom & tmp) {
		a = tmp.a;
		sv = tmp.sv;
		next = tmp.next;
		return *this;
	};

	monom multipli(monom * tmp, int maxst) {

		monom result;
		int a = 0, b = 0;
		int sva = sv, svb = tmp->getSv();
		while (sva != 0 || svb != 0) {
			a = sva % maxst;
			b = svb% maxst;
			if ((a + b) >= maxst) return result;
			sva = sva / maxst;
			svb = svb / maxst;
		}
		result.a = a * tmp->a;
		result.sv = sv + tmp->sv;
		return result;
	}
#pragma region getset
	void addMonom(monom * tmp) { next = tmp; }
	void setNext(monom * _next) { next = _next; };
	void setSv(int _sv) { sv = _sv; };
	void setA(int _a) { a = _a; };
	int getA() { return a; }
	int getSv() { return sv; }
	monom * getNext() { return next; }
	string getMonomStr(int maxSt = 10, int nx = 10)
	{
		string s = "";
		if (a == -1)
		{
			s = "-" + toString(maxSt, nx);
		}
		else
		{
			s = toString(maxSt, nx);
			if (a != 0) {
				s = to_string(a) + s;
			}
			else
			{
				s = "0";
			}
		}
		return s;
	};
#pragma endregion
	string toString(int maxSt = 10, int nx = 10) {
		int k = 1, _sv = sv;
		string s = "";
		while (_sv != 0)
		{
			string st = "";
			int pow = _sv % maxSt;
			if (pow > 0)
			{
				st = "x" + to_string(nx - k + 1);
				if (pow > 1)
					st += "^" + to_string(pow);

				s = st + s;

			}
			k++;
			_sv /= maxSt;
		}
		return s;
	};
	~monom()
	{
		next = 0;
	}
};