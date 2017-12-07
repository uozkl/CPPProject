/* 
 * File:   QwixxRow.h
 * Author: Tony
 *
 * Created on
 */

#ifndef QWIXXROW_H
#define QWIXXROW_H
#include "RollOfDice.h"
#include"Colour.h"
#include <iostream>
using namespace std;

template<class T, Colour C>
class QwixxRow {
	friend ostream& operator<<(ostream& os, QwixxRow<T, C> row);
public:
	QwixxRow();
	QwixxRow<T, C> operator+=(RollOfDice rod);
	bool validate(RollOfDice rod);
	T scoreArray;

};
template<class T, Colour C>
bool QwixxRow<T,C>:: validate(RollOfDice rod){
	int position,counter;
	if (C == Colour::RED || C == Colour::YELLOW) position = rd - 2;
	else position = 12 - rd;
	for (auto a : scoreArray) {
		if (position > counter)++counter;
		else if (a > 0) return false;
	}
	return true;
};

#endif /* QWIXXROW_H */

