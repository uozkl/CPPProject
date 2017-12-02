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
	bool validate(RollOfDice rd, int pos) {
		if(pos<0 || pos>9){
			return false;
		}

		if (scoreArray[pos] != 0) {
			return false;
		}
		int i;
		for (i = pos; i > -1; --i) {
			if (scoreArray[i] >= rd) {
				return false;
			}
		}
		for (i = pos; i < 10; ++i) {

			if (scoreArray[i] <= rd && scoreArray[i] != 0) {
				return false;
			}
		}
		return true;

	}
	;
	int& operator[](int i) {
		return scoreArray[i];
	}

	int scoreArray[10] = { };
};

#endif /* QWINTOROW_H */

