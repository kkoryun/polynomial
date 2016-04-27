#pragma once
#include "cyclelist.h"
class polynomial
{
private:
	cyclelist polynom;
	int maxSt;
	int nx;
public:
	polynomial(string s = "", int maxst = 10, int n = 10) {
		maxSt = maxst;
		nx = n;
		
		s = s + "+";

		int  l = s.length(), p = -1;
		string buf, a = "+-";
		int i = 1;
		while (l > 1) {
			while (p == -1)
			{
				p = a.find(s[i], 0);
				i++;
			}
			p = i - 1;
			if (p > 0) {
				buf = s.substr(0, p);
				polynom.addMonom(delplus(buf) , maxst, n);
				s.erase(0,p);
			}
			l = s.length();
			p = -1;
			i = 1;
		}
	};
	polynomial(const polynomial & tmp) {
		maxSt = tmp.maxSt;
		nx = tmp.nx;
		polynom = tmp.polynom;
	}

	string toString()
	{
		return polynom.toString(maxSt, nx);
	}
	void addMonom(string str)
	{
		polynom.addMonom(str, maxSt, nx);
	}

	polynomial & operator=(const polynomial & tmp)
	{
		polynom = tmp.polynom;
		maxSt = tmp.maxSt;
		nx = tmp.nx;

		return *this;
	}
	polynomial   operator+(const polynomial & tmp)
	{
		polynomial copy;
		copy.polynom = polynom + tmp.polynom;
		return copy;
	}
	polynomial   operator-(polynomial & tmp)
	{
		polynomial copy;
		copy.polynom = polynom - tmp.polynom;
		return copy;
	}
	polynomial   operator*(const polynomial & tmp)
	{
		polynomial copy;
		copy.polynom = polynom * tmp.polynom;
		return copy;
	}
	polynomial   operator*(const int & tmp)
	{
		polynomial copy;
		copy.polynom = polynom * tmp;
		return copy;
	}
	string delplus(string buf) {
		string s(buf);
		int p = s.find("+", 0);
		if (p==0)
		s.erase(0,1);
		return s;
	}
};

