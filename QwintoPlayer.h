
/* 
 * File:   QwintoPlayer.h
 * Author: Tony
 *
 * Created on 2017å¹´11æœˆ17æ—¥, ä¸‹å�ˆ2:57
 */

#ifndef QWINTOPLAYER_H
#define QWINTOPLAYER_H
#include "RollOfDice.h"
#include "QwintoScoreSheet.h"

class QwintoPlayer {
public:
    QwintoPlayer();
    QwintoPlayer(const QwintoPlayer& orig);
    virtual ~QwintoPlayer();
    void inputBeforeRoll(RollOfDice &rod);
    void inputAfterRoll(RollOfDice &rod);
private:
    QwintoScoreSheet qtss;
};

#endif /* QWINTOPLAYER_H */

