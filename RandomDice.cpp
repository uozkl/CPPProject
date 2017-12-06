/* 
 * File:   RandomDice.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "RandomDice.h"
#include "Dice.h"
#include <ctime>

//I find that the game always give the same random value when it starts, so i used the current unix time as the seed.

std::mt19937 RandomDice::generator(time(0));
std::uniform_int_distribution<unsigned> RandomDice::distribution(1, 6);

int RandomDice::getDice() {
	return distribution(generator);

}

