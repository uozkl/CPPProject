/* 
 * File:   ScoreSheet.h
 * Author: Tony
 *
 * Created on
 */

#ifndef SCORESHEET_H
#define SCORESHEET_H
#include "Player.h"
#include "Dice.h"
#include "Colour.h"
#include <string>
using namespace std;

class ScoreSheet {

	friend ostream& operator<<(ostream& out, const ScoreSheet& sheet);
public:

	ScoreSheet();
	ScoreSheet(string pname);
	string getName() const;
	void setName(string n);
	bool score(RollOfDice rod, Colour color, int position = -1);
	void setTotal();
	virtual ~ScoreSheet(){};
	int failed = 0;
	int getTotal() {
		return overallScore;
	};
	string getName() {
		return name;
	};
	virtual bool validate(RollOfDice rod, Colour color, int position) = 0;
	virtual int calcTotal() = 0;

	virtual bool const operator!() = 0;
protected:
	string name;

	int overallScore = 0;
};

#endif /* SCORESHEET_H */

