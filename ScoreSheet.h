
/* 
 * File:   ScoreSheet.h
 * Author: Tony
 *
 * Created on 2017骞�11鏈�17鏃�, 涓嬪崍2:56
 */

#ifndef SCORESHEET_H
#define SCORESHEET_H
#include "Player.h"
#include "Colour.h"
#include <string>

class ScoreSheet {

public:
   // Player getPlayer();
    void setPlayer();
    int getScore();
    int getFailed();
    bool score(RollOfDice rod, Colour color);
    int setTotal();
    virtual ~ScoreSheet();
private:
    std::string name;
    int failed,score;
protected:
    virtual bool validate() = 0;
    virtual int calcTotal() = 0;
};

#endif /* SCORESHEET_H */

