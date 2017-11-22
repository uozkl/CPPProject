
/* 
 * File:   QwixxScoreSheet.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "QwixxScoreSheet.h"
#include <iostream>
using namespace std;

QwixxScoreSheet::QwixxScoreSheet() {
}

QwixxScoreSheet::QwixxScoreSheet(const QwixxScoreSheet& orig) {
}

QwixxScoreSheet::~QwixxScoreSheet() {
}
ostream& operator<<(ostream& out, const QwixxScoreSheet& sheet){

	out<<"Player name:"<<sheet.name<<endl<<"------------------------------"<<endl;
	out<<sheet.row1<<endl<<"------------------------------"<<endl;
	out<<sheet.row2<<endl<<"------------------------------"<<endl;
	out<<sheet.row3<<endl<<"------------------------------"<<endl;
	out<<"Failed throws:"<<sheet.failed<<endl;

	return out;
}
