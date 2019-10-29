#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;
#ifndef PCH_H
#define PCH_H

bool Bernoulli(const double p);
vector<double> geo(const double p, const int tries);

vector<double> str_1_o_k(const int tries, int num_elements);
vector<double> str_const_p(const int tries,int num_elements, const double p);



#endif 
