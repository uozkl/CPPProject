
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


ostream& operator<<(ostream& out, const QwixxScoreSheet& sheet){

	out<<"Player name: "<<sheet.name<<endl<<"------------------------------"<<endl<<"------------------------------"<<endl<<"------------------------------"<<endl<<"------------------------------"<<endl;
	out<<"Failed throws:"<<endl;
		 return out;
}
