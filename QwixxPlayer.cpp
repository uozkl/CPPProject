/* 
 * File:   QwixxPlayer.cpp
 * Author: Tony
 * 
 * Created on 2017骞�11鏈�17鏃�, 涓嬪崍2:57
 */

#include "QwixxPlayer.h"
#include<iostream>
#include<string>
using namespace std;

QwixxPlayer::QwixxPlayer(QwixxScoreSheet qs) {
	qxss = qs;
}

void QwixxPlayer::inputBeforeRoll(RollOfDice &rod) {
	if(active==false){cout<<"Wait for other player get roll....";return;}
	cout<<"Your roll: "<<endl;
	Colour red = Colour::RED;
	Colour yellow = Colour::YELLOW;
	Colour green = Colour::GREEN;
	Colour blue = Colour::BLUE;
	Colour white=Colour::WHITE;
	Dice *w1=new Dice(white);
	Dice *w2=new Dice(white);
	rod.add(*w1);
	rod.add(*w2);
	if(qxss.lock[0]){Dice *r = new Dice(red);rod.add(*r);}
	if(qxss.lock[1]){Dice *y = new Dice(yellow);rod.add(*y);}
	if(qxss.lock[2]){Dice *g= new Dice(green);rod.add(*g);}
	if(qxss.lock[3]){Dice *b = new Dice(blue);rod.add(*b);}
}

void checkInput(char& _in,QwixxScoreSheet &qxss,bool &undo,bool checkUndo=false){
	cout<<"Please input a value: "<<endl;
	string in;
	bool valid=false;
	while(!valid){
		cin>>in;
		if(in.length()==1){
			_in=in[0];
			switch(_in){
				case 'r':if(qxss.lock[0])valid=true;
				case 'y':if(qxss.lock[1])valid=true;
				case 'g':if(qxss.lock[2])valid=true;
				case 'b':if(qxss.lock[3])valid=true;
				case 'm':valid=true;
				default:break;
			}
			if(checkUndo){
				if(_in=='y'){undo=true;valid=true;}
				if(_in=='n'){undo=false;valid=true;}
			}
		}
		if(valid)break;
		cout<<"Invalid input"<<endl;
	}
}

void QwixxPlayer::inputAfterRoll(RollOfDice &rod) {
	string colorlist[]={ "Red","Blue","Yellow","Green","White"};
	if(active){
		cout<<"Please select the dice which represented by colour to fill your sheet: "<<endl;
		cout<<"If you don't want to choose any of the dice, you can use one of your Mis-Throw chance to skip this round"<<endl;
		cout<<"You can choose ";
		if(qxss.lock[0])cout<<"r for Red; ";
		if(qxss.lock[1])cout<<"y for yellow; ";
		if(qxss.lock[2])cout<<"g for green; ";
		if(qxss.lock[3])cout<<"b for blue; ";
		cout<<"and m for skip. "<<endl;
		cout<<"Currently you have "<<4-qxss.failed<<" chances to skip, note ";
		if(qxss.failed==3)cout<<"if you skip this time, gameover.";
		else cout<<"if you used all your chances, gameover";
		char check;
		//get two white face
		int face,w1,w2;
		Dice *d1=nullptr;
		Dice *d2=nullptr;
		for(Dice &e:rod){
			if(e.getColour()==Colour::WHITE){
				if(d1==nullptr)d1=&e;
				else d2=&e;
			}
		}
		RollOfDice p1,p2;
		char finalCommand;
		int finalSet;
		bool undo=true;
		bool pass1,pass2;
		Colour c;
		while(undo){
			undo=false;
			checkInput(check,qxss,undo);
			finalCommand=check;
			switch(check){
				case 'r':c=Colour::RED;
				case 'y':c=Colour::YELLOW;
				case 'g':c=Colour::GREEN;
				case 'b':c=Colour::BLUE;
				case 'm':
					cout<<"You chose to skip this round"<<endl;
					cout<<"Undo changes? y/n";
					checkInput(check,qxss,undo);
					break;
				default: 
					for(Dice d:rod)if(d.getColour()==c){
						p1=p1.pair(*d1,d);
						p2=p2.pair(*d2,d);
					}
					cout<<"You chose "<<colorlist[(int)c]<<" , its face is "<<face<<endl;
					cout<<"Sum of two sets with white dice is "<<p1<<" and "<<p2<<endl;
					pass1=qxss.validate(p1,c);
					pass2=qxss.validate(p2,c);
					if(p1&p2)cout<<"You can add either one of two set to your "<<colorlist[(int)c]<<" row."<<endl;
					else if(p1)cout<<"You can add only one set "<<p1<<" to your "<<colorlist[(int)c]<<" row."<<endl;
					else if(p2)cout<<"You can add only one set "<<p2<<" to your "<<colorlist[(int)c]<<" row."<<endl;
					else {
						cout<<"But you can't add any one of the set to your "<<colorlist[(int)c]<<" row."<<endl<<"Please reselect a colcour"<<endl;
						undo=true;
						continue;
					}
					cout<<"Undo selection? y/n";
					checkInput(check,qxss,undo,true);
			}
		}
		if(!(pass1&pass2)){
			cout<<"Set "<<p2<<" has added to your "<<colorlist[(int)c]<<" row."<<endl;
		}
	}
	else{
		//TODO
	}
	
}

