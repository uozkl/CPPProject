
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




 ostream& operator<<(ostream& os, const QwixxScoreSheet &qxsheet){

	os<<"Player name: "<<qxsheet.name<<endl<<"----------------------------------------"<<endl;
	os<<qxsheet.red<<endl<<"----------------------------------------"<<endl;
	os<<qxsheet.yellow<<endl<<"----------------------------------------"<<endl;
	os<<qxsheet.green<<endl<<"----------------------------------------"<<endl;
	os<<qxsheet.blue<<endl<<"----------------------------------------"<<endl;
	os<<"Failed throws:"<<endl;
		 return os;
}
bool QwixxScoreSheet:: validate(RollOfDice rod, Colour color, int position){

}
int QwixxScoreSheet:: calcTotal(){

}
