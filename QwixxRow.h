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
	bool validate(bool type, int pos);
	T scoreArray;

};
template<class T, Colour C>
bool QwixxRow<T,C>:: validate(bool type, int pos){
	if(type){
		score;
		for(int i=0;i<pos;i++){
			score=scoreArray.next();
		}
		if(score==pos)return false;
		for(int j=pos;j<scoreArray.length;j++){
			if 存在插入过的值 return false;
		}
	}
	else{
		if score=scoreArray[pos] return false;
		for(int j=pos;j<scoreArray.length;j++){
			if 存在插入过的值 return false;
		}
	}

	return true;
};

#endif /* QWIXXROW_H */

