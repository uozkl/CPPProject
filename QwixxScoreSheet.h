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
	int calcTotal()override;
	bool const operator!()override;
	int lock[4];
	QwixxRow<vector<int>, Colour::RED> red;
	QwixxRow<vector<int>, Colour::YELLOW> yellow;
	QwixxRow<list<int>, Colour::GREEN> green;
	QwixxRow<list<int>, Colour::BLUE> blue;
	int np=-1;
	bool QwixxScoreSheet::validate(RollOfDice rod, Colour color, int position=-1)override {
		switch(color){
			case Colour::RED:return red.validate(rod,np);
			case Colour::YELLOW:return yellow.validate(rod,np);
			case Colour::GREEN:return green.validate(rod,np);
			case Colour::BLUE:return blue.validate(rod,np);
			default:return false;
		}
	}
	QwixxScoreSheet& operator+=(RollOfDice& rod){
		Colour c;
		for(Dice &a:rod){
			if(a.getColour()!=Colour::WHITE){
				c=a.getColour();
			}
		}
		switch(c){
			case Colour::RED:red+=rod;
			case Colour::YELLOW:yellow+=rod;
			case Colour::GREEN:green+=rod;
			case Colour::BLUE:blue+=rod;
		}
		return *this;
	}

	
	
	
	};

#endif /* QWIXXSCORESHEET_H */

