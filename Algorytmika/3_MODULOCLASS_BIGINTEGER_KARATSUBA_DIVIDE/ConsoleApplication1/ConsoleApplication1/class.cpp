#include "class.hpp"
using namespace std;
Z_13::Z_13()
{
    value = 0 % p; /** konstruktor bez argumentu przyjmuje wart 0*/
}
Z_13::Z_13(int a)
{
    value = a % p;  /** konstruktor z argumentem przyjmuje wart modulo p*/
}
Z_13 operator+(const Z_13 & a, const Z_13 &b)
{
    Z_13 w(a.value+b.value);
    return w;
}
const string Z_13::error[] = {"nie dziel przez 0!\n", "nie moze byc litera\n", "ma byc calkowita\n"}; /**\var tablica obsługi wyjątków*/
Z_13 operator-(const Z_13 & a, const Z_13 &b)
{
    Z_13 d(1);
    int c = a.value-b.value;
    if(c < 0)   /** jesli jest ujemne zmieniaja sie zasady działania*/
    {
    c *= -1;
    Z_13 w(a.p -  c);
    d = w;
    }
    else
    {
    Z_13 w(c);
    d = w;
    }
    return d;
}
Z_13 operator*(const Z_13 & a, const Z_13 &b)
{
    Z_13 w(a.value*b.value);
    return w;
}
Z_13 operator /(const Z_13 & a, const Z_13 &b)
{
    if(b.value == 0)
    {
        throw 0;
    }
    int b_odw = 1;//odwrócenie b^-1
    for(; b_odw < a.p; b_odw++) /**szukamy odwrotności liczby w przedziale 1- (p-1) która pomnozona z tą liczbą da po modulo p wart 1*/
    {
        if((b_odw*b.value) % 13 == 1)
        {
            break;
        }
    }
    Z_13 w(a.value*b_odw);
    return w;
}
Z_13 & Z_13::operator=(const Z_13 &a)
{
    this->value = a.value;
    return (*this);
}
Z_13 & Z_13::operator-()
{
    this -> value = this->p - (this -> value);
    return(*this);
}
Z_13 & Z_13::operator +=(const Z_13 &a)
{
    Z_13 w(this->value + a.value);
    this->value = w.value;
    return (*this);
}
Z_13 & Z_13::operator -=(const Z_13 &a)
{
    Z_13 w(this->value - a.value);
    this->value = w.value;
    return (*this);
}
Z_13 & Z_13::operator *=(const Z_13 &a)
{
    Z_13 w(this->value * a.value);
    this->value = w.value;
    return (*this);
}
Z_13 & Z_13::operator /=(const Z_13 &a)
{
    if(a.value == 0)
    {
        throw 0;
    }
    int a_odw = 1;//odwrócenie b^-1
    for(; a_odw < a.p; a_odw++)
    {
        if((a_odw*a.value) % 13 == 1)
        {
            break;
        }
    }
    Z_13 w(this->value*a_odw);
    this->value = w.value;
    return (*this);
}
bool operator <(const Z_13 &a, const Z_13 &b)
{
    if(a.value < b.value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool operator <=(const Z_13 &a, const Z_13 &b)
{
    if(a.value <= b.value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool operator >(const Z_13 &a, const Z_13 &b)
{
    if(a.value > b.value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool operator >=(const Z_13 &a, const Z_13 &b)
{
    if(a.value >= b.value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool operator ==(const Z_13 &a, const Z_13 &b)
{
    if(a.value == b.value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool operator !=(const Z_13 &a, const Z_13 &b)
{
    if(a.value != b.value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




