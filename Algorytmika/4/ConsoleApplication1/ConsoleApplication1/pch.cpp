// pch.cpp: plik źródłowy odpowiadający wstępnie skompilowanemu nagłówkowi, niezbędny do powodzenia kompilacji

#include "pch.h"
Urn::Urn(int urn_Number, int ball_Number)
{
	this->ballNumber = ball_Number;
	this->urnNumber = urn_Number;
	this->isEmpty = true;
	this->isFull = false;
	this->howManyEmpty = this->urnNumber;
	for (int i = 0; i < urn_Number; i++)
	{
		this->urn_fill.push_back(0);
	}
}
Urn::Urn(const Urn & a)
{
	this->urnNumber = a.urnNumber;
	this->ballNumber = a.ballNumber;
	this->isEmpty = a.isEmpty;
	this->isFull = a.isFull;
	this->urn_fill = a.urn_fill;
	this->howManyEmpty = a.urnNumber;
}
Urn::~Urn()
{
	this->urn_fill.clear();
}
Urn::Urn()
{
	this->ballNumber = 1;
	this->urnNumber = 1;
	this->howManyEmpty = 0;
	this->isEmpty = false;
	this->isFull = true;
}
void Urn::setAllAgain(int urn_Number, int ball_Number)
{
	this->ballNumber = ball_Number;
	this->urnNumber = urn_Number;
	this->empty();
	this->isEmpty = true;
	this->isFull = false;
	this->howManyEmpty = this->urnNumber;
	for (int i = 0; i < urn_Number; i++)
	{
		urn_fill.push_back(0);
	}
}
void Urn::addUrn(int num)
{
	for (int i = 0; i < num; i++)
	{
		this->urn_fill.push_back(0);
		this->urnNumber++;
		this->howManyEmpty++;
	}
	this->isFull = false;
}
void Urn::addBalls(int num)
{
	this->ballNumber = this->ballNumber + num;
	if (isEmpty == true) {
		this->putBalls();
	}//when empty puts all with the new ones included
	else
	{
		for (int i = 0; i < num; i++)
		{
			int position = (rand() % this->urnNumber);
			if (this->urn_fill[position] == 0)
			{
				this->howManyEmpty--;
			}
			this->urn_fill[position]++;//puts them randomly
		}
	}

	//this->isFully();
}
int Urn::addBallsWPosition()
{
	int position;
	this->ballNumber = this->ballNumber + 1;
	if (isEmpty == true) {
		this->putBalls();//when empty puts all with the new ones included
	}
	position = (rand() % this->urnNumber);
	if (this->urn_fill[position] == 0) this->howManyEmpty--;
	this->urn_fill[position]++;//puts it randomly
	
	//this->isFully();

	return position;
}
void Urn::putBalls()
{
	this->empty();
	this->howManyEmpty = this->urnNumber;
	for (int i = 0; i < this->ballNumber; i++)
	{
		int position = (rand() % this->urnNumber);
		if (this->urn_fill[position] == 0) this->howManyEmpty--;
		this->urn_fill[position]++;
	}
	this->isEmpty = false;
	this->isFully();
}
void Urn::empty()
{
	if (this->isEmpty == true) return;
	else
	{
		for (int i = 0; i < this->urnNumber; i++)
		{
			this->urn_fill[i] = 0;
		}
		this->isEmpty = true;
		this->isFull = false;
		this->howManyEmpty = this->urnNumber;
	}
}
void Urn::isFully()
{
	if (this->urnNumber == 0)throw "Cannot get into 0\n";
	for (int i = 0; i < this->urnNumber;i++)
		{
			if (this->urn_fill[i] == 0)
			{
				this->isFull = false;
				return;
			}
	}
	
}

void Urn::isAtLeast(int num)
{
	if (this->urnNumber == 0)throw "Cannot put into 0\n";
	bool isAtLeast = false;
	if (num == 1 ||this->isEmpty) {
		this->isFull = 0;
		this->ballNumber = 0;
		this->empty();
		this->addBalls(this->urnNumber*num - 1); //there cannot be at least without the balls before
	}
	int j = 0;
	
	while (!isAtLeast)
	{
		this->addBalls(1);
		for (int i = j; i < this->urnNumber; i++)
		{
			if (this->urn_fill[i] < num)
			{
				break;
			}
			j++;//not to check at the beginning again
		}
		if (j == this->urnNumber ) isAtLeast = true;
	}

}

void Urn::isInOne(int num)
{
	if (this->urnNumber == 0)throw "Cannot put into 0\n";
	this->empty();
	this->ballNumber = 0;
	while (true)
	{
		int temp=this->addBallsWPosition();
		if (this->urn_fill[temp] == num) return;//end when it has that amount of balls inside
	}
}

int Urn::howManyEmpt()
{
	this->empty();
	this->ballNumber = 0;
	this->addBalls(this->urnNumber);
	return this->howManyEmpty;
}

int Urn::thisBall()
{
	return this->ballNumber;
}

int Urn::thisUrns()
{
	return this->urnNumber;
}
