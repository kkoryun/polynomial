#include"monom.h"
#include"cyclelist.h"
#include<iostream>
void main() 
{
	//monom * m1,*m2 , *m3 , *m4;
	monom m1("-35x4^5x3^2x1",10,4);
	monom m2("x4^5x3^2", 10, 4);
	monom m3("x4^5x1", 10, 4);
	
	cyclelist c;

	c.addMonom(&m1);
	//c.addMonom(&m2);
	//c.addMonom(&m3);
	//cout << m1.getA() << " "<<m1.getSv()<< endl;
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
	
	system("pause");
}