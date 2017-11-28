
/* 
 * File:   RandomDice.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "RandomDice.h"

RandomDice::RandomDice() {
        std::default_random_engine generator;
        std::uniform_int_distribution<unsigned int> distribution(1,6);
        dice=distribution(generator);
    
}
