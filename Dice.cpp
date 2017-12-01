/*
 * Dice.cpp
 *
 *  Created on: 2017?11?17?
 *      Author: Nathan
 */

#include "Dice.h"
#include "RandomDice.h"

using namespace std;
	Dice::Dice(Colour &_colour):colour(_colour)
	{
	}
	void Dice::roll()
	{

		face = rd.getDice();
//return face;
	}
//	Dice& Dice:: operator=(const Dice& rhs){
//		colour(rhs.colour);
//		face = rhs.face;
//		return *this;
//	}
	ostream& operator<<(ostream& os, const Dice& d)
	{

		 //char *colorNames[] = { "Red","Blue","Yellow","Green","White" };
		string colourOut;
		switch(d.colour){
		case Colour::RED:
			colourOut="Red";
			break;
		case Colour::BLUE:
			colourOut = "Blue";
			break;
		case Colour::YELLOW:
			colourOut="Yellow";
			break;
		case Colour::GREEN:
			colourOut = "Green";
			break;
		case Colour::WHITE:
			colourOut = "White";
			break;
		}

		os << colourOut << " "<< d.face;
		return os;
	}

