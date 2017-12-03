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
	while (cin.fail()) {
		cout << "Please enter a number value" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Please enter the number of dice(s) to roll for player "
				<< this->qtss.name << ": " << endl;
		cin >> num;
	}
	if (num == 3) {
		Colour red =Colour::RED;
		Dice *r = new Dice(red);
		rod.add(*r);
		Colour yellow = Colour::YELLOW;
		Dice *y = new Dice(yellow);
		rod.add(*y);
		Colour blue = Colour::BLUE;
		Dice *b = new Dice(blue);
		rod.add(*b);
	} else if (num > 0 && num <= 2) {
		for (int i = 0; i < num; ++i) {
			cout << "Please select the color of dice " << i + 1 << ":(r/y/b)"
					<< endl;
			Colour c;
			string ibcolour;
			cin >> ibcolour;
			if (ibcolour == "r") {
				c = Colour::RED;
			} else if (ibcolour == "b") {
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
				<< this->qtss.name << ":(r/y/b) " << endl;
		string iacolour;
		cin >> iacolour;

		cout << "Please select the position to score: " << endl;
		int iscore;
		cin >> iscore;
		while (cin.fail()) {
			cout << "Please enter a number value" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please select the position to score: " << endl;
			cin >> iscore;
		}
		if (iacolour == "r") {
			if (!qtss.score(rod, Colour::RED, iscore)) {
				cout << "Try again?(y/n)" << endl;
				string selection;
				cin >> selection;
				if (selection == "n") {
					done = true;
					this->qtss.failed++;
				}
			} else {
				done = true;
			}

		} else if (iacolour == "b") {
			if (!qtss.score(rod, Colour::BLUE, iscore)) {
				cout << "Try again?(y/n)" << endl;
				string selection;
				cin >> selection;
				if (selection == "n") {
					done = true;
					this->qtss.failed++;
				}
			} else {
				done = true;
			}

		} else if (iacolour == "y") {
			if (!qtss.score(rod, Colour::YELLOW, iscore)) {
				cout << "Try again?(y/n)" << endl;
				string selection;
				cin >> selection;
				if (selection == "n") {
					done = true;
					this->qtss.failed++;
				}
			} else {
				done = true;
			}
		} else {
			cout << "Incorrect colour input.(r/y/b) :(" << endl;
		}

	}
}

