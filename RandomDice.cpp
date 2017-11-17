
/* 
 * File:   RandomDice.cpp
 * Author: Tony
 * 
 * Created on 2017年11月17日, 下午2:55
 */

#include "RandomDice.h"

RandomDice::RandomDice() {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1,6);
        dice=distribution(generator);
    
}
