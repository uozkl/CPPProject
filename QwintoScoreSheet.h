
/* 
 * File:   QwintoScoreSheet.h
 * Author: Tony
 *
 * Created on
 */

#ifndef QWINTOSCORESHEET_H
#define QWINTOSCORESHEET_H
#include "QwintoRow.h"
#include "ScoreSheet.h"
#include<iostream>
using namespace std;

class QwintoScoreSheet : public ScoreSheet{

	friend ostream& operator<<(ostream& out, const QwintoScoreSheet& sheet);
public:
    QwintoScoreSheet();
    QwintoScoreSheet(const QwintoScoreSheet& orig);
    virtual ~QwintoScoreSheet();

private:
    QwintoRow row1;
    QwintoRow row2;
    QwintoRow row3;
};

#endif /* QWINTOSCORESHEET_H */

