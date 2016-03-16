#pragma once
#include "monom.h"

class cyclelist : public monom

{
private: 
	monom * first;
public:
	cyclelist();

	cyclelist(const cyclelist & tmp) {};
	cyclelist operator*(int tmp) {
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
	cyclelist operator- (const cyclelist & tmp) {

		cyclelist result = tmp * (-1) ;
		result = result +  *this;

		return result;

	}


	~cyclelist();
};

