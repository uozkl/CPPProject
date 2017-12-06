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
#include <windows.h>

using namespace std;

int main() {

	cout << "Please choose the game version (1-Qwinto, 2-Qwixx): " << endl;
	int version;
	cin >> version;
	cout << "Please enter the number of players: " << endl;
	int count;
	cin >> count;
	if (version == 1) {
		cout << "Qwinto is selected." << endl;
		vector<QwintoPlayer> playerVec;
		//create players
		for (int i = 1; i <= count; ++i) {
			cout << "Please enter the name for player " << i << ": " << endl;
			string playerName;
			cin >> playerName;
			QwintoScoreSheet *qtss = new QwintoScoreSheet(playerName);
			QwintoPlayer *player = new QwintoPlayer(*qtss);
			playerVec.push_back(*player);
		}
		bool gg = false;
		while (gg == false) {
			for (auto &a : playerVec) {	//loop over all the players, ask the active player to roll the dice
				RollOfDice rd;
				a.active = true;
				a.inputBeforeRoll(rd);
				rd.roll();
				cout << rd << endl;
				cout << a.qtss << endl;
				a.inputAfterRoll(rd);
				cout << a.qtss << endl;
				if (!a.qtss) {
					gg = true;
					break;
				}
				for (auto &b : playerVec) {	//loop over all inactive players and get their input
					if (!b.active) {
						cout << b.qtss;
						b.inputAfterRoll(rd);
						cout << b.qtss << endl;
						if (!b.qtss) {
							gg = true;
							break;
						}
					}
				}
				a.active = false;
			}
		}

		//printing score sheet and find who is the winner
		string winner;
		int high = -100;
		cout
				<< "The game has ended, calculating final score and printing score sheets..."
				<< endl;
		for (int i = 0; i <= 50; i++) {     // just for fun
			cout << ">";
			Sleep(100);
		}
		cout << "100%" << endl;
		for (auto a : playerVec) { // loop over all player and calculate their total score, find out the player with the highest score
			a.qtss.setTotal();
			if (a.qtss.getTotal() > high) {
				high = a.qtss.getTotal();
				winner = a.qtss.getName();
			}

			cout << a.qtss;

		}
		cout << "The winner is: " << winner << "!" << endl;

	}

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

