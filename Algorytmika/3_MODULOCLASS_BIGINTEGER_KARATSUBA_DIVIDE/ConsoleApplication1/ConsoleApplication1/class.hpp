#ifndef class_hpp
#define class_hpp
#include <iostream>
#include <math.h>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <exception>
/** \brief Klasa zawierajaca metody, konstruktory i operatory dla ciała modulo */
using namespace std;
class Z_13
{
private:
    int p = 13; /** \var liczba do dzielenia modulo*/
    int value;  /** \var efekt dzielenia modulo*/
public:
    static const string error[3];
    Z_13();
    Z_13(int a);
    friend Z_13 operator +(const Z_13 & a, const Z_13 &b);  /**\fn operator dodawania 2 wartosci i zrobienie z niej wartosci modulo*/
    friend Z_13 operator -(const Z_13 & a, const Z_13 &b);  /**\fn operator odejmowania 2 wartosci i zrobienie z niej wartosci modulo*/
    friend Z_13 operator *(const Z_13 & a, const Z_13 &b);  /**\fn operator mnożenia 2 wartosci i zrobienie z niej wartosci modulo*/
    friend Z_13 operator /(const Z_13 & a, const Z_13 &b);  /**\fn operator dzielenia 2 wartosci i zrobienie z niej wartosci modulo*/
    Z_13 & operator -();    /**\fn operator zmiany znaku wartosci i zrobienie z niej wartosci modulo*/
    Z_13 & operator = (const Z_13 & a); /**\fn operator proównania*/
    friend ostream & operator <<(ostream & out,const Z_13 &a)/**\fn operator do ostream*/
    {
        out << a.value; /** wysyła wartość liczby modulo*/
        out << endl;
        return out;
    }
    Z_13 & operator +=(const Z_13 &a); /**operatory z pdpktu b*/
    Z_13 & operator -=(const Z_13 &a);
    Z_13 & operator *=(const Z_13 &a);
    Z_13 & operator /=(const Z_13 &a);
    friend bool operator <(const Z_13 &a, const Z_13 &b);/**operatory logiczne*/
    friend bool operator <=(const Z_13 &a, const Z_13 &b);
    friend bool operator >=(const Z_13 &a, const Z_13 &b);
    friend bool operator >(const Z_13 &a, const Z_13 &b);
    friend bool operator ==(const Z_13 &a, const Z_13 &b);
    friend bool operator !=(const Z_13 &a, const Z_13 &b);
    friend istream & operator >>(istream & in, Z_13 &a) /**operator pobierania danych*/
    {
        string g;
        in >> g;
        if(isalpha(g[0]))
        {
            throw 1;
        }
        istringstream s(g);
        float x;
        s >> x;
        int y = int(x);
        if(x - y != 0)
        {
            throw 2; /**wyrzucamy wyjatek, ze liczba musi byc calkowita*/
        }
        a.value =(int) x % a.p;
        return in;
    }
};
#endif // class_hpp
