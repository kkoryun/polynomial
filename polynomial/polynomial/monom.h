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
	monom() {
		a = 0;
		sv = -1;
		next = 0;
	}
	monom(int _a = 0, int _mem = -1) {};
	monom(string _str, int maxSt = 10, int nx = 10)
	{
		int *pow;
		pow = new int[nx];

		string *variable;
		variable = new string[nx];

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

					while ((l <= _str.length()) && (_str[l] >= '0') && (st[l] <= '9'))
					{
						p = p + st[l];
						_str.erase(l, 1);
					}
					if (_str.length() == 0)
					{
						pow[i] = 1;
					}
					else
					{
						_strerase(l, 1);
						string h = "";
						h = h + st[l];
						pow[i] = stoi(h);
						_strerase(l, 1);
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
			if (st == "-")
			{
				a = -1;
			}
			else
			{
				a = stoi(st);
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
	monom & operator=(monom & tmp) { a = tmp.a;
	sv = tmp.sv;
//	next = tmp.next;
	};
	
	string getMonomStr(int maxSt = 10) 
	{
		string st;
		st = "";
		if (a == 1)
		{
			st = "";
		}
		else
		{
			if (a == -1)
			{
				st = "-";
			}
			else
			{
				int k = 1;
				while (sv != 0)
				{
					int pow = sv%maxst;
					sv = sv / maxst;
					if (pow > 0)
					{
						st = "x" + to_string(nx - k) + st;
						if (_str.length() == 2)
						{
							if (pow > 1)
							{
								st = st + "^" + to_string(pow);
							}
						}
						else
						{
							if (pow > 1)
							{
								string j = "";
								j = j + "^" + to_string(pow);
								_strinsert(2, j);
							}
						}
					}
					k++;
				}
				if (st[1] == '0')
				{
					_strerase(1, 1);
				}
				string f = "";
				f = f + to_string(a);
				_strinsert(0, f);
			}
		}

		return st;
	};
	~monom() { next = 0; }
	void addMonom(monom * tmp) { next = tmp; }
	void setNext(monom * _next) { next = _next; };
	void setSv(int _sv) { sv = _sv; };
	void setA(int _a) { a = _a; };
	int getA() { return a; }
	int getSv(){ return sv;}
	monom * getNext() { return next; }

	

};