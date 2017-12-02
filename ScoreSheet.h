
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
   // Player getPlayer();
	ScoreSheet();
	ScoreSheet(string pname);
	string getName() const;
	void setName(string n);
    bool score(RollOfDice rod, Colour color, int position=-1);
    int setTotal();
    string name;
    int failed;
	int overallScore;
   // virtual ~ScoreSheet();
protected:
    virtual bool validate(RollOfDice rod, Colour color, int position) = 0;
    virtual int calcTotal() = 0;


//protected:

//
};

#endif /* SCORESHEET_H */

