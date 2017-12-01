
/* 
 * File:   QwintoPlayer.h
 * Author: Tony
 *
 * Created on
 */

#ifndef QWINTOPLAYER_H
#define QWINTOPLAYER_H
#include "RollOfDice.h"
#include "QwintoScoreSheet.h"

class QwintoPlayer : public Player {
public:
QwintoPlayer(QwintoScoreSheet qs);
    void inputBeforeRoll(RollOfDice &rod);
    void inputAfterRoll(RollOfDice &rod);
   // Dice setDice(string str);
    QwintoScoreSheet qtss;
};

#endif /* QWINTOPLAYER_H */

