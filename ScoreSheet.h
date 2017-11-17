
/* 
 * File:   ScoreSheet.h
 * Author: Tony
 *
 * Created on 2017年11月17日, 下午2:56
 */

#ifndef SCORESHEET_H
#define SCORESHEET_H
#include "Player.h"
class ScoreSheet {
    Player player;
    int failed,score;
public:
    Player getPlayer();
    void setPlayer();
    int getScore();
    int getFailed();
    int setScore();
    int setFailed();
private:

};

#endif /* SCORESHEET_H */

