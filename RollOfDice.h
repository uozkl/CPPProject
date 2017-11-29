
/* 
 * File:   RollOfDice.h
 * Author: Tony
 *
 * Created on
 */

#ifndef ROLLOFDICE_H
#define ROLLOFDICE_H
#include<iostream>
#include "Dice.h"
using namespace std;
class RollOfDice {
	vector<Dice>elems;
	int num = 0;
public:
	RollOfDice();
	void add(Dice &_dice);
	Dice fetch(int posit);
	void roll();
	RollOfDice pair(Dice &diceA, Dice &diceB);
	int *begin();
	int *end();
	operator int() const;
	ostream& operator<<(ostream &os);
};

#endif /* ROLLOFDICE_H */

