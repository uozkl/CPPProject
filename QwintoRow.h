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
public:
//	QwintoRow(){
//		scoreArray[10] ={" "," "," "," "," "," "," "," "," "," ",};
//	}
//	QwintoRow(const QwintoRow& orig);
//	virtual ~QwintoRow();

	friend ostream& operator<<(ostream& os, QwintoRow<C> row);
	//ostream& operator[](ostream& os, const QwintoRow<Colour::RED>& row);

private:
	int scoreArray[10]={ };
};

#endif /* QWINTOROW_H */

