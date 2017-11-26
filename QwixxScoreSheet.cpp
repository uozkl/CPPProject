
/* 
 * File:   QwixxScoreSheet.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "QwixxScoreSheet.h"
#include <iostream>
using namespace std;

//QwixxScoreSheet::QwixxScoreSheet(QwixxRow row1,QwixxRow row2,QwixxRow row3 ) {
//	qxrow1 = row1;
//	qxrow2 = row2;
//	qxrow3 = row3;
//}

//QwixxScoreSheet::QwixxScoreSheet(const QwixxScoreSheet& orig) {
//}

//QwixxScoreSheet::~QwixxScoreSheet() {
//}
ostream& operator<<(ostream& out, const QwixxScoreSheet& sheet){

	out<<"Player name: "<<sheet.name<<endl<<"------------------------------"<<endl<<"------------------------------"<<endl<<"------------------------------"<<endl<<"------------------------------"<<endl;
	out<<"Failed throws:"<<endl;
		 return out;
}
