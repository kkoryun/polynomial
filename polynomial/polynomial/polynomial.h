#pragma once
#include "cyclelist.h"
class polynomial
{
private: 
	cyclelist pol;
	int maxSt;
	int nx;
public:
	polynomial(string s="",int maxst=10, int n=10) {
		maxSt = maxst;
		nx = n;
		
		s = s + "+";
		int l = s.length(), p = -1;
		string buf ,a="+-";
		int i = 1;
		while (l!=0) {
			while (p == -1)
			{
				p = a.find(s[i], 0);
				i++;
			}
			p = i-1;
			if (p > 0) {
				buf = s.substr(0, p);
				pol.addMonom(buf, maxst, n);
				s.erase(0, p+1);
			}
			l = s.length();
			p = -1;
			i = 1;
	     }
	};
	polynomial(const polynomial & tmp) {
		maxSt = tmp.maxSt;
		nx = tmp.nx;
		pol = tmp.pol;
	}
	polynomial & operator= (const polynomial & tmp)
	{
		pol = tmp.pol;
		maxSt = tmp.maxSt;
		nx = tmp.nx;

		return *this;
	}
	string toString()
	{
		return pol.toString(maxSt,nx);
	}
	void addMonom(string str)
	{
		pol.addMonom(str, maxSt, nx);
	}
	polynomial operator+(const polynomial & tmp)
	{
		polynomial copy;
		copy.pol = pol + tmp.pol;
		return copy;
	}
	polynomial operator-( polynomial & tmp)
	{
		polynomial copy;
		copy.pol = pol.operator-( tmp.pol);
		return copy;
	}
	polynomial operator*(const polynomial & tmp)
	{
		/*polynomial copy(*this);
		copy.pol = copy.pol.polpol(tmp.pol, maxSt);
		return copy;*/
	}
};

