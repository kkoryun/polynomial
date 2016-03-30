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
	monom(int _a , int _sv ) 
	{
		a = _a;
		sv = _sv;
	};
	monom(string _str, int maxSt = 10, int nx = 10)
	{
		int * pow = new int[nx];

		string * variable = new string[nx];

		for (int i = 0; i < nx; i++)
		{
			pow[i] = 0;
			if (i == 0)
			{
				variable[i] = "x";
			}
			else
			{
				variable[i] = "x" + to_string(i);
			}
			int l = _str.find(variable[i], 0);
			_str.erase(l, variable[i].length());
			if (_str[l] == '^')
			{
				_str.erase(l, 1);
				string h = "";
				h = h + _str[l];
				pow[i] = stoi(h);
				_str.erase(l, 1);
			}
			else
			{
				if (i == 0)
				{
					if (_str[l] == 'x')
					{
						pow[i] = 1;
					}
					else
					{
						pow[i] = 1;
						_str.erase(l, 1);
					}
				}
				else
				{
					//_strerase(l, 2);
					string p = "";

					while ((l <= _str.length()) && (_str[l] >= '0') && (_str[l] <= '9'))
					{
						p = p + _str[l];
						_str.erase(l, 1);
					}
					if (_str.length() == 0)
					{
						pow[i] = 1;
					}
					else
					{
						_str.erase(l, 1);
						string h = "";
						h = h + _str[l];
						pow[i] = stoi(h);
						_str.erase(l, 1);
					}

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
		for (int i = 0; i < nx; i++)
		{
			sv = sv * 10 + pow[i];
		}
		next = 0;

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
#pragma endregion
	string getMonomStr(int maxSt = 10)
	{
		string s;
		s = "";
		if (a == 1)
		{
			s = "";
		}
		else
		{
			if (a == -1)
			{
				s = "-" + toString(maxSt);

			}
			else
			{
				s = toString(maxSt);
				if (a != 0) {
					string f = to_string(a);
					s.insert(0, f);
				}
				else
				{
					s = "0";
				}
			
			}
		}

		return s;
	};
  
	string toString(int maxSt=10) {
		int k = 1 , _sv = sv;
		string s="";
		while (_sv != 0)
		{
			int pow = _sv % maxSt;
			if (pow > 0)
			{
				s += "x" + to_string(k);
				if (pow >= 1)
					s += "^" + to_string(pow) + "*";
			}
			k++;
			_sv /= maxSt;
		}
		s.erase(s.length() - 1);
		return s;
	};
	~monom() { next = 0; }
};