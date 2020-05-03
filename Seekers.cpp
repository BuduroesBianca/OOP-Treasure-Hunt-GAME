#include "Seekers.h"
#include<iostream>

Seekers::Seekers(): coordX(0), coordY(0), life(1), ID(0), name(NULL) {} // constructor cu lista de initializare

void Seekers::SetName(char x) 
{
	name = x;
}

void Seekers::SetPlayers(int n) // asezam jucatorii in colturile hartii in functie de ID
{
	if (ID == 1) 
	{
		coordX = 1;
		coordY = 1;
	}
	if (ID == 2)
	{
		coordX = 1;
		coordY = n;
	}
	if (ID == 3) 
	{
		coordX = n;
		coordY = n;
	}
	if (ID == 4) 
	{
		coordX = n;
		coordY = 1;
	}
}

void Seekers::Alive() 
{
	life = 1; // e viu
}

void Seekers::Dead()
{
	life = 0; // a murit
}

void Seekers::SetID(const int x) 
{
	ID = x;
}

int Seekers::GetID() const
{
	return ID;
}

int Seekers::Life() const 
{
	return life;
}

void Seekers::SetCoordX(int x) // setam coordonata X
{
	coordX = x;
}

void Seekers::SetCoordY(int y) // setam coordonata Y
{
	coordY = y;
}

int Seekers::GetCoordX() const // getter pentru coordonata X
{
	return coordX;
}

int Seekers::GetCoordY() const // getter pentru coordonata Y
{
	return coordY;
}
