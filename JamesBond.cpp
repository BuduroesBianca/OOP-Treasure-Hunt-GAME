#include "JamesBond.h"
#include "Map.h"
#include<iostream>

using namespace std;

JamesBond::JamesBond(MAP& harta) 
{
	SetName('J');
	SetID(2);
	SetPlayers(harta.dimension);
	harta.map[GetCoordX()][GetCoordY()] = 'J';
	Alive();
}


void JamesBond::move(MAP& harta) 
{

	if (Life() == 1) // daca jucatorul este in viata
	{

		// verificam daca o comoara este langa jucator (stanga-dreapta, sus-jos, diagonale)

		if (harta.map[GetCoordX() - 1][GetCoordY() - 1] == 'T' || // i-1 && j-1
			harta.map[GetCoordX() - 1][GetCoordY()] == 'T' ||    //  i-1 && j
			harta.map[GetCoordX() - 1][GetCoordY() + 1] == 'T' || // i-1 && j+1
			harta.map[GetCoordX()][GetCoordY() + 1] == 'T' ||     // i && j+1
			harta.map[GetCoordX() + 1][GetCoordY() - 1] == 'T' || // i+1 && j-1
			harta.map[GetCoordX() + 1][GetCoordY()] == 'T' ||     // i+1 && j
			harta.map[GetCoordX() + 1][GetCoordY() + 1] == 'T' ||  // i+1 && j+1
			harta.map[GetCoordX()][GetCoordY() - 1] == 'T') {      //i && j-1

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

			cout << "James Bond found a TREASURE on position (" << GetCoordX() << "," << GetCoordY() << ")";
			harta.TreasureFound();
			harta.DecreaseNrOfHunters();
			Dead();
			harta.PutPlayerInPlace(this->GetID()); // punem jucatorul in vector pentru podium
			cout << "There are only " << harta.GetNrOfHunters() << " hunters left" << endl;
		}

		// cazurile in care jucatorul se blocheaza

		else if (harta.map[GetCoordX()][GetCoordY() - 1] == '*' && harta.map[GetCoordX() - 1][GetCoordY()] == '*' ||
				 harta.map[GetCoordX()][GetCoordY() - 1] == 'L' && GetCoordX() == harta.dimension / 2)
		{
			harta.map[GetCoordX()][GetCoordY()] = '*';
			Dead();
			harta.DecreaseNrOfHunters();
			cout << "James Bond died because he got stuck" << endl;
			cout << "There are only " << harta.GetNrOfHunters() << " hunters left" << endl;
		}

		// cazul in care jucatorul inca este in cautare si se poate misca

		else
		{
			// acesta se misca in spirala pe jumatatea de sus a hartii, de la dreapta la stanga,
			// dar miscarea lui depinde de dimensiunea hartii

			int limita = harta.dimension / 2; // calculam la ce linie se afla jumatatea hartii

			if (harta.dimension % 2 != 0) // DACA DIMENSIUNEA ESTE IMPARA
			{
				if (GetCoordX() < limita || GetCoordY() % 2 == 0)
				{
					if (GetCoordY() % 2 != 0) // daca nr coloanei este impar, acesta coboara pe coloana
					{
						harta.map[GetCoordX()][GetCoordY()] = '*';
						SetCoordX(GetCoordX() + 1); // cresc linia pentru a cobori
						harta.map[GetCoordX()][GetCoordY()] = 'J';
						cout << "Jams Bond moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
					}
					else
					{
						// daca nr coloanei este par, acesta urca pe coloana

						if (GetCoordX() > 1) // daca jucatorul poate urca
						{
							harta.map[GetCoordX()][GetCoordY()] = '*';
							SetCoordX(GetCoordX() - 1); // scad linia pentru a urca
							harta.map[GetCoordX()][GetCoordY()] = 'J';
							cout << "James Bond moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
						}
						else if (GetCoordX() == 1) // daca jucatorul ajunge la limita de sus
						{
							harta.map[GetCoordX()][GetCoordY()] = '*';
							SetCoordY(GetCoordY() - 1); // trec la urmatoarea coloana
							harta.map[GetCoordX()][GetCoordY()] = 'J';
							cout << "James Bond moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
						}
					}
				}
				else if (GetCoordX() == limita) // daca jucatorul ajunge la limita de jos
				{
					harta.map[GetCoordX()][GetCoordY()] = '*';
					SetCoordY(GetCoordY() - 1); // trec la urmatoarea coloana
					harta.map[GetCoordX()][GetCoordY()] = 'J';
					cout << "James Bond moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
				}

			}
			else 
			{
				// DACA DIMENSIUNEA ESTE PARA

				if (GetCoordX() < limita || GetCoordY() % 2 != 0)
				{
					if (GetCoordY() % 2 == 0) // daca nr coloanei este par, acesta coboara pe coloana
					{
						harta.map[GetCoordX()][GetCoordY()] = '*';
						SetCoordX(GetCoordX() + 1); // cresc linia pentru a cobori
						harta.map[GetCoordX()][GetCoordY()] = 'J';
						cout << "James Bond moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
					}
					else
					{
						// daca nr coloanei este impar, acesta urca pe coloana

						if (GetCoordX() > 1) // daca are unde sa urce
						{
							harta.map[GetCoordX()][GetCoordY()] = '*';
							SetCoordX(GetCoordX() - 1); // micsorez linia pentru a urca
							harta.map[GetCoordX()][GetCoordY()] = 'J';
							cout << "James Bond moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
						}
						else if (GetCoordX() == 1) // daca ajunge la limita de sus
						{
							harta.map[GetCoordX()][GetCoordY()] = '*';
							SetCoordY(GetCoordY() - 1); // trec la urmatoarea coloana
							harta.map[GetCoordX()][GetCoordY()] = 'J';
							cout << "James Bond moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
						}
					}
				}
				else if (GetCoordX() == limita) // daca ajunge la limita de jos
				{
					harta.map[GetCoordX()][GetCoordY()] = '*';
					SetCoordY(GetCoordY() - 1); // trec la urmatoarea coloana
					harta.map[GetCoordX()][GetCoordY()] = 'J';
					cout << "James Bond moved to position (" << GetCoordX() << "," << GetCoordY() << ")" << endl;
				}
			}


		}
	}
}

