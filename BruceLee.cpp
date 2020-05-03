#include "BruceLee.h"
#include "Map.h"
#include<iostream>

using namespace std;

BruceLee::BruceLee(MAP& harta) 
{
	SetName('B');
	SetID(3);
	SetPlayers(harta.dimension);
	harta.map[GetCoordX()][GetCoordY()] = 'B';
	Alive();
}

void BruceLee::move(MAP& harta) 
{
	if (Life() == 1) // daca jucatorul inca este in viata

	{	
		// verific daca exista vreo comoara langa jucator (stanga-dreapta, sus-jos, diagonale)

		if (harta.map[GetCoordX() - 1][GetCoordY() - 1] == 'T' || // i-1 && j-1
			harta.map[GetCoordX() - 1][GetCoordY()] == 'T' ||    //  i-1 && j
			harta.map[GetCoordX() - 1][GetCoordY() + 1] == 'T' || // i-1 && j+1
			harta.map[GetCoordX()][GetCoordY() + 1] == 'T' ||     // i && j+1
			harta.map[GetCoordX() + 1][GetCoordY() - 1] == 'T' || // i+1 && j-1
			harta.map[GetCoordX() + 1][GetCoordY()] == 'T' ||     // i+1 && j
			harta.map[GetCoordX() + 1][GetCoordY() + 1] == 'T' ||  // i+1 && j+1
			harta.map[GetCoordX()][GetCoordY() - 1] == 'T') {      //i && j-1

			// daca da, caut exact locul

			if (harta.map[GetCoordX() - 1][GetCoordY() - 1] == 'T') // i-1 && j-1
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX() - 1][GetCoordY() - 1] = '*';
				SetCoordX(GetCoordX() - 1);
				SetCoordY(GetCoordY() - 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';

			}
			if (harta.map[GetCoordX() - 1][GetCoordY()] == 'T') // i-1 && j
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX() - 1][GetCoordY()] = '*';
				SetCoordX(GetCoordX() - 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';

			}
			if (harta.map[GetCoordX() - 1][GetCoordY() + 1] == 'T') // i-1 && j+1
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX() - 1][GetCoordY() + 1] = '*';
				SetCoordX(GetCoordX() - 1);
				SetCoordY(GetCoordY() + 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';
			}
			if (harta.map[GetCoordX()][GetCoordY() + 1] == 'T') // i && j+1
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX()][GetCoordY() + 1] = '*';
				SetCoordY(GetCoordY() + 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';
			}
			if (harta.map[GetCoordX() + 1][GetCoordY() - 1] == 'T') // i+1 && j-1
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX() + 1][GetCoordY() - 1] = '*';
				SetCoordX(GetCoordX() + 1);
				SetCoordY(GetCoordY() - 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';
			}
			if (harta.map[GetCoordX() + 1][GetCoordY()] == 'T') // i+1 && j
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX() + 1][GetCoordY()] = '*';
				SetCoordX(GetCoordX() + 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';
			}
			if (harta.map[GetCoordX() + 1][GetCoordY() + 1] == 'T') // i+1 && j+1
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX() + 1][GetCoordY() + 1] = '*';
				SetCoordX(GetCoordX() + 1);
				SetCoordY(GetCoordY() + 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';
			}
			if (harta.map[GetCoordX()][GetCoordY() - 1] == 'T') // i && j-1
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				harta.map[GetCoordX()][GetCoordY() - 1] = '*';
				SetCoordY(GetCoordY() - 1);
				harta.map[GetCoordX()][GetCoordY()] = '*';
			}

			cout << "Bruce Lee found a TREASURE on position (" << GetCoordX() << "," << GetCoordY() << ")";
			harta.TreasureFound();
			harta.DecreaseNrOfHunters();
			Dead();
			harta.PutPlayerInPlace(this->GetID()); // pun jucatorul in vector pt podium
			cout << "There are only " << harta.GetNrOfHunters() << " hunters left" << endl;
		}

		// cazul in care jucatorul se blocheaza

		else if (harta.map[GetCoordX() - 1][GetCoordY() - 1] == '*')
		{	
			harta.map[GetCoordX()][GetCoordX()] = '*';
			Dead();
			harta.DecreaseNrOfHunters();
			cout << "Bruce Lee died because he got stuck" << endl;
			cout << "There are only " << harta.GetNrOfHunters() << " hunters left" << endl;	
		}
		 
		// cazul in care jucatorul se poate misca

		else
		{
			// daca acesta se poate misca, o face urcand pe a 2a diagonala

			harta.map[GetCoordX()][GetCoordY()] = '*';
			SetCoordX(GetCoordX() - 1);
			SetCoordY(GetCoordY() - 1);
			harta.map[GetCoordX()][GetCoordY()] = 'B';
			cout << "Bruce Lee moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
		}
	}
}
