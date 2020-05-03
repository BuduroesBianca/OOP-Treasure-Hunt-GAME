#pragma once
#include<iostream>

using namespace std;

class MAP
{
	char** map;
	int dimension, nrOfTreasures, nrOfHunters, PlayersPlaces[10], lengthPlaces = 0;

public:

	MAP(int); // constructor
	~MAP(); // destructor

	void RandomTreasures(); // aseaza comorile pe harta
	int GetDimension() const ; // getter pentru dimensiune
	int GetNrOfTreasures() const; // getter pentru nr de comori
	void TreasureFound(); // daca a gasit o comoara, atunci comori--
	void SetNrOfHunters(int); // seteaza numarul de jucatori
	int GetNrOfHunters() const; // getter pentru nr de jucatori
	void DecreaseNrOfHunters(); // daca a murit un jucator, atunci jucatori--
	void PutPlayerInPlace(int); // pune jucatorii in vectorul pentru podium
	void Results(); // afiseaza podiumul

	friend ostream& operator<<(ostream&, const MAP&);

	friend class LaraCroft;
	friend class JamesBond;
	friend class BruceLee;
	friend class EvelynSalt;

};