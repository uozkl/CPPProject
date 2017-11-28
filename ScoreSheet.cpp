
/* 
 * File:   ScoreSheet.cpp
 * Author: Tony, Nathan
 * 
 * Created on
 */

#include "ScoreSheet.h"
#include <iostream>
#include<stdio.h>
using namespace std;

ostream& operator<<(ostream& out, const ScoreSheet& sheet){
	return out;
}
ScoreSheet::ScoreSheet(){

}
ScoreSheet::ScoreSheet(string pname){
	name=pname;
}

bool ScoreSheet:: score(RollOfDice rod, Colour color, int position){
	return validate(rod, color, position);
}

int ScoreSheet:: setTotal(){
	return calcTotal();
}
