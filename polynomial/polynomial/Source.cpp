#include"monom.h"
#include<iostream>
void main() 
{
	monom * m1,*m2 , *m3 , *m4;
	monom m("-35x4^5x3^2x1",10,4);

	cout << m.getA() << " "<<m.getSv()<< endl;
	cout << m.getMonomStr(10,4) << endl;
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