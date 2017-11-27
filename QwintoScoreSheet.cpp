
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

ostream& operator<<(ostream& os, const QwintoScoreSheet& sheet){

os<<"Player name: "<<sheet.name<<endl<<"---------------------------------------------"<<endl;
os<<sheet.red<<endl<<"---------------------------------------------"<<endl;
os<<sheet.yellow<<endl<<"---------------------------------------------"<<endl;
os<<sheet.blue<<endl<<"---------------------------------------------"<<endl;
os<<"Failed throws:"<<endl;
	 return os;
}
