#pragma once
#include "monom.h"

class cyclelist : public monom

{
private: 
	monom * first;
public:
	cyclelist()
	{
		first = new monom();
		first->setNext(first);
	};
	void addMonom(monom * tmp) 
	{
		monom * prev = first;
		monom * cur = first->getNext();
		while (cur->getSv() > tmp->getSv())
		{
			prev = cur;
			cur = cur->getNext();
		}
		if (cur->getSv() < tmp->getSv())
		{
			prev->setNext(tmp);
			tmp->setNext(cur);
		}
		else
		{
			cur->setA(cur->getA() + tmp->getA());
			if (cur->getA == 0)
			{
				prev->setNext(cur->getNext());
				cur->setNext(0);
				delete cur;
			}
		}
	};
	void addMonom(int sv, int a) 
	{
		monom * tmp = new monom(a, sv);
		addMonom(tmp);
	};
	void addMonom(string st, int maxSt, int count) {};

	cyclelist(const cyclelist & tmp) 
	{
		first = tmp.first;
		monom *p1 = first, *p2 = tmp.first, *t;
		
		while ( t = p2->getNext() )
		{
			p1->setNext(t);
			p1 = p1->getNext();
			p2 = p2->getNext();
		}
	};
	cyclelist operator* (      int         tmp) {
		cyclelist result(*this);
		monom * cur = first->getNext();
		while (cur != first)
		{
			cur->setA(cur->getA()*tmp);
			cur = cur->getNext();
		}
		return result;
	}
	cyclelist operator+ (const cyclelist & tmp) {
		
		cyclelist result(tmp) ;

		monom * cur = first->getNext();
		while (cur != first)
		{
			monom * copycur = new monom(*cur);
			result.addMonom(copycur);
		}
		return result;
	}
	cyclelist operator- (      cyclelist   tmp) {

		cyclelist result = tmp * (-1) ;
		result = result +  *this;

		return result;

	}
	cyclelist & operator=(const cyclelist & tmp) {};

	~cyclelist();
};

