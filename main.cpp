/*
 * main.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: natha
 */
#include<iostream>
#include"QwintoScoreSheet.h"
#include "QwixxScoreSheet.h"
#include "QwintoPlayer.h"
#include <vector>
using namespace std;

int main() {
	cout << "Please choose game version (1-Qwinto, 2-Qwixx): " << endl;
	int version;
	cin >> version;

	cout << "Please enter the number of players: " << endl;
	int count;
	cin >> count;
	if (version == 1) {
		cout << "Qwinto selected." << endl;
		vector<QwintoPlayer> playerVec;
		for (int i = 1; i <= count; ++i) {
			cout << "Please enter the name for player "<<i<<": " << endl;
			string playerName;
			cin >> playerName;
			QwintoScoreSheet *qtss = new QwintoScoreSheet(playerName);
			QwintoPlayer *player = new QwintoPlayer(*qtss);
			playerVec.push_back(*player);
			//qtss= new QwintoScoreSheet(playerName);

			cout << player->qtss;
		}
	} else if (version == 2) {
		//QwixxScoreSheet *qxss;
		cout << "qwixx not available" << endl;
//		cout << "Qwixx selected." << endl;
//		cout << qxss;

	} else {
		//wrong input
	}
	return 0;
}

