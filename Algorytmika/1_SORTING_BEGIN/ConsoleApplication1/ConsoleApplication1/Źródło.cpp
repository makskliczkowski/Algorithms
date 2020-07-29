#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;
int main()
{
	srand(time(NULL));// seeed for functions
	int n = 100;
	ofstream tables;
	ofstream time;
	float *a = new float[2];//for information about time(optional)
	for (int i = 100; i <= 1000; i+100)
	{
		char *h = new char[30];
		snprintf(h, 30, "table%d.txt", i);
		tables.open(h);
		delete[] h;
		if (!tables.is_open())
		{
			cout << "Unable to open file";
			return -1;
		}
		time.open("timeb.txt");
		if (!time.is_open())
		{
			cout << "Unable to open file";
			return -1;
		}
		//creating table
		float *table = new float[i];
		//sorting for different tables
	
		table = Randomise_Table(table,i);
		for (int k = 0; k < i; k++)
			{
				tables << table[k] <<"\t";
			}
		a = Insertsort_up(table,i);
		tables << "\t------>\t\t";
		for (int k = 0; k < i; k++)
			{
				tables << table[k] << "\t";
			}
		tables<<"\n";
		time << a[0]<<" " <<i << "\n";
		//closing files
		delete[] table;
		tables.close();
	}
	time.close();
	return 0;
}