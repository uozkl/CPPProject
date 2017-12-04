/* 
 * File:   Player.h
 * Author: Tony
 *
 * Created on
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
	bool active = false;
};

#endif /* PLAYER_H */

