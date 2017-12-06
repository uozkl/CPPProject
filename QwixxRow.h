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
	bool validate(RollOfDice rd, int pos);
	T scoreArray;
	//test2

};
template<class T, Colour C>
bool QwixxRow<T,C>:: validate(RollOfDice rd, int pos){

	return true;
};

#endif /* QWIXXROW_H */

