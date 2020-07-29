// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

int main()
{
	srand(time(NULL));// seeed for functions
	try {
		ofstream a;
		a.open("a.dat");
		if (!a.is_open()) throw "Unable to open file\n";
		ofstream b;
		b.open("b.dat");
		if (!b.is_open()) throw "Unable to open file\n";
		ofstream sz;
		sz.open("sz.dat");
		if (!sz.is_open()) throw "Unable to open file\n";
		//file handling

		int average = 1000;
		float k1= 0;//number of balls
		float k2 = 0;//number of balls
		float k3 = 0;
		Urn temp(5,0);
		 //a)b)
		for (int n = 5; n < 125; n++) 
		{
			k1 = 0;
			k2 = 0;
			k3 = 0;
			for (int av = 0; av < average; av++)
			{
				temp.isAtLeast(1);
				k1 = k1 + temp.thisBall();
				temp.isInOne(2);
				k2 = k2 + temp.thisBall();
				k3=k3+temp.howManyEmpt();

			}
			k1 = k1 / average;
			k2 = k2 / average;
			k3 = k3 / average;
			a << temp.thisUrns() << "\t" << k1 << endl;
			b << temp.thisUrns() << "\t" << k2 << endl;
			sz << temp.thisUrns() << "\t" << k3 << endl;
			temp.addUrn(1);
		}
		a.close();
		b.close();
		sz.close();
		return 0;
	}
	catch(...){}

}

