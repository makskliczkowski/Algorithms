#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;
int main()
{

	//b)Wykonaj swój algorytm dla danych rozmiaru n = 100, 200, . . . , 1000. Narysuj wykres liczby wykonanych porówna« w zalez»nosci od n. Wyciagnij wnioski.	
	try
	{
		srand(time(NULL));// seeed for functions

		ofstream time;
		time.open("timea.txt");
		if (!time.is_open())
		{
			string g = "Unable to open file";
			throw g;
		}//files 

		int n = 100;
		float *a = new float[2];//for information about time(optional)
		for (int i = n; i <= 1000; i = i + 100)
		{
			float *table = new float[i];
			//sorting for different random tables
			table = Randomise_Table(table, i);
			a = Insertsort_up(table, i);
			time << a[0] << " " << i << "\n";
			delete[] a;
			delete[] table;
		}
		time.close();
	}
	catch(string)
	{
		return -1;
	}
	return 0;
}