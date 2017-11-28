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


class Dice {

	friend ostream& operator<<(ostream& os, const Dice& d);
public:
	Dice();
	int roll();
	unsigned int face;
	const Colour color;
};



#endif /* DICE_H_ */
