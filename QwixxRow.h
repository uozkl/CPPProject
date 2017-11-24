
/* 
 * File:   QwixxRow.h
 * Author: Tony
 *
 * Created on
 */

#ifndef QWIXXROW_H
#define QWIXXROW_H
#include "RollOfDice.h"

class QwixxRow {
public:
    QwixxRow();
    QwixxRow(const QwixxRow& orig);
    virtual ~QwixxRow();
private:
//QwixxRow<Red> row;
RollOfDice rd;

};

#endif /* QWIXXROW_H */

