
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
#include <string>
using namespace std;

class ScoreSheet {

	friend ostream& operator<<(ostream& out, const ScoreSheet& sheet);
public:
   // Player getPlayer();
	//ScoreSheet();
	string getName() const;
	void setName(string n);
    bool score(RollOfDice rod, Colour color, int position);
   // int setTotal();
   // virtual ~ScoreSheet();
private:
    string name;
    int failed;
	int overallScore;
//protected:
//    virtual bool validate() = 0;
//    virtual int calcTotal() = 0;
};

#endif /* SCORESHEET_H */

