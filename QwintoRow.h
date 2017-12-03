/* 
 * File:   QwintoRow.h
 * Author: Tony, Nathan
 *
 * Created on
 */

#ifndef QWINTOROW_H
#define QWINTOROW_H
#include"Dice.h"
#include "Colour.h"
#include "RollOfDice.h"
#include<iostream>
#include <array>
using namespace std;

template<Colour C> class QwintoRow {

	friend ostream& operator<<(ostream& os, QwintoRow<C> row);
public:

	bool validate(RollOfDice rd, int pos);
	int& operator[](int i) {
		return scoreArray[i-1];
	}

	int scoreArray[10] = { };
};
template<Colour C>
bool QwintoRow<C>::validate(RollOfDice rd, int pos) {
	bool cCheck = false;
	for (auto a : rd) {
		if (a.colour == C) {
			cCheck = true;
		}
	}
	if (!cCheck) {
		cout << "Row selected does not match the color of dices rolled."
				<< endl;
		return false;
	}

	if (pos < 0 || pos > 9) {
		cout << "Index out of range." << endl;
		return false;
	}

	if (scoreArray[pos-1] != 0) {
		cout << "This position is already occupied." << endl;
		return false;
	}
	int i;
	for (i = pos-1; i > -1; --i) {
		if (scoreArray[i] >= rd && scoreArray[i] > 0) {
			cout << "the number on the left must be smaller than this" << endl;
			return false;
		}
	}
	for (i = pos-1; i < 10; ++i) {

		if (scoreArray[i] <= rd && scoreArray[i] > 0) {
			cout << "the number on the right must be greater than this" << endl;
			return false;
		}
	}
	return true;

}

#endif /* QWINTOROW_H */

