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

	friend ostream& operator<<(ostream &os, RollOfDice rod);
public:
	RollOfDice();
	void add(Dice &_dice);
	Dice fetch(int posit);
	void roll();
	RollOfDice pair(Dice &diceA, Dice &diceB);
	Dice *begin();
	Dice *end();
	operator int() const;
	vector<Dice> elems;
	int num = 0;
	//Dice setDice(string ipt);

};

#endif /* ROLLOFDICE_H */

