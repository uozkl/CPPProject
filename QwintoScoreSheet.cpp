
/* 
 * File:   QwintoScoreSheet.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "QwintoScoreSheet.h"
#include "ScoreSheet.h"
#include <iostream>
using namespace std;

//QwintoScoreSheet::QwintoScoreSheet(){
//}
//
//QwintoScoreSheet::QwintoScoreSheet(const QwintoScoreSheet& orig) {
//}
//
//QwintoScoreSheet::~QwintoScoreSheet() {
//}

ostream& operator<<(ostream& out, const QwintoScoreSheet& sheet){

out<<"Player name: "<<sheet.getName()<<endl<<"------------------------------"<<endl<<"------------------------------"<<endl<<"------------------------------"<<endl<<"------------------------------"<<endl;
out<<"Failed throws:"<<endl;
	 return out;
}
