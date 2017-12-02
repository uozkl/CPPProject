/* 
 * File:   QwintoPlayer.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "QwintoPlayer.h"
#include "RollOfDice.h"
#include "Colour.h"
#include "Dice.h"
using namespace std;

QwintoPlayer::QwintoPlayer(QwintoScoreSheet qs) {
	qtss = qs;
}

void QwintoPlayer::inputBeforeRoll(RollOfDice &rod) {

	cout << "Please enter the number of dice(s) to roll for player "
			<< this->qtss.name << ": " << endl;
	int num;
	cin >> num;
	if (num > 0 && num <= 3) {
		for (int i = 0; i < num; ++i) {
			cout << "Please select the color of dice " << i + 1 << ": " << endl;
			Colour c;
			string ibcolour;
			cin >> ibcolour;
			if (ibcolour == "red") {
				c = Colour::RED;
			} else if (ibcolour == "blue") {
				c = Colour::BLUE;
			} else {
				c = Colour::YELLOW;
			}
			Dice *d = new Dice(c);
			rod.add(*d);
		}

	} else {
		cout << "invalid number of dice" << endl;
	}
}
void QwintoPlayer::inputAfterRoll(RollOfDice &rod) {
	bool done = false;
	while (!done) {
		cout << "Please select which color of row to score for player "
				<< this->qtss.name << ": " << endl;
		string iacolour;
		cin >> iacolour;

		cout << "Please select the index to score: " << endl;
		int iscore;
		cin >> iscore;

		if (iacolour == "red") {
			if (!qtss.score(rod, Colour::RED, iscore)) {
				cout << "Try again?(y/n)" << endl;
				string selection;
				cin >> selection;
				if (selection == "n") {
					done = true;
					this->qtss.failed++;
				}
			}else{
					done=true;
				}


		} else if (iacolour == "blue") {
			if (!qtss.score(rod, Colour::BLUE, iscore)) {
				cout << "Try again?(y/n)" << endl;
				string selection;
				cin >> selection;
				if (selection == "n") {
					done = true;
					this->qtss.failed++;
				}
			}else{
					done=true;
				}

		} else {
			if (!qtss.score(rod, Colour::YELLOW, iscore)) {
				cout << "Try again?(y/n)" << endl;
				string selection;
				cin >> selection;
				if (selection == "n") {
					done = true;
					this->qtss.failed++;
				}
			}else{
					done=true;
				}
			}

		}
	}


