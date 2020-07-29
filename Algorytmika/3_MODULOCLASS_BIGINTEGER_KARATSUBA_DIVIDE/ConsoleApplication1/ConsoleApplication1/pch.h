#include <iostream>
#include <math.h>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <exception>
#include <istream>
#include <ostream>
#include <vector>
#include <assert.h>
#include <ctime>
#include <algorithm>
using namespace std; 
#ifndef PCH_H
#define PCH_H

class BigInteger {
private:
	string number;
	vector<int> vnumber;
	int factor = 10;//for unit representation;
	int length;
	int sign;

public:
	BigInteger(std::string stringNumber);//
	BigInteger(int integerNumber);
	BigInteger();
	BigInteger(const BigInteger &a);
	~BigInteger();
	void print();//put out to stream
	void setstring(string stringNumber);//when we put ()constructor
	BigInteger changesign();//for sign change
	void numberDelete();
	void removeZeros();
	void random(int length);


	//friends
	friend BigInteger mulIntStringByChar(const BigInteger& op1, const char op2);
	friend bool isZero(const BigInteger& oper);//(2*O(n))
	friend BigInteger multiplyTime(const BigInteger &a, const BigInteger &b, int &t, int&length);
	//arithmetic
	BigInteger add(BigInteger bigInt);//functions that can be replaced by operators
	BigInteger subtruct(BigInteger bigInt);
	BigInteger mod();
	BigInteger multiply(BigInteger bigInt);
	BigInteger power(int n);
	BigInteger divide(BigInteger const &bigInt);
	BigInteger factorial();//silnia
	

	//operations overload
	friend BigInteger operator +(const BigInteger &a, const BigInteger &b);
	friend BigInteger operator +(const BigInteger &a, const string &b);
	friend BigInteger operator -(const BigInteger &a, const BigInteger &b);
	friend BigInteger operator -(const BigInteger &a, const string &b);
	friend BigInteger operator *(const BigInteger &a, const BigInteger &b);
	friend BigInteger operator *(const BigInteger &a, const string &b);
	friend BigInteger operator /(const BigInteger &a, const BigInteger &b);
	friend BigInteger operator /(const BigInteger &a, const string &b);
	BigInteger & operator -();//change sign
	BigInteger & operator = (const BigInteger & a); 
	BigInteger & operator = (const string &a);
	BigInteger & operator = (const long long &a);
	BigInteger & operator +=(const BigInteger &bigInt); 
	BigInteger & operator -=(const BigInteger &bigInt);
	BigInteger & operator *=(const BigInteger &bigInt);
	BigInteger & operator /=(const BigInteger &bigInt);
	friend bool operator <(const BigInteger &a, const BigInteger &b);/** logical operators*/
	friend bool operator <=(const BigInteger &a, const BigInteger &b);
	friend bool operator >=(const BigInteger &a, const BigInteger &b);
	friend bool operator >(const BigInteger &a, const BigInteger &b);
	friend bool operator ==(const BigInteger &a, const BigInteger &b);
	friend bool operator !=(const BigInteger &a, const BigInteger &b);
	char operator[](int n);
	friend ostream & operator <<(ostream & out, const BigInteger &a);/**\fn operator  ostream*/
	friend istream & operator >>(istream & in, BigInteger &a); /*data istream operator*/
};
void Karatsuba(int average, int max_n, string file_name);

#endif //PCH_H
