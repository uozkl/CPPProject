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
	bool validate(RollOfDice rod,int &position);
	T scoreArray;

};
template<class T, Colour C>
bool QwixxRow<T,C>:: validate(RollOfDice rod,int &position){
	int counter;
	if (C == Colour::RED || C == Colour::YELLOW) position = rod - 2;
	else position = 12 - rod;
	for (auto a : scoreArray) {
		if (position > counter)++counter;
		else if (a > 0) return false;
	}
	return true;
};
template<class T, Colour C>
QwixxRow<T, C> QwixxRow<T, C>::operator +=(RollOfDice rd) {
	int position,counter=0;
	if(!validate(rd,position)){
		throw "That entry is invalid";
		}
	cout<<"DEBUG:POSITION= "<<position<<endl;
	for (auto &a:scoreArray){
		if(position==counter){
			a=rd;
			break;
		}
		++counter;
	}
	return *this;
};

#endif /* QWIXXROW_H */

