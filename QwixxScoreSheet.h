
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
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class QwixxScoreSheet : public ScoreSheet {

	friend ostream& operator<<(ostream& os, const QwixxScoreSheet& sheet);
public:
    QwixxScoreSheet(string pname);

private:
    QwixxRow<vector<int>,Colour::RED> red;
    QwixxRow<vector<int>,Colour::YELLOW> yellow;
    QwixxRow<list<int>,Colour::GREEN> green;
    QwixxRow<list<int>,Colour::BLUE> blue;
};

#endif /* QWIXXSCORESHEET_H */

