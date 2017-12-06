/* 
 * File:   ScoreSheet.cpp
 * Author: Tony, Nathan
 * 
 * Created on
 */

#include "ScoreSheet.h"
#include <iostream>
#include<stdio.h>
#include "QwintoScoreSheet.h"
#include<typeinfo>
using namespace std;

ostream& operator<<(ostream& out, const ScoreSheet& sheet) {
	return out;
}
ScoreSheet::ScoreSheet() {

}
ScoreSheet::ScoreSheet(string pname) {
	name = pname;
}

// first validate if the score is valid, then score the dice accoring to input
bool ScoreSheet::score(RollOfDice rod, Colour color, int position) {

	if (!validate(rod, color, position)) {

		return false;

	} else {
		//check this type, cast to corresponding and add score to score sheet
		if (typeid(*this) == typeid(QwintoScoreSheet)) {
			QwintoScoreSheet *qts = dynamic_cast<QwintoScoreSheet*>(this);
			switch (color) {
			case Colour::RED:
				qts->red[position] = rod;
				return true;
				break;
			case Colour::BLUE:
				qts->blue[position] = rod;
				return true;
				break;
			case Colour::YELLOW:
				qts->yellow[position] = rod;
				return true;
				break;
			}
		}else{

		}
	}
}


void ScoreSheet::setTotal() {

	overallScore = calcTotal();
}
