/* 
 * File:   QwintoRow.cpp
 * Author: Tony
 * 
 * Created on
 */

#include "QwintoRow.h"
#include"Colour.h"
#include<iostream>

//QwintoRow:: QwintoRow() {
//
//
//}
//
//QwintoRow::QwintoRow(const QwintoRow& orig) {
//}
//
//QwintoRow::~QwintoRow() {
//}

ostream& operator<<(ostream& os, const QwintoRow<Colour::RED>& row) {

	os << "Red         ";
	for (int i = 0; i < 10; ++i) {
		switch (i) {
		case 1:
			os << "%";
			break;
		case 2:
			os << "%";
			break;
		case 3:
			os << "|XX|";
			break;
		case 4:
			os << "%";
			break;
		case 5:
			os << "%";
			break;
		default:
			os << "|";
			break;
		}
		os << " ";
	}
	return os;
}

ostream& operator<<(ostream& os, const QwintoRow<Colour::YELLOW>& row) {
	os << "Yellow    ";
	for (int i = 0; i < 10; ++i) {
		switch (i) {
		case 5:
			os << "|XX|";
			break;
		case 6:
			os << "%";
			break;
		case 7:
			os << "%";
			break;
		default:
			os << "|";
			break;
		}
		os << " ";
	}

	return os;
}


ostream& operator<<(ostream& os, const QwintoRow<Colour::BLUE>& row) {
	os << "Blue    ";
	for (int i = 0; i < 10; ++i) {
		switch (i) {
		case 2:
			os << "%";
			break;
		case 3:
			os << "%";
			break;
		case 4:
			os << "|XX|";
			break;
		case 8:
			os << "%";
			break;
		case 9:
			os << "%";
			break;
		default:
			os << "|";
			break;
		}
		os << " ";
	}

	return os;
}

