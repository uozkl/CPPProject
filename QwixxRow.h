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
private:
	T scoreArray;

};

#endif /* QWIXXROW_H */

