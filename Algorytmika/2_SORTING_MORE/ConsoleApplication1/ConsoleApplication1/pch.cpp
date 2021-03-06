#include <fstream>
#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <cstdio>

using namespace std::chrono;
using namespace std;


float* Insertsort_up(float *table, int size)//name for user friendly name
{
	ofstream tables;
	char *h = new char[30];//for different file names
	snprintf(h, 20, "ISU%d.txt", size);
	tables.open(h);
	delete[] h;
	if (!tables.is_open())
	{
		string g = "Unable to open file";
		throw g;
	}

	//auto start = high_resolution_clock::now();
	float temp;
	float *a = new float[2];
	a[1] = 0;//for real time showing(optional)
	a[0] = 0;//number of steps
	for (int j = 1; j < size; j++)//algorithm 
	{
		temp = table[j];
		int i = j - 1;
		while (i >= 0 && table[i] > temp)
		{
			table[i + 1] = table[i];
			i--;
			a[0]++;
		}
		table[i + 1] = temp;
		if (i != j - 1)//check if table is modified
		{
			for (int j = 0; j < size; j++)//writing tables
			{
				tables << table[j] << "\t";
			}
			tables << "\n";
		}
	}
	//auto stop = high_resolution_clock::now();
	//duration<double, std::milli> fp_ms = (stop - start);
	//a[1] = fp_ms.count();//execution time
	tables.close();
	return a;
}
float* Insertsort_down(float *table, int size)
{
	ofstream tables;
	char *h = new char[30];//for different file names
	snprintf(h, 15, "ISD%d.txt", size);
	tables.open(h);
	delete[] h;
	if (!tables.is_open())
	{
		string g = "Unable to open file";
		throw g;
	}

	//auto start = high_resolution_clock::now();
	float temp;
	float *a = new float[2];
	a[1] = 0;//for real time showing(optional)
	a[0] = 0;//number of steps
	for (int j = 1; j < size; j++)
	{
		temp = table[j];
		int i = j - 1;
		while (i >= 0 && table[i] < temp)
		{
			table[i + 1] = table[i];
			i--;
			a[0]++;
		}
		table[i + 1] = temp;
		if (i != j - 1)//check if table is modified
		{
			for (int j = 0; j < size; j++)//writing tables
			{
				tables << table[j] << "\t";
			}
			tables << "\n";
		}
	}
	//auto stop = high_resolution_clock::now();
	//duration<double, std::milli> fp_ms = (stop - start);
	//a[1] = fp_ms.count();//execution time
	tables.close();
	return a;

}
float* Randomise_Table(float *table, int size)
{
	for (int i = 0; i < size; i++)
	{
		double x = (static_cast <float> (RAND_MAX / 123));
		if (x != 0)
		{
			table[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 123)) - (rand()) / x;
		}
		//so they become negative as well
	}
	return table;
}
float* Insertsort_up(float *table, int size, int iterations)
{

	/*ofstream tables;
	char *h = new char[30];//for different file names
	snprintf(h, 20, "ISU%d_I.txt", size);
	tables.open(h);
	delete[] h;
	if (!tables.is_open())
	{
		string g = "Unable to open file";
		throw g;
	}
	//auto start = high_resolution_clock::now();*/
	float temp;
	float *a = new float[iterations];
	for (int start = 0; start < iterations; start++)//for different iterations
	{
		a[start] = 0;//for different n 
		//table = Randomise_Table(table, size);
		for (int j = 1; j < size; j++)//algorithm 
		{
			temp = table[j];
			int i = j - 1;
			while (i >= 0 && table[i] > temp)
			{
				table[i + 1] = table[i];
				i--;
				a[start]++;
			}
			table[i + 1] = temp;
			/*if (i != j - 1)//check if table is modified
			{
				for (int j = 0; j < size; j++)//writing tables
				{
					tables << table[j] << "\t";
				}
				tables << "\n";
			}*/
		}
		//tables << "\n\n";
	}
	//tables.close();
	return a;
}
float* Insertsort_down(float *table, int size, int iterations)
{

	ofstream tables;
	char *h = new char[30];//for different file names
	snprintf(h, 20, "ISU%d_I.txt", size);
	tables.open(h);
	delete[] h;
	if (!tables.is_open())
	{
		string g = "Unable to open file";
		throw g;
	}
	//auto start = high_resolution_clock::now();
	float temp;
	float *a = new float[iterations];
	for (int start = 0; start < iterations; start++)//for different iterations
	{
		table = Randomise_Table(table, size);
		for (int j = 1; j < size; j++)//algorithm 
		{
			temp = table[j];
			int i = j - 1;
			while (i >= 0 && table[i] < temp)
			{
				table[i + 1] = table[i];
				i--;
				a[start]++;
			}
			table[i + 1] = temp;
			if (i != j - 1)//check if table is modified
			{
				for (int j = 0; j < size; j++)//writing tables
				{
					tables << table[j] << "\t";
				}
				tables << "\n";
			}
		}
		tables << "\n\n";
	}
	tables.close();
	return a;
}
void writeToFile(float*table, int size)
{


}
void almostQuickSort(float *table, int l, int r, int numElem, float & elem, int & iterations)
{
	int checker;
	//if (numElem > r-1 || numElem < 0)
	//{
	//	throw "NOOOO!"; //when we want to get something outside the table
	//}
	try {
 		if (l < r)
		{
			iterations = iterations + r-l-1;
			
			checker = partition(table, l, r);
			if (checker == elem);
			{
				elem = table[checker];
			}
			if ((numElem - 1) <= checker)
			{
			almostQuickSort(table, l, checker, numElem, elem, iterations);
			}
			if ((numElem - 1) > checker)
			{
				almostQuickSort(table, (checker + 1), r, numElem,  elem, iterations);
				
			}

		}

			elem = table[numElem - 1];
	}
	catch (...)
	{

	} 
}
int partition(float* table, int l, int r)
{
	float test = table[l];
	int i = l;//left side
	int j = r;//right side
	float temp;
	while (true)// for getting table in half, in direction where there are less than table[l] and more than -||-
	{

		while (table[j] > test)
		{
			j--;
		}
		while (table[i] < test)
		{
			i++;
		}
		if (i < j)
		{
			temp = table[i];
			table[i] = table[j];
			table[j] = temp;
			i++;
			j--;
		}
		else
		{
			return j; // position of cutting element
		}
	}
}
void haro()
{
	ofstream file;
	float* table;
	int size;
	int iterations;
	int yourPosition=-1;
	float yourNumber=0;
	char decision;
	cout << "Tell the size of a table" << endl;
	cin >> size;
	if (size > 1000)
	{
		cout << "I bet You wouldn't even look at all of them, making it smaller then" << endl;
		size = 1000;
	}
	table = new float[size];
	int l = 0;//start of table
	int r = size - 1;//end of table
	cout << "Do You want it randomised or put Your own numbers?(R for random, else for own)" << endl;
	cin >> decision;
	if (toupper(decision) == 'R')
	{
		table = Randomise_Table(table, size);
	}
	else
	{
		cout << "Podaj po kolei liczby" << endl;
		for (int i = 0; i < size; i++)
		{
			cin >> table[i];
		}
	}
	cout << "Which possition would You like to choose?" << endl;
	while (yourPosition >= size || yourPosition < 0)
	{
		cin >> yourPosition;
	}
	//file handling
	file.open("test.txt");
	if (!file.is_open())
	{
		string g = "Unable to open file";
		throw g;
	}
	file << "TABLE AT START" << "\t";
	for (int i = 0; i < size; i++)
	{
		file << table[i] << "\t";
	}
	file << endl << "After algorithm" << "\t";
	almostQuickSort(table, l, r, yourPosition, yourNumber, iterations);
	for (int i = 0; i < size; i++)
	{
		file << table[i] << "\t";
	}
	file << endl << "TABLE SORTED" << "\t";
	Insertsort_up(table, size, 1);
	for (int i = 0; i < size; i++)
	{
		file << table[i] << "\t";
	}
	file << endl << "YOUR NUMBER" << "\t" <<yourNumber;
	file.close();
	return;
}
int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

//