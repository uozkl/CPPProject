
/* 
 * File:   ScoreSheet.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "ScoreSheet.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, const ScoreSheet& sheet){
	out<<sheet;
	return out;
}
