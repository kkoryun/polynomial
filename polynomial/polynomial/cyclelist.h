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
		first = new monom();
		first->setNext(first);

		monom *cur1 = tmp.first->getNext() , *cur2 = first ;
		
		while (cur1 != tmp.first)
		{
			monom *m = new monom(*cur1);
			cur2->setNext(m);
			cur1 = cur1->getNext();
			cur2 = m;
		}
		cur2->setNext(first);
		
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

		return result;*/

	}
	cyclelist & operator=(const cyclelist & tmp) {
	
		monom *cur1 = tmp.first->getNext(), *cur2 = first;

		while (cur1 != tmp.first)
		{
			monom *m = new monom(*cur1);
			cur2->setNext(m);
			cur1 = cur1->getNext();
			cur2 = m;
		}
		cur2->setNext(first);

		return(*this);
	};

	~cyclelist() {
		monom *p = first->getNext(), *last = first ,* next ;
		while (p != first) {
			p = p->getNext();
			last = p;
		}
		last->setNext(0);
		p = first;
		while (p!=0)
		{
			last = p;
			p = p->getNext();
			delete last;
		}
		/*
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
		*/
		
		

	};
};

