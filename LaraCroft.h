#pragma once
#include "Map.h"
#include "Seekers.h"

/* 
	LaraCroft se misca in spirala pe jumatatea de sus a hartii.
	Aceasta coboara pe coloanele impare si urca pe cele pare.

	Ea poate vedea comorile din jurul ei si ke acceseaza
	daca acestea se afla langa ea (stanga-dreapta, sus-jos, dar si diagonale)
							   _   _	
		O O O O O			| | | | |
		O O O O O			|_| |_| |
		O O O O O			O O O O O
		O O O O O			O O O O O
		O O O O O			O O O O O 

*/		

class LaraCroft : public Seekers
{
	
public:

	LaraCroft( MAP&);

	void move( MAP&);

};

