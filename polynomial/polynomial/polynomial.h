#pragma once
#include "cyclelist.h"
class polynomial
{
private: 
	cyclelist pol;
	int maxSt;
	int nx;
public:
	polynomial(const polynomial & tmp) {
		maxSt = tmp.maxSt;
		nx = tmp.nx;
		pol = tmp.pol;
	}
	polynomial & operator= (const polynomial & tmp)
	{
		pol = tmp.pol;
		return *this;
	}
	string toString()
	{
		return pol.toString();
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
	polynomial operator*(const polynomial & tmp)
	{
		polynomial copy(*this);
		copy.pol = copy.pol.polpol(tmp.pol, maxSt);
		return copy;
	}

	~polynomial();
};

