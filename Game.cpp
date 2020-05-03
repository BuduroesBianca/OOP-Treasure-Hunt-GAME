#include "Game.h"
#include "Map.h"
#include "LaraCroft.h"
#include "JamesBond.h"
#include "BruceLee.h"
#include "Seekers.h"
#include "EvelynSalt.h"
#include<iostream>
#include<exception>

using namespace std;

void Game::StartGame()
{
	cout << "Jocul va incepe in curand!" << endl;
	cout << "Introduceti dimensiunea laturii hartii (minim 15)" << endl;

	int n, ok = 0;
	while (ok == 0) // testam inputul pentru dimenisune pana acesta este corect
	{
		try
		{
			cin >> n;
			if (n < 15)
			{
				throw n;
			}
			else
				ok = 1; // inputul este corect
		}
		catch (int)
		{
			cout << "Dimensiunea laturii hartii trebuie sa fie minim 15!" << endl;
		}
	}	
	
	MAP harta(n);
	harta.RandomTreasures(); // asez comorile pe harta
	harta.SetNrOfHunters(4); // setez numarul de jucatori
	LaraCroft L(harta); 
	JamesBond J(harta);
	BruceLee B(harta);
	EvelynSalt E(harta);
	cout << harta << endl;
	CurrentRound = 0; // initializam runda curenta

	cout << "Cum doriti sa se desfasoare jocul? Alegeti una din optiunile de mai jos!" << endl;
	cout << "Modul 1: Simularea succesiva a rundelor" << endl;
	cout << "Modul 2: Oprirea simularii la fiecare 3 runde cu optiunea de continuare sau oprire" << endl;
	cout << "Ambele moduri permit afisarea configuratiei hartii la fiecare sfarsit de runda simulata" << endl;
	cout << "Introduceti modul dorit: 1 sau 2 -> ";

	int mod, optiune = 1;
	ok = 0;
	while (ok == 0) // testam inputul pentru optiune pana acesta este corect
	{
		try
		{
			cin >> mod;
			if (mod != 1 && mod != 2)
			{
				throw mod;
			}
			else
				ok = 1; // inputul este corect
		}
		catch (int)
		{
			cout << "Numarul introdus este gresit. Alegeti unul din modurile prezentate! :)" << endl;
		}
	}

	if (mod == 1) // simularea succesiva a rundelor
	{
		while (harta.GetNrOfHunters() > 0 && harta.GetNrOfTreasures() > 0) 
		{
			CurrentRound++; // cresc runda curenta
			cout << "Runda numarul: " << CurrentRound << endl; // afisez numarul rundei

			// jucatorii se misca

			L.move(harta);
			J.move(harta);
			B.move(harta);
			E.move(harta);

			cout << endl << harta << endl;
		}
	}
	else if(mod == 2) // Oprirea simularii la fiecare 3 runde
	{
		cout << endl;
		system("pause");
		cout << endl;

		do {
			CurrentRound++;
			cout << "Runda numarul: " << CurrentRound << endl;
			L.move(harta);
			J.move(harta);
			B.move(harta);
			E.move(harta);
			cout << endl;
			cout << harta << endl << endl;

			// daca runda este divizibila cu 3 si inca avem jucatori si comori oprim afisarea
			// rundelor si intrebam utilizatorul daca vrea sa continue

			if (CurrentRound % 3 == 0 && harta.GetNrOfHunters() > 0 && harta.GetNrOfTreasures() > 0)
			{
				cout << "Doriti sa mai continuati? 1 inseamna DA / 0 inseamna NU -> ";
				ok = 0;
				while (ok == 0)
				{
					try
					{
						cin >> optiune;
						if (optiune != 1 && optiune != 0)
						{
							throw optiune;
						}
						else
							ok = 1;
					}
					catch (int)
					{
						cout << "Optiunea dorita este incorecta. Va rugam introduceti 1 pentru Da si 0 pentru NU" << endl;
					}
				}
				cout << endl;
			}	
		} while (optiune == 1 && harta.GetNrOfHunters() > 0 && harta.GetNrOfTreasures() > 0); // rulam cat timp utilizatorul doreste sa continue


		cout << harta << endl;
	}
	cout << "Jocul s-a terminat!" << endl << endl;
	cout << "PODIUM" << endl << endl;
	harta.Results(); // afisarea podiumului
	cout << endl << "In cazul in care pe podium nu apar toti jucatorii, este datorita faptului ca" << endl << "restul jucatorilor au ramas blocati inainte de a gasi o comoara." << endl;
}
