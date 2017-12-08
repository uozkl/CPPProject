#include "QwintoPlayer.h"
#include "QwintoRow.h"
#include "QwintoScoreSheet.h"
#include "QwintoPlayer.h"
#include "QwixxPlayer.h"
#include "QwixxRow.h"
#include "QwixxScoreSheet.h"
#include "RollOfDice.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main()
{
    cout << "This is the test class for all the classes" << endl;
    int index;
    bool test = true;
    while (test)
    {
        cout << "You can test folling classes:" << endl;
        cout << "1.QwintoPlayer" << endl
             << "2.QwintoRow" << endl
             << "3.QwintoScoreSheet" << endl
             << "4.QwintoPlayer" << endl
             << "5.QwixxPlayer" << endl
             << "6.QwixxRow" << endl
             << "7.QwixxScoreSheet" << endl
             << "8.RollOfDice" << endl;
        cout << "Input index to start test:" << endl;
        cin >> index;
        switch (index)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        }
    }
    return 0;
}