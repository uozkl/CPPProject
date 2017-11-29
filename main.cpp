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
#include"QwixxPlayer.h"
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
			cout << "Please enter the name for player " << i << ": " << endl;
			string playerName;
			cin >> playerName;
			QwintoScoreSheet *qtss = new QwintoScoreSheet(playerName);
			QwintoPlayer *player = new QwintoPlayer(*qtss);
			playerVec.push_back(*player);

			cout << player->qtss;
		}
	} else if (version == 2) {
		cout << "Qwixx slected." << endl;
		vector<QwixxPlayer> playerVec;
		for (int i = 1; i <= count; ++i) {
			cout << "Please enter the name for player " << i << ": " << endl;
			string playerName;
			cin >> playerName;
			QwixxScoreSheet *qxss = new QwixxScoreSheet(playerName);
			QwixxPlayer *player = new QwixxPlayer(*qxss);
			playerVec.push_back(*player);
			cout << player->qxss;
		}
	} else {
		//wrong input
	}
	return 0;
}

