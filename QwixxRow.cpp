/* 
 * File:   QwixxRow.cpp
 * Author: Tony
 * 
 * Created on 2017
 */

#include "QwixxRow.h"
#include "Colour.h"
#include <iostream>
#include <vector>
using namespace std;

template<>
QwixxRow<vector<int>, Colour::RED>::QwixxRow() {
	scoreArray = vector <int>(12,0);
}
//
//QwixxRow::QwixxRow(const QwixxRow& orig) {
//}
//
//QwixxRow::~QwixxRow() {
//}
//
template<class S, Colour C>
 ostream& operator<<(ostream& os, QwixxRow<vector<int>, Colour::RED> row) {
	os << "Red      ";
	int i=2;
	for (int a : row.scoreArray) {
		os << "|";
		if (a!=0){
			os<<"XX";
		}else if (i != 0 && i < 10) {
			os << " " << i;
		} else if (i >= 10) {
			os << i;
	++i;
		}
	}

	return os;
}
