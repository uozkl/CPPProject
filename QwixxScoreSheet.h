
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
using namespace std;

class QwixxScoreSheet : public ScoreSheet {

	friend ostream& operator<<(ostream& out, const QwixxScoreSheet& sheet);
public:
    //QwixxScoreSheet(QwixxRow row1, QwixxRow row2,QwixxRow row3);
   // QwixxScoreSheet(const QwixxScoreSheet& orig);
  //  virtual ~QwixxScoreSheet();
private:
//    QwixxRow qxrow1;
//    QwixxRow qxrow2;
//    QwixxRow qxrow3;
};

#endif /* QWIXXSCORESHEET_H */

