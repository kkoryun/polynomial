#pragma once
#include <string>
using namespace std;
typedef long long int64;
class monom
{

protected:
    int a;
	int64 sv;
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
			int  l =_str.find(variable, 0);
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
		delete pow;
	};
	monom(monom & tmp)
	{
		a = tmp.a;
		sv = tmp.sv;
		next = tmp.next;
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
		int A = 0, B = 0;
		int64 sva = sv, svb = tmp->getSv();
		while (sva != 0 || svb != 0) 
		{
			A   = sva % maxst;
			B   = svb % maxst;
			if ( (A + B) >= maxst ) return monom(0,-1);
			sva = sva / maxst;
			svb = svb / maxst;
		}
		result.a = a * tmp->a;
		result.sv = sv + tmp->sv;
		return result;
	}
	monom sum(monom * tmp) {
		monom result;
		if (sv == tmp->sv) result.a = a + tmp->a;

		return monom(0,-1);
	}
#pragma region getset
	void addMonom(monom * tmp) { next = tmp; }
	void setNext(monom * _next) { next = _next; };
	void setSv(int64 _sv) { sv = _sv; };
	void setA(int _a) { a = _a; };
	int getA() { return a; }
	int64 getSv() { return sv; }
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
		int64 k = 1, _sv = sv;
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
		if (a == 0)  return s;
		if (a == 1)  return s;
		if (a == -1) return ("-" + s);
		s = to_string(a) + s;
		return s;
	};
	~monom()
	{
		next = 0;
	}
};