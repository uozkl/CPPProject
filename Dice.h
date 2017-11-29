/*
 * Dice.h
 *
 *  Created on
 *      Author: Nathan
 */

#ifndef DICE_H_
#define DICE_H_
#include "Colour.h"
#include <ostream>
using namespace std;
#include<iostream>
#include"RandomDice.h"
#include "Colour.h"
#include<string>


class Dice {

	friend ostream& operator<<(ostream& os, const Dice& d);
public:
	Dice(Colour c);
	int roll();
	//unsigned int face;
	const Colour color;
	int face = 0;
	const Colour colour;
public:
	Dice(Colour &_colour);
	void roll();
	int getFace() { return face; }
	Colour getColour() { return colour; }
	ostream& operator<<(ostream &os);

};



#endif /* DICE_H_ */
