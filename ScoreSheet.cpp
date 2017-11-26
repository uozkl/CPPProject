
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

string ScoreSheet::getName() const{
	return name;
}
void ScoreSheet:: setName(string n){
	name=n;
}
