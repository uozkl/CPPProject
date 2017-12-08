// #ifdef TEST
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
    char a;
    while (test)
    {
        string playerName = "test";
        RollOfDice rd;
        RollOfDice rodR, rodG;
        Colour red = Colour::RED;
        Colour green = Colour::GREEN;
        Dice *reddice = new Dice(red);
        Dice *greendice = new Dice(green);
        QwixxRow<vector<int>, Colour::RED> redRow;
        QwixxRow<list<int>, Colour::GREEN> greenRow;
        test = false;

        cout << "You can test folling classes:" << endl
             << "1.QwintoPlayer" << endl
             << "2.QwintoRow" << endl
             << "3.QwintoScoreSheet" << endl
             << "4.QwintoPlayer" << endl
             << "5.QwixxPlayer" << endl
             << "6.QwixxRow" << endl
             << "7.QwixxScoreSheet" << endl
             << "8.RollOfDice" << endl
             << "Input index to start test:" << endl;
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
            cout << "Testing QwixxPlayer.cpp" << endl;
            cout << "Build a player named test and set him active" << endl;
            QwintoScoreSheet *qtss = new QwintoScoreSheet(playerName);
            QwintoPlayer *player = new QwintoPlayer(*qtss);
            (*player).active = true;
            cout << "Build roll of dice, add dice and roll" << endl;
            (*player).inputBeforeRoll(rd);
            rd.roll();
            cout << "Show score sheet, let player make choice" << endl;
            (*player).inputBeforeRoll(rd);
            cout << endl
                 << "End of test" << endl
                 << endl;
            break;
        case 6:
            cout << "Testing QwixxRow.cpp" << endl;
            cout << "Build a vector row red and list row green" << endl;
            rodR.add(*reddice);
            rodG.add(*greendice);
            rodR.roll();
            rodG.roll();
            cout << "Print two rows" << endl;
            cout << "Red: " << redRow << endl;
            cout << "Green: " << greenRow << endl;
            cout << "Add roll of dice";

            break;
        case 7:
            break;
        case 8:
            break;
        }
        cout << "Keep testing? y/n" << endl;
        cin >> a;
        if (a == 'y')
            test = true;
    }
    return 0;
}
// #endif