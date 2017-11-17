
/* 
 * File:   QwixxPlayer.h
 * Author: Tony
 *
 * Created on 2017å¹´11æœˆ17æ—¥, ä¸‹å�ˆ2:57
 */

#ifndef QWIXXPLAYER_H
#define QWIXXPLAYER_H
#include "RollOfDice.h"
#include "QwixxScoreSheet.h"

class QwixxPlayer {
public:
    QwixxPlayer();
    QwixxPlayer(const QwixxPlayer& orig);
    virtual ~QwixxPlayer();
    void inputBeforeRoll(RollOfDice &rod);
    void inputAfterRoll(RollOfDice &rod);
private:
    QwixxScoreSheet qxss;
};

#endif /* QWIXXPLAYER_H */

