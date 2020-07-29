// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string>
int main()
{
	srand(time(NULL));
	int average = 100;
	const int tries = 100000;
	int num_elements = 1000;
	ofstream a;
	ofstream b;
	ofstream c;
	//file handling
	try {
		vector<double> geometric, oneOverK, constP;

		//a,c)-------------------------------------------
		for (int i = 0; i < 4; i++) {
			double p = 0.2 + i * 0.2;
			//a------------------------------------------
			geometric = geo(p, tries);
					
			//file a--------------------------------------
			a.open("a_"+to_string(float(p))+".dat");
			if (!a.is_open()) throw "Unable to open file\n";
			for (int j = 1; j < tries;j++)
			{
				a << j << "\t" << geometric[j] << endl;
			}
			//c-------------------------------------------
			constP = str_const_p(tries, num_elements, p);

			//file c---------------------------------------
			c.open("c_" + to_string(float(p)) + ".dat");
			if (!c.is_open()) throw "Unable to open file\n";
			for (int j = 1; j < num_elements; j++)
			{
				c << j << "\t" << constP[j] << endl;
			}
			a.close();
			c.close();
		}
		//b)----------------------------------------------
		oneOverK = str_1_o_k(tries, num_elements);
		//file b---------------------------------------
		b.open("b.dat");
		if (!b.is_open()) throw "Unable to open file\n";
		for (int j = 0; j < num_elements; j++)
		{
			b << j << "\t" << oneOverK[j] << endl;
		}
		b.close();

		return 0;
	}
	catch (...) {

	}


}

