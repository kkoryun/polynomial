#include"monom.h"
#include"cyclelist.h"
#include<conio.h>
#include<iostream>
#include"polynomial.h"
void main() 
{
	//monom * m1,*m2 , *m3 , *m4;
	monom m1("-35x4^5x3^2x1",10,4);
	monom m2("x4^4x3^2", 10, 4);
	monom m3("x4^5x1", 10, 4);
	monom m4;
	cyclelist c;
//	m4 = m2.multipli(&m1, 10);
	c.addMonom(&m1);
	c.addMonom(&m2);
	c.addMonom(&m3);

	cyclelist c1, c2(c) ;
	c1 = cyclelist(c);

	//c = c1 * 5;
    //c2 = c1 * c;
	
	polynomial p1("6x1^2x3^3-2x2^4x3^2"/*+5x2x5^3x7*/, 10, 10) , p2("x1^2x5^3-4x2^4x3^2"/*+3x2x5^4x7*/,10,10);
	polynomial p;
	p = p1*p2;
	p = p1 + p2;
	p = p1 - p2;
	string s ="polynom " + p.toString();
	cout << "6x1^2x3^3-2x2^4x3^2\n";
	cout << "x1^2x5^3-4x2^4x3^2 \n";
	cout << s;
//	cout << m4.getA() << " "<<m4.getSv()<< endl;
	//cout << m1.getMonomStr(10,4) << endl;
	//string s;
	//m1 = new monom(10, 123);
	//m2 = new monom(-1, 321);
	//m3 = new monom();
	//*m3 = *m2;
	//
	//
	//m1->setNext(m2);
	//s = "";
	//s = m2->getMonomStr(10);
	//cout << s << "\n";
	//
	//s = "";
	//s = m1->getMonomStr(10);
	//cout << s << "\n";
	//
	//s = "";
	//s = m3->getMonomStr(10);
	//cout << s << "\n";
	//
	//m4 = new monom(0,476);
	//s = "";
	//s = m4->getMonomStr(10);
	//cout << s << "\n";
	
	_getch();
}