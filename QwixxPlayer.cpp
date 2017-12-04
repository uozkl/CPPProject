/* 
 * File:   QwixxPlayer.cpp
 * Author: Tony
 * 
 * Created on 2017骞�11鏈�17鏃�, 涓嬪崍2:57
 */

#include "QwixxPlayer.h"
#include<iostream>
using namespace std;

QwixxPlayer::QwixxPlayer(QwixxScoreSheet qs) {
	qxss = qs;
}

void QwixxPlayer::inputBeforeRoll(RollOfDice &rod) {
	if (active == true) {
		cout << "Please select number of dice to roll :" << endl;
	}
}

void QwixxPlayer::inputAfterRoll(RollOfDice &rod) {

}

