// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
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

class Urn
{
private:
	vector<int> urn_fill;
	int urnNumber;//how many urnas 
	int ballNumber;//how many balls
	int howManyEmpty;
	bool isEmpty;
	bool isFull;
public:
	Urn(int urn_Number, int ball_Number);
	Urn(const Urn &a);//copy
	~Urn();//destruct
	Urn();//default

	void setAllAgain(int urn_Number, int ball_Number);//works same as constructor with numbers
	void addUrn(int num);//adds an urn
	void addBalls(int num);//adds this many balls
	int addBallsWPosition();//the same as before but adds one ball and returns last added position
	void putBalls();//resetting ball positions
	void empty();//emptpies all urns 
	void isFully();//when every urn has at least 1 ball
	void isAtLeast(int num);
	void isInOne(int num);// when we get num many balls just in one urn
	int howManyEmpt();

	int thisBall();
	int thisUrns();//tells how many of them

};

#endif //PCH_H
