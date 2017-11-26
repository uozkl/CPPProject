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
//	QwintoRow();
//	QwintoRow(const QwintoRow& orig);
//	virtual ~QwintoRow();

	friend ostream& operator<<(ostream& os, const QwintoRow<C>& row);

private:
	array<int, 10> qtrow;
};

#endif /* QWINTOROW_H */

