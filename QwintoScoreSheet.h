
/* 
 * File:   QwintoScoreSheet.h
 * Author: Tony
 *
 * Created on
 */

#ifndef QWINTOSCORESHEET_H
#define QWINTOSCORESHEET_H
#include "QwintoRow.h"
#include "ScoreSheet.h"
#include "Colour.h"
#include<iostream>
using namespace std;

class QwintoScoreSheet : public ScoreSheet{

	friend ostream& operator<<(ostream& os, const QwintoScoreSheet& sheet);
public:
   QwintoScoreSheet(string pname);

	QwintoRow<Colour::RED> red;
	QwintoRow<Colour::YELLOW> yellow;
	QwintoRow<Colour::BLUE> blue;
};

#endif /* QWINTOSCORESHEET_H */

