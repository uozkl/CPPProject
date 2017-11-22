
/* 
 * File:   QwintoScoreSheet.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "QwintoScoreSheet.h"
#include <iostream>
using namespace std;

QwintoScoreSheet::QwintoScoreSheet() {
}

QwintoScoreSheet::QwintoScoreSheet(const QwintoScoreSheet& orig) {
}

QwintoScoreSheet::~QwintoScoreSheet() {
}

 ostream& operator<<(ostream& out, const QwintoScoreSheet& sheet){

	 out<<"Player name:"<<sheet.name<<endl<<"------------------------------"<<endl;
	 out<<sheet.row1<<endl<<"------------------------------"<<endl;
	 out<<sheet.row2<<endl<<"------------------------------"<<endl;
	 out<<sheet.row3<<endl<<"------------------------------"<<endl;
	 out<<"Failed throws:"<<sheet.failed<<endl;
	 return out;
 }
