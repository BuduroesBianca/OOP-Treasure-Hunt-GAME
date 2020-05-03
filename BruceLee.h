#pragma once
#include "Seekers.h"
#include "Map.h"

/*
		Bruce Lee urca pe diagonala.

		Acesta poate vedea comorile din jurul lui si le poate accesa
		daca acestea se afla langa el (stanga-dreapta, sus-jos, diagonale).

							    
		O O O O O			\ O O O O
		O O O O O			O \ O O O
		O O O O O			O O \ O O
		O O O O O			O O O \ O
		O O O O O			O O O O \
*/


class BruceLee: public Seekers
{
public:

	BruceLee(MAP&);

	void move(MAP&);
};

