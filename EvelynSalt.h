#pragma once
#include "Seekers.h"
#include "Map.h"
#include "Game.h"

/*
		Evelyn Salt parcurge harta printr-o miscare de zig-zag.
		La pasul impar urca pe linie, iar la pasul par trece 
		pe urmatoarea coloana.

		Aceasta poate vedea doar anumite comori din jurul ei 
		(stanga-dreapta, sus-jos) si le poate accesa in momentul
		in careacestea se afla langa ea.
					 
		O O O O O		O O O O *		
		O O O O O		O O O * *	
		O O O O O		O O * * O	
		O O O O O		O * * O O
		O O O O O		* * O O O	
*/


class EvelynSalt: public Seekers
{
	int pas;

public:

	EvelynSalt(MAP&);

	void move(MAP&);
};

