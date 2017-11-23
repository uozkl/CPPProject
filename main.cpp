/*
 * main.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: natha
 */
#include<iostream>
#include"QwintoScoreSheet.h"
#include "QwixxScoreSheet.h"
using namespace std;

int main(){
	cout<<"Please choose game version (1-Qwinto, 2-Qwixx):"<<endl;
	int version;
	cin>>version;
	if (version == 1){
		QwintoScoreSheet *qtss;
		cout<<"Qwinto selected."<<endl;
		cout<<*qtss;
}else if(version == 2){
	QwixxScoreSheet *qxss;
			cout<<"Qwixx selected."<<endl;
			cout<<*qxss;
}else{
	//wrong input
}
return 0;
}

