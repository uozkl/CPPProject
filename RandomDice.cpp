/* 
 * File:   RandomDice.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "RandomDice.h"
#include "Dice.h"
#include <ctime>
//std::random_device RandomDice::randDev;
std::mt19937 RandomDice::generator(time(0));
std::uniform_int_distribution<unsigned> RandomDice::distribution(1, 6);

int RandomDice::getDice() {
	return distribution(generator);

}

