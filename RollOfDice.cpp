
/* 
 * File:   RollOfDice.cpp
 * Author: Tony
 * 
 * Created on 
 */

#include "RollOfDice.h"
#include <vector>

RollOfDice::RollOfDice()
{
}

void RollOfDice::add(Dice & _dice)
{
	elems.push_back(_dice);
	num++;
}

Dice RollOfDice::fetch(int posit)
{
	if (posit>=num|posit<0)throw out_of_range("Position out of range");
	Dice fetched = elems[posit];
	for (int n = posit; n < num; n++) {
		elems[n] = elems[n + 1];
	}
	elems.pop_back();
	num--;
	return fetched;
}

void RollOfDice::roll()
{
	for (Dice it : elems) {
		it.roll();
	}
}

RollOfDice RollOfDice::pair(Dice & diceA, Dice & diceB)
{
	RollOfDice outpt;
	outpt.add(diceA);
	outpt.add(diceB);
	return outpt;
}

int * RollOfDice::begin()
{
	if (num <= 0)throw out_of_range("Roll size out of range");
	return &elems[0];
}

int * RollOfDice::end()
{
	if (num <= 0)throw out_of_range("Roll size out of range");
	return &elems[num];
}

RollOfDice::operator int() const
{
	int sum = 0;
	for (Dice a : elems) {
		sum += a.getFace();
	}
}

ostream & RollOfDice::operator<<(ostream & os)
{
	for (Dice a : elems) {
		os<<a;
	}
	return os;
}
