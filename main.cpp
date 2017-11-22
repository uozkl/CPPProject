/*
 * main.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: natha
 */
#include<iostream>
#include"QwintoScoreSheet.h"
using namespace std;

int main(){
	cout<<"Please choose game version (1-Qwinto, 2-Qwixx):"<<endl;
	int version;
	cin>>version;
	if (version == 1){
		QwintoScoreSheet ss = new ScoreSheet();
		cout<<ss;
	}else if(version == 2){
		//do something
	}else{
		//wrong input
	}
return 0;
}

