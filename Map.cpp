#include <iostream>
#include "Map.h"
#include <ctime>
#include <cstdlib>


MAP::MAP(int n):nrOfHunters(0), nrOfTreasures(0)
{
	dimension = n;
	map = new char* [dimension + 2]; // creez harta n+2/n+2 pentru a realiza un gard in jurul acesteia
	for (int i = 0; i < dimension + 2; i++) 
	{ // creez harta
		map[i] = new char[dimension + 2];
	}
	for (int i = 1; i < dimension + 1; i++) 
	{ 
		for (int j = 1; j < dimension + 1; j++) 
		{
			map[i][j] = ' '; // folosesc ' ' pt marcarea spatiilor libere din harta
		}
	}

	for (int i = 0; i < dimension + 2; i++) 
	{
		map[i][0] = '*'; // folosesc '*' pt spatiile deja vizitate, dar si pentru a crea un "gard" in jurul hartii
		map[i][dimension + 1] = '*';
		map[0][i] = '*';
		map[dimension + 1][i] = '*';
	}


}

MAP::~MAP() // destructor
{
	for (int i = 0; i < dimension; i++) 
	{
		delete[] map[i];
	}
	delete[] map;
}

void MAP::RandomTreasures() 
{
	nrOfTreasures = 3; // asezarea comorilor pe harta
	srand(time(0));
	int coordx, coordy;
	for (int i = 0; i < 3; i++) 
	{
		coordx = rand() % dimension + 1;
		coordy = rand() % dimension + 1;

		// nu asezam comorile in colturi
		while ((coordx == 1 && coordy == 1) || (coordx == 1 && coordy == dimension) ||
			(coordx == dimension && coordy == 1) || (coordx == dimension && coordy == dimension)) 
		{
			coordx = rand() % dimension + 1;
			coordy = rand() % dimension + 1;
		}
		map[coordx][coordy] = 'T'; // marcam comorile cu 'T'
	}
}

void MAP::PutPlayerInPlace(int id) // pun jucatorii care au gasit comori in vector in ordinea iesirii din joc
{
	this->lengthPlaces++;
	PlayersPlaces[this->lengthPlaces] = id;

}

int MAP::GetDimension() const 
{
	return dimension;
}

int MAP::GetNrOfTreasures() const 
{
	return nrOfTreasures;
}

int MAP::GetNrOfHunters() const 
{
	return nrOfHunters;
}

void MAP::DecreaseNrOfHunters() // scad nr de jucatori cand cineva gaseste o comoara sau ramane blocat
{
	nrOfHunters--;
}

void MAP::SetNrOfHunters(int x) 
{
	nrOfHunters = x;
}

void MAP::TreasureFound() // scad nr de comori cand cineva gaseste o comoara
{
	nrOfTreasures--;
}

ostream& operator<<(ostream& out, const MAP& M) 
{
	for (int i = 0; i < M.dimension + 2; i++) 
	{
		for (int j = 0; j < M.dimension + 2; j++) 
		{
			out << M.map[i][j] << " ";
		}
		out << endl;
	}
	out << endl;
	return out;
}

void MAP::Results() // PODIUM
{
	int l = this->lengthPlaces;

	if (l == 0)
	{
		cout << "Nimeni nu a castigat! Nicio comoara nu a fost gasita!" << endl;
	}
	else
	{
		for (int i = 1; i <= l; i++)
		{
			if (i == 1)
			{
				if (PlayersPlaces[i] == 1)
					cout << "Lara Croft a CASTIGAT jocul!!!" << endl;
				else if (PlayersPlaces[i] == 2)
					cout << "James Bond a CASTIGAT jocul!!!" << endl;
				else if (PlayersPlaces[i] == 3)
					cout << "Bruce Lee a CASTIGAT jocul!!!" << endl;
				else
					cout << "Evelyn Salt a CASTIGAT jocul!!!" << endl;
			}
			else
			{
				if (PlayersPlaces[i] == 1)
					cout << "Lara Croft este pe locul: " << i << endl;
				else if (PlayersPlaces[i] == 2)
					cout << "James Bond este pe locul: " << i << endl;
				else if (PlayersPlaces[i] == 3)
					cout << "Bruce Lee este pe locul: " << i << endl;
				else
					cout << "Evelyn Salt este pe locul: " << i << endl;
			}
		}
	}
}