#include "EvelynSalt.h"
#include "Map.h"
#include "Game.h"
#include<iostream>

using namespace std;

EvelynSalt::EvelynSalt(MAP& harta)
{
	SetName('E');
	SetID(4);
	SetPlayers(harta.dimension);
	harta.map[GetCoordX()][GetCoordY()] = 'E';
	Alive();
	pas = 0;
}

void EvelynSalt::move(MAP& harta)
{
	if (Life() == 1) // daca jucatorul inca este in viata
	{
		// verific daca este vreo comoara in jurul acesteia, doar stanga-dreapta, sus-jos

		if (harta.map[GetCoordX() - 1][GetCoordY()] == 'T' || // i-1 && j 
			harta.map[GetCoordX()][GetCoordY() + 1] == 'T' || // i && j+1
			harta.map[GetCoordX() + 1][GetCoordY()] == 'T' || // i+1 && j
			harta.map[GetCoordX()][GetCoordY() - 1] == 'T' )  // i && j-1
		{
			// daca da, caut exact locul

			if (harta.map[GetCoordX() - 1][GetCoordY()] == 'T') // i-1 && j
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX() - 1][GetCoordY()] = '*';
				SetCoordX(GetCoordX() - 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';

			}
			if (harta.map[GetCoordX()][GetCoordY() + 1] == 'T') // i && j+1
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX()][GetCoordY() + 1] = '*';
				SetCoordY(GetCoordY() + 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';
			}
			if (harta.map[GetCoordX() + 1][GetCoordY()] == 'T') // i+1 && j
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX() + 1][GetCoordY()] = '*';
				SetCoordX(GetCoordX() + 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';
			}
			if (harta.map[GetCoordX()][GetCoordY() - 1] == 'T') // i && j-1
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX()][GetCoordY() - 1] = '*';
				SetCoordY(GetCoordY() - 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';
			}

			cout << "Evelyn Salt found a TREASURE on position (" << GetCoordX() << "," << GetCoordY() << ")";
			harta.TreasureFound();
			harta.DecreaseNrOfHunters();
			Dead();
			harta.PutPlayerInPlace(this->GetID()); // pun jucatorul in vetcor pt podium
			cout << "There are only " << harta.GetNrOfHunters() << " hunters left" << endl;
		}

		// cazul in care jucatorul ramane blocat

		else if((pas % 2 != 0 && harta.map[GetCoordX() - 1 ][GetCoordY()] == '*') ||
				(pas % 2 == 0 && harta.map[GetCoordX()][GetCoordY() + 1] == '*'))
		{
			
			harta.map[GetCoordX()][GetCoordY()] = '*';
			Dead();
			harta.DecreaseNrOfHunters();
			cout << "Evelyn Salt died because she got stuck" << endl;
			cout << "There are only " << harta.GetNrOfHunters() << " hunters left" << endl;
			
		}

		// cazul in care jucatorul se poate misca

		else
		{
			// daca aceasta se poate misca, atunci la pasul impar urca pe linie
			// iar la pasul par trece la urmatoarea coloana
			// miscare zig-zag pe prima diagonala

			if (pas % 2 != 0)
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				SetCoordX(GetCoordX() - 1); // scad linia pentru a urca
				harta.map[GetCoordX()][GetCoordY()] = 'E';
				cout << "Evelyn Salt moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
				pas++;
			}
			else
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				SetCoordY(GetCoordY() + 1); // trec la urmatoarea coloana
				harta.map[GetCoordX()][GetCoordY()] = 'E';
				cout << "Evelyn Salt moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
				pas++;
			}
		}

	}
}
