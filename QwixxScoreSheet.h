/* 
 * File:   QwixxScoreSheet.h
 * Author: Tony
 *
 * Created on
 */

#ifndef QWIXXSCORESHEET_H
#define QWIXXSCORESHEET_H
#include "QwixxRow.h"
#include "ScoreSheet.h"
#include "Colour.h"
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class QwixxScoreSheet: public ScoreSheet {

	friend ostream& operator<<(ostream& os, const QwixxScoreSheet &qxsheet);
public:
	QwixxScoreSheet() = default;
	QwixxScoreSheet(string pname);
	~QwixxScoreSheet()=default;
	bool QwixxScoreSheet::validate(RollOfDice rod, Colour color, int position=-1)override{
		switch(color){
			case Colour::RED:return red.validate(rod);
			case Colour::YELLOW:return yellow.validate(rod);
			case Colour::GREEN:return green.validate(rod);
			case Colour::BLUE:return blue.validate(rod);
			default:return false;
		}
	}
	int calcTotal()override;
	bool const operator!()override;
	int lock[4];
	QwixxRow<vector<int>, Colour::RED> red;
	QwixxRow<vector<int>, Colour::YELLOW> yellow;
	QwixxRow<list<int>, Colour::GREEN> green;
	QwixxRow<list<int>, Colour::BLUE> blue;
};

#endif /* QWIXXSCORESHEET_H */

