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

template<class S, Colour C>
class QwixxRow {


	friend ostream& operator<<(ostream& os, QwixxRow<S,C> row);
public:
	QwixxRow();

	QwixxRow<S,C> operator+=(RollOfDice rod);
private:
	S scoreArray;

};

#endif /* QWIXXROW_H */

