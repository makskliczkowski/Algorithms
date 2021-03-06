
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cmath>

using namespace std;
int main()
{
	srand(time(NULL));// seeed for functions

	try {
		//-------------------------a--------------------------------------------------
		ofstream time;
		time.open("timea.txt");
		if (!time.is_open())
		{
			string g = "Unable to open file";
			throw g;
		}//file handling 
		//-------------														----------
		int n = 100;
		int iterations = 50000;
		float *a = new float[iterations]; //for steps 
		float *table = new float[n];//new table
		
		a = Insertsort_up(table, n,iterations);
		for (int i = 0; i < iterations; i++)//sorting up for different random tables
		{
			time << a[i] << "\n";
		}
		time.close();
		delete[] a;
		delete[] table;
		//------------------------b------------------------------------------------------
		time.open("timeb.txt");
		if (!time.is_open())
		{
			string g = "Unable to open file";
			throw g;
		}//file
		//--------------												-----------------
		//int steps;//for counting steps
		//int average = 10;
		a = new float[2]; //for steps 
		for (int i = n; i <= 1000; i = i + 100)
		{
			//steps = 0;
			float *table = new float[i];
			//sorting for different random tables
			table = Randomise_Table(table, i);
			a = Insertsort_up(table, i);
			time << a[0] << "\t" << sqrt(a[0]) << "\t" << i << "\n";
		}
		time.close();
		delete[] a;
	}
	catch(string)
	{
		return -1;
	}
	return 0;
}

