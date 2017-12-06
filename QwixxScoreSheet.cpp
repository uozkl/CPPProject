/* 
 * File:   QwixxScoreSheet.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "QwixxScoreSheet.h"
#include "ScoreSheet.h"
#include "QwixxRow.h"
#include <iostream>
using namespace std;

QwixxScoreSheet::QwixxScoreSheet(string pname) {
	name = pname;
}

ostream& operator<<(ostream& os, const QwixxScoreSheet &qxsheet) {

	os << "Player name: " << qxsheet.name << "\t Points: "
			<< qxsheet.overallScore << endl
			<< "----------------------------------------" << endl;
	os << qxsheet.red << endl << "----------------------------------------"
			<< endl;
	os << qxsheet.yellow << endl << "----------------------------------------"
			<< endl;
	os << qxsheet.green << endl << "----------------------------------------"
			<< endl;
	os << qxsheet.blue << endl << "----------------------------------------"
			<< endl;
	os << "Failed throws:" << qxsheet.failed << endl;
	return os;
}
bool QwixxScoreSheet::validate(RollOfDice rod, Colour color, int position) {
	switch (color) {
	case Colour::RED:
		return red.validate(rod, position);
		break;
	case Colour::YELLOW:
		return yellow.validate(rod, position);
		break;
	case Colour::BLUE:
		return blue.validate(rod, position);
		break;
	}
}
int QwixxScoreSheet::calcTotal() {

}

bool const QwixxScoreSheet::operator!() {

}
