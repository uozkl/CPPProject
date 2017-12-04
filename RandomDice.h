/* 
 * File:   RandomDice.h
 * Author: Tony
 *
 * Created on
 */

#ifndef RANDOMDICE_H
#define RANDOMDICE_H
#include <random>

struct RandomDice {

	// static std::random_device randDev;
	static std::mt19937 generator;
	static std::uniform_int_distribution<unsigned> distribution;
	//RandomDice();
	static int getDice();

};

#endif /* RANDOMDICE_H */

