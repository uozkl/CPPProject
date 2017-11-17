
/* 
 * File:   RandomDice.h
 * Author: Tony
 *
 * Created on 2017年11月17日, 下午2:55
 */

#ifndef RANDOMDICE_H
#define RANDOMDICE_H
#include <random>

class RandomDice {
    int dice;
public:
    RandomDice();
    int getDice();
    
    RandomDice(const RandomDice& orig);
    virtual ~RandomDice();
private:

};

#endif /* RANDOMDICE_H */

