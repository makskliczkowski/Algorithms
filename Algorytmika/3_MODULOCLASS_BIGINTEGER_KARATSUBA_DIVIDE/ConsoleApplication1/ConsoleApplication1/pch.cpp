// pch.cpp: plik źródłowy odpowiadający wstępnie skompilowanemu nagłówkowi, niezbędny do powodzenia kompilacji

#include "pch.h"




BigInteger::BigInteger(string stringNumber) {

	//this->vnumber.reserve(this->length);
	string temp = stringNumber;
	if (stringNumber[0] == '-') {
		int i = 1;
		this->sign = -1;
		temp.erase(temp.begin());
		while (stringNumber[i] == 0) {
			i++;
			temp.erase(temp.begin());
		}
	}
	else
	{
		int i = 0;
		while (stringNumber[i] == 0) {
			i++;
			temp.erase(temp.begin());
		}
		this->sign = +1;
	}
	//int x = 0;
	/*for (int i = 0; i < length; i++) {
		x = x * 10 + stringNumber[i] - '0';
		this->vnumber.push_back(x);
	}*/
	this->length = temp.length();
	this->number = temp;
}
BigInteger::BigInteger(int integerNumber) {
	//int factElementh = integerNumber;;//for saving factor elementh

	if (integerNumber < 0) {
		this->sign = -1;
	}
	else
	{
		this->sign = 1;
	}
	this->number = to_string(abs(integerNumber));
	this->length = to_string(abs(integerNumber)).length();
	/*int factElementh;
	while (factElementh >= 1)
	{
		int rest = integerNumber % this->factor;
		factElementh = int(factElementh / this->factor);
		this->vnumber.insert(this->vnumber.begin(), rest);//for vector
	}

	std::std::reverse(this->vnumber.begin(), this->vnumber.end());//reversing vector*/
}

void BigInteger::print()
{
	if (this->sign == -1)std::cout << '-';

	for (int i = 0; i < this->length; i++)
	{
		std::cout << this->number[i];
	}
	cout << "\n";

}

BigInteger BigInteger::add(BigInteger bigInt)
{
	string number;
	int n1 = this->length;
	int n2 = bigInt.length;
	int sign = 1;
	BigInteger a = *this;
	BigInteger b = bigInt;
	BigInteger c;
	int rest;//for remembering last number to add
	if (a.sign == -1 && b.sign == -1)
	{
		sign = -1;//changing here to overcome later
	}
	if (a.sign == -1 && b.sign == 1) {
		BigInteger temp = a;
		temp.changesign();
		c = b - temp;//we change to substrate
		*this = c;
		return *this;
	}
	if (b.sign == -1 && a.sign == 1) {
		BigInteger temp = b;
		temp.changesign();
		c = a - temp;
		*this = c;
		return *this;
	}
	string temp1 = a.number;
	string temp2 = b.number;
	std::reverse(temp1.begin(), temp1.end());
	std::reverse(temp2.begin(), temp2.end());//std::reverse for having easier option at adding elements to string

	if (n1 > n2)
	{
		swap(temp1, temp2);
		n1 = temp1.length();
		n2 = temp2.length();
	}
	rest = 0;//at beginning no rest
	for (int i = 0; i < n1; i++)
	{
		int sum = ((temp1[i] - '0') + (temp2[i] - '0') + rest);
		number.push_back(sum % 10 + '0');
		// Calculate rest for next step 
		rest = (int)sum / 10;
	}
	for (int i = n1; i < n2; i++)//for the rest of a number
	{
		int sum = ((temp2[i] - '0') + rest);
		number.push_back(sum % 10 + '0');
		rest = (int)sum / 10;
	}
	if (rest)//if we created bigger number
	{
		number.push_back(rest + '0');
	}
	std::reverse(number.begin(), number.end());
	BigInteger temp(number);
	if (sign == -1)//in case where both were negative
	{
		temp.changesign();
	}
	this->number = temp.number;
	this->sign = temp.sign;
	//if (sign != 1 || sign != -1)
	//{
	//	this->number = c.number;//when we have to substract
	//}

	return *this;
}

BigInteger BigInteger::subtruct(BigInteger bigInt)
{
	string number;
	int temp = 0;
	int sign = 1;
	int n1 = this->length;
	int n2 = bigInt.length;
	string temp1 = this->number;
	string temp2 = bigInt.number;
	if (this->sign == -1 && bigInt.sign == -1)
	{
		sign = -sign;//for changing at the end
	}
	if (this->sign == -1 && bigInt.sign == 1) {
		BigInteger temp = *this;
		temp.changesign();//we get simple adding taken negative
		temp = -(bigInt + temp);
		*this = temp;
		return *this;
	}
	if (bigInt.sign == -1 && this->sign == 1) {
		BigInteger temp = bigInt;
		temp.changesign();
		*this = (temp + bigInt);//add
		return *this;
	}
	if (n1 < n2) {
		swap(temp1, temp2);
		n1 = temp1.length();
		n2 = temp2.length();
		sign = -sign;
	}
	std::reverse(temp1.begin(), temp1.end());
	std::reverse(temp2.begin(), temp2.end());

	//substractioon process
	for (int i = 0; i < n2; i++)
	{
		int j = (temp1[i] - '0') - (temp2[i] - '0') - temp;
		if (j < 0)
		{
			j = j + this->factor;
			temp = 1;//this for taking from the others
		}
		else temp = 0;
		number.push_back(j + '0');
	}
	for (int i = n2; i < n1; i++)
	{
		int j = (temp1[i] - '0') - temp;
		if (j < 0)
		{
			j = j + this->factor;
			temp = 1;
		}
		else temp = 0;
		number.push_back(j + '0');
	}

	std::reverse(number.begin(), number.end());
	//removeZeros(number);
	BigInteger temporary(number);
	if (sign == -1) temporary.changesign();
	temporary.removeZeros();
	*this = temporary;
	return *this;
}

BigInteger::BigInteger()
{
	this->sign = 1;
	string temp = "0";
	this->number = temp;
	this->length = temp.length();
}

BigInteger::BigInteger(const BigInteger & a)
{
	this->number = a.number;
	this->length = a.number.length();
	this->sign = a.sign;
}

BigInteger::~BigInteger()
{
	this->number.clear();
}

void BigInteger::setstring(string stringNumber)
{

	if (stringNumber[0] == '-') {
		if (stringNumber[1] == 0) throw - 1;
		this->sign = -1;
		stringNumber.erase(stringNumber.begin());
	}
	else
	this->length = stringNumber.length();
	this->number = stringNumber;
	(*this).removeZeros();

}

BigInteger BigInteger::changesign()
{
	if (this->sign == 1) this->sign = -1;
	else this->sign = 1;
	return *this;
}

void BigInteger::numberDelete()
{
	this->number.clear();
	this->length = this->number.length();
	this->sign = 1;
}

void Karatsuba(int average, int max_n, string file_name)
{
	ofstream file;
	file.open("times.dat");
	if (!file.is_open())
	{
		throw "Can't open a file";
	}
	BigInteger a;
	BigInteger b;

	for (int i = 1; i < max_n; i++)
	{
		int t = 0;
		int n = 0;
		int time = 0;
		for (int j = 0; j < average; j++)
		{
			a.random(i);
			b.random(i);
			multiplyTime(a, b, t, n);
			time = time + t;
		}
		time = time / average;
		file << n << "\t\t" << time << endl;
	}
	file.close();
}
BigInteger mulIntStringByChar(const BigInteger & a, const char b)
{

	if (b == 0) return BigInteger("0");
	if (b == 1 - '0') return a;
	int reminder = 0;//rest
	int multipler = b - '0'; //by what is it multipled
	int d;
	string number;
	for (size_t i = 0; i < a.number.length(); i++) {
		int ans = a.number[a.number.length() - 1 - i] - '0';//what will be multipled
		d = (multipler *ans) + reminder;//what's left after multiply
		reminder = (int)(d / 10);//decimal number to add
		d = d % a.factor;
		number.push_back(d + '0');
	}

	if (reminder) number.push_back(reminder + '0');//to add extra place
	std::reverse(number.begin(), number.end());
	BigInteger temporary(number);
	if (a.sign == -1) temporary.sign = -1;
	temporary.removeZeros();
	return temporary;
}

bool isZero(const BigInteger & oper)
{
	for (size_t i = 0; i < oper.number.length(); i++)
		if (oper.number[i] != '0') return false;
	return true;
}

BigInteger multiplyTime(const BigInteger &a,const BigInteger &b, int &t,int &length)//second length of number,first steps
{
	int n1 = a.number.length();
	int n2 = b.number.length();
	int n = max(n1, n2);
	length = max(length,n);
	int sign = 1;;//for change at the end
	t = t + 2 * n;//2*O(n)
	if (isZero(a) || isZero(b))
	{
		return BigInteger();
	}
	if (n1 == 1)
	{
		t = t + n;//for multintstringbychar
		return mulIntStringByChar(b, a.number[0]);
	}
	if (n2 == 1)
	{
		t = t + n;//for multintstringbychar
		return mulIntStringByChar(a, b.number[0]);
	}//when it's a simple multiply
	if ((a.sign == -1 && b.sign == 1) || (a.sign == 1 && b.sign == -1))
	{
		sign = -1;//O(1)
	}
	BigInteger x = a;
	BigInteger y = b;//O(2n)
	if (n1 < n2) {//making equal length
		for (int i = 0; i < n2 - n1; i++) {
			x.number.insert(x.number.begin(), '0');
		}
		swap(x, y);
		n = n2;
		n1 = n2;
	}
	
	else if (n1 > n2) {
		for (int i = 0; i < n1 - n2; i++) {
			y.number.insert(y.number.begin(), '0');
		}
		n = n1;
		n2 = n1;
	}
	t = t +  n;//max (O(n))
	if (n % 2 != 0)
	{
		x.number.insert(x.number.begin(), '0');
		y.number.insert(y.number.begin(), '0');
		n++;
	}//O(1);
	int left = n / 2;
	int right = n - left;
	BigInteger xl(x.number.substr(0, left));//for xes muliply

	BigInteger xr(x.number.substr(right, right));

	BigInteger yl(y.number.substr(0, left));

	BigInteger yr(y.number.substr(right, right));//for ys multiply
	//4*O(n)
	t = t + 4 * n;
	//recursive calls
	BigInteger temp2 = multiplyTime(xl, yl,t,length);
	BigInteger temp3 = multiplyTime(xr , yr,t,length);
	//sum 2*O(n)
	t = t + 2* n;
	BigInteger sum1 = xl + xr;
	BigInteger sum2 = yl + yr;
	//recursive
	BigInteger temp1 = multiplyTime(sum1 , sum2, t, length);
	//2*O(n)
	BigInteger temp4 = temp2;//temp2
	BigInteger temp5 = temp3;//temp3
	//5*O(n);
	for (int i = 0; i < n; i++)
	{
		temp2.number.push_back('0');
		if (i % 2 == 0)
		{
			temp1.number.push_back('0');
			temp5.number.push_back('0');
			temp4.number.push_back('0');
		}
	}
	t = t + 5 * n;
	//
	temp1.length = temp1.number.length();
	temp2.length = temp2.number.length();
	temp3.length = temp3.number.length();
	temp4.length = temp4.number.length();
	temp5.length = temp5.number.length();
	//5*O(n)
	
	BigInteger temporary;
	temporary = temp3 + temp2 + temp1 - temp4 - temp5;
	t = t + 5 * n;//sum
	temporary.removeZeros();
	temporary.length = temporary.number.length();
	if (sign == -1) temporary.changesign();//when occured change
	return temporary;
}

void BigInteger::removeZeros() {
	while (this->number.length()!=1 && this->number[0] == '0')
	{
		this->number.erase(this->number.begin());
		this->length--;
	}
}

BigInteger BigInteger::mod()
{
	if (this->sign == -1) this->sign = 1;
	return *this;
}

BigInteger BigInteger::multiply(BigInteger bigInt)
{
	int time = 0;//złożoność
	int n1 = this->number.length();
	int n2 = bigInt.number.length();
	int n = max(n1, n2);
	int sign;//for change at the end
	if (isZero(*this) || isZero(bigInt))
	{
		this->numberDelete();
		return *this;
		time = time + n1 + n2;
	}
	if (n1 == 1)
	{
		time = time + n2;
		*this= mulIntStringByChar(bigInt, this->number[0]);
		return *this;
	}
	if (n2 == 1)
	{
		time = time + n1;
		*this = mulIntStringByChar(*this, bigInt.number[0]);
		return *this;
	}//when it's a simple multiply
	if ((this->sign == -1 && bigInt.sign == 1) || (this->sign == 1 && bigInt.sign == -1))
	{
		sign = -1;
	}
	BigInteger x = *this;
	BigInteger y = bigInt;
	if (n1 < n2) {//making equal length
		for (int i = 0; i < n2 - n1; i++) {
			x.number.insert(x.number.begin(), '0');
			x.print();
		}
		n = n2;
	}
	else if (n1 > n2) {
		for (int i = 0; i < n1 - n2; i++) {
			y.number.insert(y.number.begin(), '0');
		}
		n = n1;
	}
	if (n % 2 != 0)
	{
		x.number.insert(x.number.begin(), '0');
		y.number.insert(y.number.begin(), '0');
		n++;
	}
	int left = n / 2;
	int right = n - left;
	BigInteger xl(x.number.substr(0, left));//for xes muliply
	BigInteger xr(x.number.substr(right, right));

	BigInteger yl(y.number.substr(0, left));
	BigInteger yr(y.number.substr(right, right));//for ys multiply
	BigInteger temp2 = xl * yl;

	BigInteger temp3 = xr * yr;
	BigInteger sum1 = xl + xr;
	BigInteger sum2 = yl + yr;
	BigInteger temp1 = sum1 * sum2;

	BigInteger temp4 = (xl* yl);//temp2

	BigInteger temp5 = (xr* yr);//temp3
	for (int i = 0; i < n; i++)
	{
		temp2.number.push_back('0');
		if (i % 2 == 0)
		{
			temp1.number.push_back('0');
			temp5.number.push_back('0');
			temp4.number.push_back('0');
		}
	}
	temp1.length = temp1.number.length();
	temp2.length = temp2.number.length();
	temp3.length = temp3.number.length();
	temp4.length = temp4.number.length();
	temp5.length = temp5.number.length();
	time = time + 5 * n;


	BigInteger temporary;
	temporary = temp3 + temp2;
	temporary = temporary + temp1;
	temporary = temporary - temp4;
	temporary = temporary - temp5;
	temporary.removeZeros();
	temporary.length = temporary.number.length();
	if (sign == -1) temporary.changesign();//when occured change
	temporary.removeZeros();
	*this = temporary;
	return *this;
}

BigInteger BigInteger::power(int n)
{
	if (n == 0) return BigInteger("1");
	if (n == 1) return *this;
	BigInteger temp = *this;
	for (int i = 0; i < n; i++)
	{
		(*this) = (*this)*temp;//naive power
	}
	return (*this);
}

BigInteger BigInteger::divide(const BigInteger &bigInt)
{
	int n1 = this->number.length();
	int n2 = bigInt.number.length();
	int sign = 1;
	if (n1 < n2)
	{
		*this = BigInteger("0");
		return *this;
	}
	BigInteger Nomin = *this;
	if (Nomin.number == "0")
	{
		*this = BigInteger("0");
		return *this;
	}
	if (Nomin.sign == -1)
	{
		sign = sign * -1;
	}
	BigInteger Denomin = bigInt;
	if (Denomin.sign == -1)
	{
		sign = sign * -1;
	}
	if (Denomin.number == "0")throw "can't divide by 0!\n";
	BigInteger A = Denomin;//quick diviser
	BigInteger R = Nomin;//reminder
	BigInteger Q;//quotient
	BigInteger Qn;//new quotient
	int temp;//help
	int reminder;
	int M = Denomin.number.length() - 1;//denomin length -1
	for (size_t i = 1; i < A.number.length(); i++) {
		A.number[i] = 0 + '0';
	}
	BigInteger Rp = R;//for abs check
	while (Rp.mod() >= Denomin)
	{
		Q.numberDelete();//for clarity
		temp = 0;
		reminder = 0;
		for (size_t i = 0; i < R.number.length() - M; i++)
		{
			temp = 10 * reminder + (R.number[i] - '0');
			int topush = temp / (A.number[0] - '0');//for the i'th number in our quotient
			Q.number += to_string(topush);
			Q.length = Q.number.length();
			reminder = temp - int(Q.number[i] - '0') * int(A.number[0] - '0');
		}
		if (R.sign == -1) { Q.sign = -1; }//when we need to substract
		Qn = Q + Qn;
		R = Nomin - (Qn * Denomin);
		R.removeZeros();
		Rp = R;//for loop condition,not to change sign
	}
	if (R.sign == 1)
	{
		Qn.removeZeros();
		return Qn;//finish after that
	}
	Qn = Qn - BigInteger("1");//we have to do like in modulo class
	R = R + Denomin;
	if (sign < 0) Q.sign = -1;
	Qn.removeZeros();
	*this = Qn;
	return *this;
}

BigInteger BigInteger::factorial()
{
	if (this->sign == -1)throw"NOT NEGATIVEs\n";
	if (this->number == "0") { return BigInteger("1"); }
	
	BigInteger temp = *this;
	while(temp.number!="1")
	{
		temp = temp - "1";
 		(*this) = (*this)*temp;//naive power
	}
	return (*this);
}

void BigInteger::random(int length)
{
	this->number.clear();
	this->length = length;
	this->sign = 1;
	int temp = 1 + (rand() % 9);
	this->number[0] = temp + '0';
	for (int i = 1; i < length; i++)
	{
		temp = 1 + (rand() % 9);
		this->number.insert(this->number.begin(), temp + '0');
	}
}

BigInteger & BigInteger::operator-()
{
	if (this->sign == -1) this->sign = 1;
	else this->sign = -1;
	return(*this);
}

BigInteger & BigInteger::operator=(const BigInteger & a)
{
	this->number = a.number;
	this->length = a.number.length();
	this->sign = a.sign;
	return(*this);
}

BigInteger & BigInteger::operator=(const string & a)
{
	if (isalpha(a[0]-'0'))throw "I cannot!\n";
	BigInteger temp(a);
	this->number = temp.number;
	this->length = temp.number.length();
	this->sign = temp.sign;
	return(*this);
}

BigInteger & BigInteger::operator=(const long long & a)
{
	this->sign = 1;
	long long temp;//temp
	if (a < 0)
	{
		temp = abs(a);
		this->sign = -1;
	}
	this->number = to_string(a);
	this->length = this->number.length();
	
	return(*this);
	
}


BigInteger & BigInteger::operator+=(const BigInteger & bigInt)
{
	string number;
	int n1 = this->length;
	int n2 = bigInt.length;
	int sign = 1;
	BigInteger a = *this;
	BigInteger b = bigInt;
	BigInteger c;
	int rest;//for remembering last number to add
	if (a.sign == -1 && b.sign == -1)
	{
		sign = -1;//changing here to overcome later
	}
	if (a.sign == -1 && b.sign == 1) {
		BigInteger temp = a;
		temp.changesign();
		c = b - temp;//we change to substrate
		*this = c;
		return *this;
	}
	if (b.sign == -1 && a.sign == 1) {
		BigInteger temp = b;
		temp.changesign();
		c = a - temp;
		*this = c;
		return *this;
	}
	string temp1 = a.number;
	string temp2 = b.number;
	std::reverse(temp1.begin(), temp1.end());
	std::reverse(temp2.begin(), temp2.end());//std::reverse for having easier option at adding elements to string

	if (n1 > n2)
	{
		swap(temp1, temp2);
		n1 = temp1.length();
		n2 = temp2.length();
	}
	rest = 0;//at beginning no rest
	for (int i = 0; i < n1; i++)
	{
		int sum = ((temp1[i] - '0') + (temp2[i] - '0') + rest);
		number.push_back(sum % 10 + '0');
		// Calculate rest for next step 
		rest = (int)sum / 10;
	}
	for (int i = n1; i < n2; i++)//for the rest of a number
	{
		int sum = ((temp2[i] - '0') + rest);
		number.push_back(sum % 10 + '0');
		rest = (int)sum / 10;
	}
	if (rest)//if we created bigger number
	{
		number.push_back(rest + '0');
	}
	std::reverse(number.begin(), number.end());
	BigInteger temp(number);
	if (sign == -1)//in case where both were negative
	{
		temp.changesign();
	}
	this->number = temp.number;
	this->sign = temp.sign;
	//if (sign != 1 || sign != -1)
	//{
	//	this->number = c.number;//when we have to substract
	//}

	return *this;
}

BigInteger & BigInteger::operator-=(const BigInteger & bigInt)
{
	string number;
	int temp = 0;
	int sign = 1;
	int n1 = this->length;
	int n2 = bigInt.length;
	string temp1 = this->number;
	string temp2 = bigInt.number;
	if (this->sign == -1 && bigInt.sign == -1)
	{
		sign = -sign;//for changing at the end
	}
	if (this->sign == -1 && bigInt.sign == 1) {
		BigInteger temp = *this;
		temp.changesign();//we get simple adding taken negative
		temp = -(bigInt + temp);
		*this = temp;
		return *this;
	}
	if (bigInt.sign == -1 && this->sign == 1) {
		BigInteger temp = bigInt;
		temp.changesign();
		*this = (temp + bigInt);//add
		return *this;
	}
	if (n1 < n2) {
		swap(temp1, temp2);
		n1 = temp1.length();
		n2 = temp2.length();
		sign = -sign;
	}
	std::reverse(temp1.begin(), temp1.end());
	std::reverse(temp2.begin(), temp2.end());

	//substractioon process
	for (int i = 0; i < n2; i++)
	{
		int j = (temp1[i] - '0') - (temp2[i] - '0') - temp;
		if (j < 0)
		{
			j = j + this->factor;
			temp = 1;//this for taking from the others
		}
		else temp = 0;
		number.push_back(j + '0');
	}
	for (int i = n2; i < n1; i++)
	{
		int j = (temp1[i] - '0') - temp;
		if (j < 0)
		{
			j = j + this->factor;
			temp = 1;
		}
		else temp = 0;
		number.push_back(j + '0');
	}

	std::reverse(number.begin(), number.end());
	//removeZeros(number);
	BigInteger temporary(number);
	if (sign == -1) temporary.changesign();
	*this = temporary;
	return *this;
}

BigInteger & BigInteger::operator*=(const BigInteger & bigInt)
{
	int time = 0;//złożoność
	int n1 = this->number.length();
	int n2 = bigInt.number.length();
	int n = max(n1, n2);
	int sign;//for change at the end
	if (isZero(*this) || isZero(bigInt))
	{
		this->numberDelete();
		return *this;
		time = time + n1 + n2;
	}
	if (n1 == 1)
	{
		time = time + n2;
		*this = mulIntStringByChar(bigInt, this->number[0]);
		return *this;
	}
	if (n2 == 1)
	{
		time = time + n1;
		*this = mulIntStringByChar(*this, bigInt.number[0]);
		return *this;
	}//when it's a simple multiply
	if ((this->sign == -1 && bigInt.sign == 1) || (this->sign == 1 && bigInt.sign == -1))
	{
		sign = -1;
	}
	BigInteger x = *this;
	BigInteger y = bigInt;
	if (n1 < n2) {//making equal length
		for (int i = 0; i < n2 - n1; i++) {
			x.number.insert(x.number.begin(), '0');
			x.print();
		}
		n = n2;
	}
	else if (n1 > n2) {
		for (int i = 0; i < n1 - n2; i++) {
			y.number.insert(y.number.begin(), '0');
		}
		n = n1;
	}
	if (n % 2 != 0)
	{
		x.number.insert(x.number.begin(), '0');
		y.number.insert(y.number.begin(), '0');
		n++;
	}
	int left = n / 2;
	int right = n - left;
	BigInteger xl(x.number.substr(0, left));//for xes muliply
	BigInteger xr(x.number.substr(right, right));

	BigInteger yl(y.number.substr(0, left));
	BigInteger yr(y.number.substr(right, right));//for ys multiply
	BigInteger temp2 = xl * yl;

	BigInteger temp3 = xr * yr;
	BigInteger sum1 = xl + xr;
	BigInteger sum2 = yl + yr;
	BigInteger temp1 = sum1 * sum2;

	BigInteger temp4 = (xl* yl);//temp2

	BigInteger temp5 = (xr* yr);//temp3
	for (int i = 0; i < n; i++)
	{
		temp2.number.push_back('0');
		if (i % 2 == 0)
		{
			temp1.number.push_back('0');
			temp5.number.push_back('0');
			temp4.number.push_back('0');
		}
	}
	temp1.length = temp1.number.length();
	temp2.length = temp2.number.length();
	temp3.length = temp3.number.length();
	temp4.length = temp4.number.length();
	temp5.length = temp5.number.length();
	time = time + 5 * n;


	BigInteger temporary;
	temporary = temp3 + temp2;
	temporary = temporary + temp1;
	temporary = temporary - temp4;
	temporary = temporary - temp5;
	temporary.removeZeros();
	temporary.length = temporary.number.length();
	if (sign == -1) temporary.changesign();//when occured change
	temporary.removeZeros();
	*this = temporary;
	return *this;
}

BigInteger & BigInteger::operator/=(const BigInteger & bigInt)
{
	int n1 = this->number.length();
	int n2 = bigInt.number.length();
	int sign = 1;
	if (n1 < n2) 
	{
		*this =BigInteger("0");
		return *this;
	}
	BigInteger Nomin = *this;
	if (Nomin.number == "0")
	{
		*this = BigInteger("0");
		return *this;
	}
	if (Nomin.sign == -1)
	{
		sign = sign * -1;
	}
	BigInteger Denomin = bigInt;
	if (Denomin.sign == -1)
	{
		sign = sign * -1;
	}
	if (Denomin.number == "0")throw "can't divide by 0!\n";
	BigInteger A = Denomin;//quick diviser
	BigInteger R = Nomin;//reminder
	BigInteger Q;//quotient
	BigInteger Qn;//new quotient
	int temp;//help
	int reminder;
	int M = Denomin.number.length() - 1;//denomin length -1
	for (size_t i = 1; i < A.number.length(); i++) {
		A.number[i] = 0 + '0';
	}
	BigInteger Rp = R;//for abs check
	while (Rp.mod() >= Denomin)
	{
		Q.numberDelete();//for clarity
		temp = 0;
		reminder = 0;
		for (size_t i = 0; i < R.number.length() - M; i++)
		{
			temp = 10 * reminder + (R.number[i] - '0');
			int topush = temp / (A.number[0] - '0');//for the i'th number in our quotient
			Q.number += to_string(topush);
			Q.length = Q.number.length();
			reminder = temp - int(Q.number[i] - '0') * int(A.number[0] - '0');
		}
		if (R.sign == -1) { Q.sign = -1; }//when we need to substract
		Qn = Q + Qn;
		R = Nomin - (Qn * Denomin);
		R.removeZeros();
		Rp = R;//for loop condition,not to change sign
	}
	if (R.sign == 1)
	{
		Qn.removeZeros();
		return Qn;//finish after that
	}
	Qn = Qn - BigInteger("1");//we have to do like in modulo class
	R = R + Denomin;
	if (sign < 0) Q.sign = -1;
	Qn.removeZeros();
	*this = Qn;
	return *this;
}

BigInteger operator+(const BigInteger & a, const BigInteger & b)
{
	string number;
	int n1 = a.length;
	int n2 = b.length;
	int sign = 1;
	BigInteger c;
	int rest;//for remembering last number to add
	if (a.sign == -1 && b.sign == -1)
	{
		sign = -1;//changing here to overcome later
	}
	if (a.sign == -1 && b.sign == 1) {
		BigInteger temp = a;
		temp.changesign();
		c = b - temp;//we change to substrate
		return c;
	}
	if (b.sign == -1 && a.sign == 1) {
		BigInteger temp = b;
		temp.changesign();
		c = a - temp;
		return c;
	}
	string temp1 = a.number;
	string temp2 = b.number;
	std::reverse(temp1.begin(), temp1.end());
	std::reverse(temp2.begin(), temp2.end());//std::reverse for having easier option at adding elements to string

	if (n1 >= n2)
	{
		swap(temp1, temp2);
		n1 = temp1.length();
		n2 = temp2.length();
	}
	rest = 0;//at beginning no rest
	for (int i = 0; i < n1; i++)
	{
		int sum = ((temp1[i] - '0') + (temp2[i] - '0') + rest);
		number.push_back(sum % 10 + '0');
		// Calculate rest for next step 
		rest = (int)sum / 10;
	}
	for (int i = n1; i < n2; i++)//for the rest of a number
	{
		int sum = ((temp2[i] - '0') + rest);
		number.push_back(sum % 10 + '0');
		rest = (int)sum / 10;
	}
	if (rest)//if we created bigger number
	{
		number.push_back(rest + '0');
	}
	std::reverse(number.begin(), number.end());
	BigInteger temp(number);
	if (sign == -1)
	{
		temp.changesign();
	}
	return temp;
}

BigInteger operator+(const BigInteger & a, const string & b)
{
	string number;
	int n1 = a.length;
	int n2 = b.length();
	BigInteger c;
	int rest;//for remembering last number to add
	if (a.sign == -1) {
		BigInteger temp = a;
		temp.changesign();
		c = b - temp;//we change to substrate
		return c;
	}
	string temp1 = a.number;
	string temp2 = b;
	std::reverse(temp1.begin(), temp1.end());
	std::reverse(temp2.begin(), temp2.end());//std::reverse for having easier option at adding elements to string

	if (n1 >= n2)
	{
		swap(temp1, temp2);
		n1 = temp1.length();
		n2 = temp2.length();
	}
	rest = 0;//at beginning no rest
	for (int i = 0; i < n1; i++)
	{
		int sum = ((temp1[i] - '0') + (temp2[i] - '0') + rest);
		number.push_back(sum % 10 + '0');
		// Calculate rest for next step 
		rest = (int)sum / 10;
	}
	for (int i = n1; i < n2; i++)//for the rest of a number
	{
		int sum = ((temp2[i] - '0') + rest);
		number.push_back(sum % 10 + '0');
		rest = (int)sum / 10;
	}
	if (rest)//if we created bigger number
	{
		number.push_back(rest + '0');
	}
	std::reverse(number.begin(), number.end());
	BigInteger temp(number);
	return temp;
}

BigInteger operator-(const BigInteger & a, const BigInteger & b)
{
	string number;
	int temp = 0;
	int sign = 1;
	int n1 = a.length;
	int n2 = b.length;
	string temp1 = a.number;
	string temp2 = b.number;
	BigInteger c;//for sign changing properties
	if (a.sign == -1 && b.sign == -1)
	{
		sign = -1;//for changing at the end
	}
	if (a.sign == -1 && b.sign == 1) {
		BigInteger temp = a;
		temp.changesign();//we get simple adding taken negative
		c = -(b + temp);
		return c;
	}
	if (b.sign == -1 && a.sign == 1) {
		BigInteger temp = b;
		temp.changesign();
		c = (temp + a);//add
		return c;
	}
	if (a < b)
	{
		swap(temp1, temp2);
		n1 = temp1.length();
		n2 = temp2.length();
		sign = -1;
	}
	std::reverse(temp1.begin(), temp1.end());
	std::reverse(temp2.begin(), temp2.end());

	//substractioon process
	for (size_t i = 0; i < temp2.length(); i++)
	{
		int j = (temp1[i] - '0') - (temp2[i] - '0') - temp;
		if (j < 0)
		{
			j = j + a.factor;
			temp = 1;//this for taking from the others
		}
		else temp = 0;
		number.push_back(j + '0');
	}
	for (int i = n2; i < n1; i++)
	{
		int j = (temp1[i] - '0') - temp;
		if (j < 0)
		{
			j = j + a.factor;
			temp = 1;
		}
		else temp = 0;
		number.push_back(j + '0');
	}
	std::reverse(number.begin(), number.end());
	
	BigInteger temporary(number);
	if (sign == -1) temporary.changesign();
	temporary.removeZeros();
	return temporary;
}

BigInteger operator-(const BigInteger & a, const string & b)
{
	string number;
	int temp = 0;
	int sign = 1;
	int n1 = a.length;
	int n2 = b.length();
	string temp1 = a.number;
	string temp2 = b;
	BigInteger c;//for sign changing properties

	if (a.sign == -1) {
		BigInteger temp = a;
		temp.changesign();//we get simple adding taken negative
		c = -(b + temp);
		return c;
	}
	if (n1 < n2) {
		swap(temp1, temp2);
		n1 = temp1.length();
		n2 = temp2.length();
		sign = -sign;
	}
	std::reverse(temp1.begin(), temp1.end());
	std::reverse(temp2.begin(), temp2.end());

	//substractioon process
	for (size_t i = 0; i < temp2.length(); i++)
	{
		int j = (temp1[i] - '0') - (temp2[i] - '0') - temp;
		if (j < 0)
		{
			j = j + a.factor;
			temp = 1;//this for taking from the others
		}
		else temp = 0;
		number.push_back(j + '0');
	}
	for (int i = n2; i < n1; i++)
	{
		int j = (temp1[i] - '0') - temp;
		if (j < 0)
		{
			j = j + a.factor;
			temp = 1;
		}
		else temp = 0;
		number.push_back(j + '0');
	}
	std::reverse(number.begin(), number.end());
	BigInteger temporary(number);
	temporary.removeZeros();
	if (sign == -1) { temporary.changesign(); }
	return temporary;
}

BigInteger operator*(const BigInteger & a, const BigInteger & b)
{//karatsuba

	int *time;//złożoność
	time = new int;
	int time_add=0;
	int n1 = a.number.length();
	int n2 = b.number.length();
	int n = max(n1, n2);
	int sign = 1;;//for change at the end
	if (isZero(a) || isZero(b))
	{
		return BigInteger();
		time_add = time_add + n;
	}
	if (n1 == 1)
	{
		*time = *time + n;
		return mulIntStringByChar(b, a.number[0]);
	}
	if (n2 == 1)
	{
		*time = *time + n;
		return mulIntStringByChar(a, b.number[0]);
	}//when it's a simple multiply
	if ((a.sign == -1 && b.sign == 1) || (a.sign == 1 && b.sign == -1))
	{
		sign = -1;
	}
	BigInteger x = a;
	BigInteger y = b;
	*time += 2 * n;
	if (n1 < n2) {//making equal length
		for (int i = 0; i < n2 - n1; i++) {
			x.number.insert(x.number.begin(), '0');
		}
		swap(x, y);
		n = n2;
		n1 = n2;
	}
	else if (n1 > n2) {
		for (int i = 0; i < n1 - n2; i++) {
			y.number.insert(y.number.begin(), '0');
		}
		n = n1;
		n2 = n1;
	}
	if (n % 2 != 0)
	{
		x.number.insert(x.number.begin(), '0');
		y.number.insert(y.number.begin(), '0');
		n++;
	}
	int left = n / 2;
	int right = n - left;
	BigInteger xl(x.number.substr(0, left));//for xes muliply

	BigInteger xr(x.number.substr(right, right));

	BigInteger yl(y.number.substr(0, left));

	BigInteger yr(y.number.substr(right, right));//for ys multiply

	BigInteger temp2 = xl * yl;

	BigInteger temp3 = xr * yr;
	BigInteger sum1 = xl + xr;
	BigInteger sum2 = yl + yr;
	BigInteger temp1 = sum1 * sum2;

	BigInteger temp4 = (xl* yl);//temp2

	BigInteger temp5 = (xr* yr);//temp3

	for (int i = 0; i < n; i++)
	{
		temp2.number.push_back('0');
		if (i % 2 == 0)
		{
			temp1.number.push_back('0');
			temp5.number.push_back('0');
			temp4.number.push_back('0');
		}
	}
	temp1.length = temp1.number.length();
	temp2.length = temp2.number.length();
	temp3.length = temp3.number.length();
	temp4.length = temp4.number.length();
	temp5.length = temp5.number.length();

	time = time + 5 * n;


	BigInteger temporary;
	temporary = temp3 + temp2 + temp1-temp4-temp5;
	temporary.removeZeros();
	temporary.length = temporary.number.length();
	if (sign == -1) temporary.changesign();//when occured change
	return temporary;

}

BigInteger operator*(const BigInteger & a, const string & b)
{
	int time = 0;//złożoność
	int n1 = a.number.length();
	int n2 = b.length();
	int n = max(n1, n2);
	int sign = 1;//for change at the end
	if (isZero(a) || isZero(b))
	{
		return BigInteger();
		time = time + n1 + n2;
	}
	if (n1 == 1)
	{
		time = time + n2;
		return mulIntStringByChar(b, a.number[0]);
	}
	if (n2 == 1)
	{
		time = time + n1;
		return mulIntStringByChar(a, b[0]);
	}//when it's a simple multiply
	if ((a.sign == -1))
	{
		sign = -1;
	}
	BigInteger x = a;
	BigInteger y = b;
	if (n1 < n2) {//making equal length
		for (int i = 0; i < n2 - n1; i++) {
			x.number.insert(x.number.begin(), '0');
		}
		n = n2;
	}
	else if (n1 > n2) {
		for (int i = 0; i < n1 - n2; i++) {
			y.number.insert(y.number.begin(), '0');
		}
		n = n1;
	}
	if (n % 2 != 0)
	{
		x.number.insert(x.number.begin(), '0');
		y.number.insert(y.number.begin(), '0');
		n++;
	}
	int left = n / 2;
	int right = n - left;
	BigInteger xl(x.number.substr(0, left));//for xes muliply

	BigInteger xr(x.number.substr(right, right));

	BigInteger yl(y.number.substr(0, left));

	BigInteger yr(y.number.substr(right, right));//for ys multiply

	BigInteger temp2 = xl * yl;

	BigInteger temp3 = xr * yr;
	BigInteger sum1 = xl + xr;
	BigInteger sum2 = yl + yr;
	BigInteger temp1 = sum1 * sum2;

	BigInteger temp4 = (xl* yl);//temp2

	BigInteger temp5 = (xr* yr);//temp3

	for (int i = 0; i < n; i++)
	{
		temp2.number.push_back('0');
		if (i % 2 == 0)
		{
			temp1.number.push_back('0');
			temp5.number.push_back('0');
			temp4.number.push_back('0');
		}
	}
	temp1.length = temp1.number.length();
	temp2.length = temp2.number.length();
	temp3.length = temp3.number.length();
	temp4.length = temp4.number.length();
	temp5.length = temp5.number.length();
	time = time + 5 * n;


	BigInteger temporary;
	temporary = temp3 + temp2;
	temporary = temporary + temp1;
	temporary = temporary - temp4;
	temporary = temporary - temp5;
	temporary.removeZeros();
	temporary.length = temporary.number.length();
	if (sign == -1) temporary.changesign();//when occured change
	return temporary;

}

BigInteger operator/(const BigInteger & a, const BigInteger & b)
{//Based on N/D=Q+R
	int n1 = a.number.length();
	int n2 = b.number.length();
	int sign = 1;
	if (n1 < n2) return BigInteger("0");
	BigInteger Nomin = a;
	if (Nomin.number == "0")return BigInteger("0");
	if (Nomin.sign == -1)
	{
		sign = sign * -1;
	}
	BigInteger Denomin = b;
	if (Denomin.sign == -1)
	{
		sign = sign * -1;
	}
	if (Denomin.number == "0")throw "can't divide by 0!\n";
	BigInteger A = Denomin;//quick diviser
	BigInteger R = Nomin;//reminder
	BigInteger Q;//quotient
	BigInteger Qn;//new quotient
	int temp;//help
	int reminder;
	int M = Denomin.number.length() - 1;//denomin length -1
	for (size_t i = 1; i < A.number.length(); i++) {
		A.number[i] = 0 + '0';
	}
	BigInteger Rp = R;//for abs check
	while (Rp.mod() >= Denomin)
	{
		Q.numberDelete();//for clarity
		temp = 0;
		reminder = 0;
		for (size_t i = 0; i < R.number.length() - M; i++)
		{
			temp = 10 * reminder + (R.number[i] - '0');
			int topush = temp / (A.number[0] - '0');//for the i'th number in our quotient
			Q.number += to_string(topush);
			Q.length = Q.number.length();
			reminder = temp - int(Q.number[i] - '0') * int(A.number[0] - '0');
		}
		if (R.sign == -1) { Q.sign = -1; }//when we need to substract
		Qn = (Q + Qn);
		R = Nomin-(Qn * Denomin);
		R.removeZeros();
		Rp = R;//for loop condition,not to change sign
	}
	if (R.sign == 1)
	{
		Qn.removeZeros();
		return Qn;//finish after that
	}
	Qn = Qn - BigInteger("1");//we have to do like in modulo class
	R = R + Denomin;
	if (sign < 0) Q.sign = -1;
	Qn.removeZeros();
	return Qn;
}

BigInteger operator/(const BigInteger & a, const string & b)
{
	int n1 = a.number.length();
	int n2 = b.length();
	int sign = 1;
	if (n1 < n2) return BigInteger("0");
	BigInteger Nomin = a;
	if (Nomin.number == "0")return BigInteger("0");
	if (Nomin.sign == -1)
	{
		sign = sign * -1;
	}
	BigInteger Denomin = b;
	if (Denomin.sign == -1)
	{
		sign = sign * -1;
	}
	if (Denomin.number == "0")throw "can't divide by 0!\n";
	BigInteger A = Denomin;//quick diviser
	BigInteger R = Nomin;//reminder
	BigInteger Q;//quotient
	BigInteger Qn;//new quotient
	int temp;//help
	int reminder;
	int M = Denomin.number.length() - 1;//denomin length -1
	for (size_t i = 1; i < A.number.length(); i++) {
		A.number[i] = 0 + '0';
	}
	BigInteger Rp = R;//for abs check
	while (Rp.mod() >= Denomin)
	{
		Q.numberDelete();//for clarity
		temp = 0;
		reminder = 0;
		for (size_t i = 0; i < R.number.length() - M; i++)
		{
			temp = 10 * reminder + (R.number[i] - '0');
			int topush = temp / (A.number[0] - '0');//for the i'th number in our quotient
			Q.number += to_string(topush);
			Q.length = Q.number.length();
			reminder = temp - int(Q.number[i] - '0') * int(A.number[0] - '0');
		}
		if (R.sign == -1) { Q.sign = -1; }//when we need to substract
		Qn = Q + Qn;
		R = Nomin - (Qn * Denomin);
		R.removeZeros();
		Rp = R;//for loop condition,not to change sign
	}
	if (R.sign == 1)
	{
		Qn.removeZeros();
		return Qn;//finish after that
	}
	Qn = Qn - BigInteger("1");//we have to do like in modulo class
	R = R + Denomin;
	if (sign < 0) Q.sign = -1;
	Qn .removeZeros();
	return Qn;
}


bool operator<(const BigInteger & a, const BigInteger & b)
{
	if (a.number.length() > b.number.length())return false;
	else if (a.number.length() == b.number.length()) {
		for (size_t i = 0; i < a.number.length(); i++)
		{
			if (a.number[i] == b.number[i])
			{
				continue;
			}
			if (a.number[i] > b.number[i])
			{
				return false;
			}
			if (a.number[i] < b.number[i])
			{
				return true;
			}
		}
	}
	else return true;
	return false;//when all elements are equal, after completing loop
}

bool operator<=(const BigInteger & a, const BigInteger & b)
{
	if (a.number.length() > b.number.length())return false;
	else if (a.number.length() == b.number.length()) {
		for (size_t i = 0; i < a.number.length(); i++)
		{
			if (a.number[i] == b.number[i])
			{
				continue;
			}
			if (a.number[i] > b.number[i])
			{
				return false;
			}
			if (a.number[i] < b.number[i])
			{
				return true;
			}
		}
	}
	else return true;
	return true;//all elements equal
}

bool operator>=(const BigInteger & a, const BigInteger & b)
{
	if (a.number.length() < b.number.length())return false;
	else if (a.number.length() == b.number.length()) {
		for (size_t i = 0; i < a.number.length(); i++)
		{
			if (a.number[i] == b.number[i])
			{
				continue;
			}
			if (a.number[i] > b.number[i])
			{
				return true;
			}
			if (a.number[i] < b.number[i])
			{
				return false;
			}
		}
	}
	else return true;
	return true;//all elements equal
}

bool operator>(const BigInteger & a, const BigInteger & b)
{
	if (a.number.length() < b.number.length())return false;
	else if (a.number.length() == b.number.length()) {
		for (size_t i = 0; i < a.number.length(); i++)
		{
			if (a.number[i] == b.number[i])
			{
				continue;
			}
			if (a.number[i] > b.number[i])
			{
				return true;
			}
			if (a.number[i] < b.number[i])
			{
				return false;
			}
		}
	}
	else return true;
	return false;//all elements equal
}

bool operator==(const BigInteger & a, const BigInteger & b)
{
	if (a.number.length() != b.number.length())
	{
		return false;
	}
	for (size_t i = 0; i < a.number.length(); i++)
	{
		if (a.number[i] != b.number[i])return false;
	}
	return true;

}

bool operator!=(const BigInteger & a, const BigInteger & b)
{
	for (size_t i = 0; i < a.number.length(); i++)
	{
		if (a.number[i] != b.number[i])return true;
	}
	return false;
}

char BigInteger::operator[](int n)
{
	assert(n >= 0);
	assert(n < this->number.length());
	return this->number[n];
}

ostream & operator<<(ostream & out, const BigInteger & a)
{
	out << a.number;
	return out;
}

istream & operator>>(istream & in, BigInteger & a)
{
	string g;
	in >> g;
	if (isalpha(g[0]))
	{
		throw "NO ALPHA ALOWED\n";
	}
	a.number = g;
	return in;
}
