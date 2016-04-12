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
			if (cur->getA() == 0)
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
	void addMonom(string st, int maxSt, int nx) {
		monom *tmp = new monom(st, maxSt, nx);
		addMonom(tmp);
	};

	cyclelist(const cyclelist & tmp) 
	{
		/*monom * next = first, *cur1 = first , *cur2 = tmp.first ;
		while (first != next)
		{
			next = next->getNext();
			
			cur = next;
		}
		if (first == next)
		{
			first->setNext(0);
			delete first;
		}*/
	};
	cyclelist operator*  (      int         tmp) {
		cyclelist result(*this);
		monom * cur = first->getNext();
		while (cur != first)
		{
			cur->setA(cur->getA()*tmp);
			cur = cur->getNext();
		}
		return result;
	}
	cyclelist operator*  (const cyclelist & tmp) {
		/*cyclelist result(*this);
		monom * cur = first->getNext();
		while (cur != first)
		{
			cur->setA(cur->getA() * tmp);
			cur = cur->getNext();
		}
		return result;*/
	}
	cyclelist operator+  (const cyclelist & tmp) {
		
		cyclelist result(tmp) ;

		monom * cur = first->getNext();
		while (cur != first)
		{
			monom * copycur = new monom(*cur);
			result.addMonom(copycur);
		}
		return result;
	}
	cyclelist operator-  (const cyclelist & tmp) {

		/*cyclelist result = tmp.operator*(-1) ;
		result = result +  *this;

		return result;
*/
	}
	cyclelist & operator=(const cyclelist & tmp) {};

	~cyclelist() {
		monom * next = first->getNext(), * cur = first;
		while (next != first)
		{
			cur->setNext(0);
			delete cur;
			cur = next;
			next = next->getNext();
		}
		if (next == first)
		{
			cur->setNext(0);
			//delete cur;
		}
	};
};

