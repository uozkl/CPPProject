/* 
 * File:   QwintoScoreSheet.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "QwintoScoreSheet.h"
#include "ScoreSheet.h"
#include "QwintoRow.h"
#include <iostream>
using namespace std;

QwintoScoreSheet::QwintoScoreSheet(string pname) {
	name = pname;
}
//
//QwintoScoreSheet::QwintoScoreSheet(const QwintoScoreSheet& orig) {
//}
//
//QwintoScoreSheet::~QwintoScoreSheet() {
//}

ostream& operator<<(ostream& os, const QwintoScoreSheet& qtsheet) {

	os << "Player name: " << qtsheet.name <<"\t Points: "<<qtsheet.overallScore<< endl
			<< "---------------------------------------------" << endl;
	os << qtsheet.red << endl << "---------------------------------------------"
			<< endl;
	os << qtsheet.yellow << endl
			<< "---------------------------------------------" << endl;
	os << qtsheet.blue << endl
			<< "---------------------------------------------" << endl;
	os << "Failed throws: " <<qtsheet.failed<< endl;
	return os;
}

bool QwintoScoreSheet::validate(RollOfDice rod, Colour color, int position) {
	bool cCheck=false;
		for (auto a:rod){
			if(a.colour==color){
				cCheck=true;
			}
			if (!cCheck){
				cout<<"Row selected does not match the colour of dices rolled."<<endl;
				return false;
			}
		}
	switch (color) {
	case Colour::RED:
		if (!red.validate(rod, position)) {
			cout << "Invalid index!" << endl;
			return false;
		}

		if (yellow[position - 1] == rod || blue[position - 2] == rod) {
			cout << "Invalid index!" << endl;
			return false;
		}

		break;
	case Colour::YELLOW:
		if (!yellow.validate(rod, position)) {
			cout << "Invalid index!" << endl;
			return false;
		}
		if (red[position + 1] == rod || blue[position - 1] == rod) {
			cout << "Invalid index!" << endl;
			return false;
		}
		break;
	case Colour::BLUE:
		if (!blue.validate(rod, position)) {
			cout << "Invalid index!" << endl;
			return false;
		}
		if (red[position + 2] == rod || yellow[position + 1] == rod) {
			cout << "Invalid index!" << endl;
			return false;
		}
		break;
	}
	return true;
}

int QwintoScoreSheet::calcTotal() {

}
