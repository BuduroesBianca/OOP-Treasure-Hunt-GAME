#include "LaraCroft.h"
#include "Map.h"
#include<iostream>

using namespace std;

LaraCroft::LaraCroft( MAP& harta) 
{
	SetName('L');
	SetID(1);
	SetPlayers(harta.dimension);
	harta.map[GetCoordX()][GetCoordY()] = 'L';
	Alive();
}

void LaraCroft::move( MAP& harta)
{

	if (Life() == 1) // daca jucatorul este inca in viata
	{

		// verificam daca o comoara este langa jucator (stanga-dreapta, sus-jos, diagonale)

		if (harta.map[GetCoordX() - 1][GetCoordY() - 1] == 'T' || // i-1 && j-1
			harta.map[GetCoordX() - 1][GetCoordY()] == 'T' ||    //  i-1 && j
			harta.map[GetCoordX() - 1][GetCoordY() + 1] == 'T' || // i-1 && j+1
			harta.map[GetCoordX()][GetCoordY() + 1] == 'T' ||     // i && j+1
			harta.map[GetCoordX() + 1][GetCoordY() - 1] == 'T' || // i+1 && j-1
			harta.map[GetCoordX() + 1][GetCoordY()] == 'T' ||     // i+1 && j
			harta.map[GetCoordX() + 1][GetCoordY() + 1] == 'T' ||  // i+1 && j+1
			harta.map[GetCoordX()][GetCoordY() - 1] == 'T')  //i && j-1
		{     
			// daca da, cautam exact locul

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

			cout << "Lara Croft found a TREASURE on position (" << GetCoordX() << "," << GetCoordY() << ")";
			harta.TreasureFound();
			harta.DecreaseNrOfHunters();
			Dead();
			cout << "There are only " << harta.GetNrOfHunters() << " hunters left" << endl;
			harta.PutPlayerInPlace(this->GetID()); // pun jucatorul in vector pentru podium
		}

		// cazurile in care jucatorul se blocheaza

		else if (harta.map[GetCoordX()][GetCoordY() + 1] == '*' && harta.map[GetCoordX() - 1][GetCoordY()] == '*' ||
				harta.map[GetCoordX() + 1][GetCoordY()] == 'B' ||
				GetCoordY() % 2 != 0 && harta.map[GetCoordX() + 1][GetCoordY()] == '*')
		{
			harta.map[GetCoordX()][GetCoordY()] = '*';
			Dead();		
			harta.DecreaseNrOfHunters();
			cout << "Lara Croft died because she got stuck" << endl;
			cout << "There are only " << harta.GetNrOfHunters() << " hunters left" << endl;
		}

		// cazul in care jucatorul inca este in cautare si se poate misca

		else
		{
			// aceasta se misca in spirala pe jumatatea de sus a hartii

			int limita = harta.dimension / 2; // calculam la ce linie se afla jumatatea hartii

			if (GetCoordX() < limita || GetCoordY() % 2 == 0) // verificam sa nu coboare mai jos de jumatate
			{
				if (GetCoordY() % 2 != 0) // daca nr coloanei este impar, aceasta coboara pe coloana
				{
					harta.map[GetCoordX()][GetCoordY()] = '*';
					SetCoordX(GetCoordX() + 1); // crestem linia pentru a putea cobori
					harta.map[GetCoordX()][GetCoordY()] = 'L'; 
					cout << "Lara Croft moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
				}
				else
				{
					// cazul in care urca

					if (GetCoordX() > 1) // daca poate urca
					{
						harta.map[GetCoordX()][GetCoordY()] = '*';
						SetCoordX(GetCoordX() - 1); // scadem linia pentru a urca
						harta.map[GetCoordX()][GetCoordY()] = 'L';
						cout << "Lara Croft moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
					}
					else if (GetCoordX() == 1) // daca a ajuns la limita de sus, trece la urmatoarea coloana
					{
						harta.map[GetCoordX()][GetCoordY()] = '*';
						SetCoordY(GetCoordY() + 1); // creste coloana
						harta.map[GetCoordX()][GetCoordY()] = 'L'; 
						cout << "Lara Croft moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
					}
				}
			}
			else if (GetCoordX() == limita) // daca ajunge la limita de jos
			{
				harta.map[GetCoordX()][GetCoordY()] = '*';
				SetCoordY(GetCoordY() + 1); // trece la urmatoarea coloana
				harta.map[GetCoordX()][GetCoordY()] = 'L';
				cout << "Lara Croft moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
			}

		}


	}
}
