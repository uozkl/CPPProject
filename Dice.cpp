/*
 * Dice.cpp
 *
 *  Created on: 2017?11?17?
 *      Author: Nathan
 */

#include "Dice.h"

namespace std {
	Dice::Dice(Colour &_colour):colour(_colour)
	{
	}
	void Dice::roll()
	{
		face = new RandomDice->getDice;
	}
	ostream & Dice::operator<<(ostream & os)
	{
		char *colorNames[] = { "Red","Blue","Yellow","Green","White" };
		os << colorNames[(int)colour] << " " + face << endl;
		return os;
	}
} /* namespace std */
