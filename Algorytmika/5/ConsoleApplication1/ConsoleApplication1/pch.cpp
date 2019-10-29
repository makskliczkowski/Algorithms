

#include "pch.h"



bool Bernoulli(const double p)
{
	if (p > 1 || p < 0) throw "THAT'S IMPROBABLE";
	double random = ((double)rand() / (RAND_MAX));
	if(random<=p) return true;
	else return false;
}

vector<double> geo(const double p, const int tries)
{
	srand(time(NULL));
	if (p > 1 || p < 0) throw "THAT'S IMPROBABLE";
	vector<double> histogram(tries,0);
	bool random=0;
	for (int i = 0; i < tries;i++)
	{
		int j = 0;
		random = 0;
		while (random == 0 && j< tries-1)
		{
			random = Bernoulli(p);
			j++;
		}
		histogram[j]=histogram[j]+double(1/double(tries));		
	}
	
	return histogram;
}

vector<double> str_1_o_k(const int tries,  int num_elements)
{
	srand(time(NULL));
	if (tries < 0) "YOU CAN'T TRY - TIMES";
	if (num_elements < 0) !num_elements;
	bool random;
	vector<double> histogram(num_elements, 0);
	fill(histogram.begin(), histogram.end(), 0);
	for (int try_number = 0; try_number < tries; try_number++) {

		int chosen = 1;
		for (int k = 1; k < num_elements; k++)
		{
			random = Bernoulli(double(1 / double(k)));
			if (random == true) chosen = k;
		}
		histogram[chosen] = histogram[chosen]+ double(1 / double(tries));
	}
	return histogram;
}

vector<double> str_const_p(const int tries, int num_elements, const double p)
{
	srand(time(NULL));
	if (tries < 0) "YOU CAN'T TRY - TIMES";
	if (p > 1 || p < 0) throw "THAT'S IMPROBABLE";
	if (num_elements < 0) !num_elements;
	bool random;
	vector<double> histogram(num_elements,0);
	fill(histogram.begin(), histogram.end(), 0);
	for (int try_number = 0; try_number < tries; try_number++) {

		int chosen = 1;
		for (int k = 1; k < num_elements; k++)
		{
			random = Bernoulli(p);
			if (random == true) chosen = k;
		}
		histogram[chosen] = histogram[chosen] + double(1 / double(tries));
	}
	return histogram;
}
