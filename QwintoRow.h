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
#include<iostream>
#include <array>
using namespace std;

template<Colour C> class QwintoRow {

	friend ostream& operator<<(ostream& os, QwintoRow<C> row);
public:

	int& operator[](int i){
		return scoreArray[i];
	}

private:
	int scoreArray[10]={ };
};

#endif /* QWINTOROW_H */

