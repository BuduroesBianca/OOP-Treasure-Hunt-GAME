#pragma once
#include "Map.h"
#include "Seekers.h"

/*
		James Bond se misca in spirala in prima jumatate a hartii.
		Daca dimensiunea hartii este un numar par, atunci acesta
		coboara pe coloanele pare si urca pe cel impare, daca dimensiunea
		hartii este un numar impar, acesta urca pe coloanele pare
		si coboara pe cele impare.

		El poate vedea comorile din jurul lui si le acceseaza daca
		acestea sunt langa el (stanga-dreapta, sus-jos, dar si diagonale).
							 _   _
		O O O O O			| | | | |
		O O O O O			| |_| |_|
		O O O O O			O O O O O
		O O O O O			O O O O O
		O O O O O			O O O O O
*/

class JamesBond: public Seekers
{
public:

	JamesBond(MAP&);

	void move(MAP&);

};

