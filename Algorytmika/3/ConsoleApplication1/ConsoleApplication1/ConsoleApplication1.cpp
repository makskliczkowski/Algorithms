

#include "pch.h"
#include "class.hpp"

int main()
{
	srand(time(NULL));
	try {
		//TESTY
		BigInteger a("50");
		BigInteger b("49");
		BigInteger c("2");
		BigInteger d(3);
		BigInteger e(5);
		cout << "a="; a.print();
		cout << "b="; b.print();
		cout << "c="; c.print();
		cout << "d="; d.print();
		cout << "e="; e.print();
		a.factorial();
		b.factorial();
		cout << "a=" << a << endl << "b=" << b << endl << "a/b=" << a / b;
		//cin >> e;cout << e << endl;
		int average = 50;
		int n_max = 300;
		Karatsuba(average, n_max, "times.dat");
		//KARATSUBA TIME CHECK----------------------------------
		
	}
	catch (string a) {
	}

	return 0;

}
