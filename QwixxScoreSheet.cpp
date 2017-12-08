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
#include <string>
using namespace std;

QwixxScoreSheet::QwixxScoreSheet(string pname) {
	name = pname;
}

ostream& operator<<(ostream& os, const QwixxScoreSheet &qxsheet) {
	string lck[]={"U","B","L"};

	os << "Player name: " << qxsheet.name << "\t Points: "
			<< qxsheet.overallScore << endl
			<< "-------------------------------------------" << endl;
	os << qxsheet.red <<lck[qxsheet.lock[0]]<< endl << "-------------------------------------------"
			<< endl;
	os << qxsheet.yellow <<lck[qxsheet.lock[1]]<< endl << "-------------------------------------------"
			<< endl;
	os << qxsheet.green <<lck[qxsheet.lock[2]]<< endl << "-------------------------------------------"
			<< endl;
	os << qxsheet.blue <<lck[qxsheet.lock[3]]<< endl << "-------------------------------------------"
			<< endl;
	os << "Failed throws:" << qxsheet.failed << endl;
	return os;
}
int QwixxScoreSheet::calcTotal() {	
	int total = 0;
	int counter = 0;
	int points[12] = { 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78 };
	for (auto a : red.scoreArray) {
		if (a > 0) {
			++counter;
		}
	}
	if (counter > 0) {
		total += points[counter - 1];
	}
	counter = 0;
	for (auto a : yellow.scoreArray) {
		if (a > 0) {
			++counter;
		}
	}
	if (counter > 0) {
		total += points[counter - 1];
	}
	counter = 0;
	for (auto a : green.scoreArray) {
		if (a > 0) {
			++counter;
		}
	}
	if (counter > 0) {
		total += points[counter - 1];
	}
	counter = 0;
	for (auto a : blue.scoreArray) {
		if (a > 0) {
			++counter;
		}
	}
	if (counter > 0) {
		total += points[counter - 1];
	}
	counter = 0;
	total -= failed * 5;
	return total;

}

bool const QwixxScoreSheet::operator!() {
	if (failed == 4) {
			return true;
		}
	int counter=0;
	for(auto a: lock){
		if(a==2){
			counter++;
		}
		if(counter==2){
			return true;
		}
	}
	return false;

}
