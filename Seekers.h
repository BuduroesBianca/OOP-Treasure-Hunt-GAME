#pragma once
#include "Map.h"
#include<iostream>


class Seekers
{
	int coordX, coordY, life;
	char name;
	int ID; // ordinea jucatorilor

public:

	virtual void move(MAP&) = 0;
	Seekers();
	
	void Alive(); // life = 1
	void Dead(); // life = 0
	void SetID(const int); // seteaza ID-ul jucatorului
	int GetID() const; // getter pentru ID
	void SetPlayers(int); // aseaza jucatorii pe harta in functie de ID
	int Life() const; // returneaza stadiul in care se afla jucatorul (mort/viu)
	void SetCoordX(int); // seteaza coordonata X
	void SetCoordY(int); // seteaza coordonata Y
	void SetName(char); // seteaza numele
	int GetCoordX() const; // getter pentru coordonata X
	int GetCoordY() const; // getter pentru coordonata Y

};

