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
		}
		//++o;
		for (auto &a : playerVec) {
			while (!a.qtss) {
				RollOfDice rd;
				a.active = true;
				a.inputBeforeRoll(rd);
				rd.roll();
				cout << rd << endl;
				cout << a.qtss;

				a.inputAfterRoll(rd);
				cout << a.qtss;
				for (auto &b : playerVec) {
					if (b.active == false) {
						cout << b.qtss;
						b.inputAfterRoll(rd);
						cout << b.qtss;
					}
				}
				a.active = false;
			}
			string winner;
			int high;
			for (auto a : playerVec) {
				a.qtss.setTotal();
				if (a.qtss.overallScore > high) {
					high = a.qtss.overallScore;
					winner = a.qtss.name;
				}
				cout << a.qtss;
			}
			cout << "The winner is: " << winner << endl;

		}
	}
	//cout << player->qtss;

	else if (version == 2) {
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
system("PAUSE");
	return 0;
}

