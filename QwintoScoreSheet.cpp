
/* 
 * File:   QwintoScoreSheet.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "QwintoScoreSheet.h"
#include "ScoreSheet.h"
#include "QwintoRow.h"
#include <iostream>
using namespace std;




QwintoScoreSheet::QwintoScoreSheet(string pname){
	name=pname;
}
//
//QwintoScoreSheet::QwintoScoreSheet(const QwintoScoreSheet& orig) {
//}
//
//QwintoScoreSheet::~QwintoScoreSheet() {
//}

ostream& operator<<(ostream& os, const QwintoScoreSheet& qtsheet){

os<<"Player name: "<<qtsheet.name<<endl<<"---------------------------------------------"<<endl;
os<<qtsheet.red<<endl<<"---------------------------------------------"<<endl;
os<<qtsheet.yellow<<endl<<"---------------------------------------------"<<endl;
os<<qtsheet.blue<<endl<<"---------------------------------------------"<<endl;
os<<"Failed throws:"<<endl;
	 return os;
}

bool QwintoScoreSheet:: validate(RollOfDice rod, Colour color, int position){

	return true;
}
int QwintoScoreSheet:: calcTotal(){

}
