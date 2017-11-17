
/* 
 * File:   Player.h
 * Author: Tony
 *
 * Created on 2017å¹´11æœˆ17æ—¥, ä¸‹å�ˆ2:57
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "RollOfDice.h"

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
    virtual void inputBeforeRoll(RollOfDice &rod) = 0;
    virtual void inputAfterRoll(RollOfDice &rod) = 0;
private:

};

#endif /* PLAYER_H */

