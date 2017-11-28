
/* 
 * File:   QwixxScoreSheet.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "QwixxScoreSheet.h"
#include <iostream>
using namespace std;

QwixxScoreSheet :: QwixxScoreSheet(string pname){
	name = pname;
}

//QwixxScoreSheet::QwixxScoreSheet(const QwixxScoreSheet& orig) {
//}

//QwixxScoreSheet::~QwixxScoreSheet() {
//}


ostream& operator<<(ostream& os, const QwixxScoreSheet& sheet){

	os<<"Player name: "<<sheet.name<<endl<<"------------------------------"<<endl;
	os<<sheet.red<<"------------------------------"<<endl<<"------------------------------"<<endl<<"------------------------------"<<endl;
	os<<"Failed throws:"<<endl;
		 return os;
}
bool QwixxScoreSheet:: validate(RollOfDice rod, Colour color, int position){

}
int QwixxScoreSheet:: calcTotal(){

}
