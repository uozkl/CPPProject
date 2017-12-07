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
	if(!qxss.lock[0]){Dice *r = new Dice(red);rod.add(*r);}
	if(!qxss.lock[1]){Dice *y = new Dice(yellow);rod.add(*y);}
	if(!qxss.lock[2]){Dice *g= new Dice(green);rod.add(*g);}
	if(!qxss.lock[3]){Dice *b = new Dice(blue);rod.add(*b);}
}

void checkInput(char& _in,QwixxScoreSheet &qxss,bool &undo,int checktype=0){
	cout<<"Please input a value: "<<endl;
	string in;
	bool valid=false;
	while(!valid){
		cin>>in;
		if(in.length()==1){
			_in=in[0];
			if(checktype==0){
				switch(_in){
					case 'r':
						if(!qxss.lock[0])valid=true;
						break;
					case 'y':
						if(!qxss.lock[1])valid=true;
						break;
					case 'g':
						if(!qxss.lock[2])valid=true;
						break;
					case 'b':
						if(!qxss.lock[3])valid=true;
						break;
					case 'm':
						valid=true;
						break;
					default:
						break;
				}
			}
			if(checktype==1){
				if(_in=='y'){undo=true;valid=true;}
				if(_in=='n'){undo=false;valid=true;}
			}
			if(checktype==2){
				if(_in=='a'){valid=true;}
				if(_in=='b'){valid=true;}
			}

		}
		if(valid)break;
		cout<<"Invalid input"<<endl;
	}
}

void QwixxPlayer::inputAfterRoll(RollOfDice &rod) {
	//variables for all players
	string colorlist[]={ "Red","Blue","Yellow","Green","White"};
	Dice *d1=nullptr;
	Dice *d2=nullptr;
	char check;
	int face;
	for(Dice &e:rod){
		if(e.getColour()==Colour::WHITE){
			if(d1==nullptr)d1=&e;
			else d2=&e;
		}
	}
	RollOfDice p1,p2;
	bool undo=true;
	bool pass1=false,pass2=false;
	Colour c;
	if(active){
		cout<<"Please select the dice which represented by colour to fill your sheet: "<<endl;
		cout<<"If you don't want to choose any of the dice, you can use one of your Mis-Throw chance to skip this round"<<endl;
		cout<<"You can choose ";
		if(!qxss.lock[0])cout<<"r for Red; ";
		if(!qxss.lock[1])cout<<"y for yellow; ";
		if(!qxss.lock[2])cout<<"g for green; ";
		if(!qxss.lock[3])cout<<"b for blue; ";
		cout<<"and m for skip. "<<endl;
		cout<<"Currently you have "<<4-qxss.failed<<" chances to skip, note ";
		if(qxss.failed==3)cout<<"if you skip this time, gameover."<<endl;
		else cout<<"if you used all your chances, gameover"<<endl;
		while(undo){
			undo=false;
			checkInput(check,qxss,undo);
			switch(check){
				case 'r':
					c=Colour::RED;
					break;
				case 'y':
					c=Colour::YELLOW;
					break;
				case 'g':
					c=Colour::GREEN;
					break;
				case 'b':
					c=Colour::BLUE;
					break;
				case 'm':
					cout<<"You chose to skip this round"<<endl;
					cout<<"You sure? You will use one of your chances to skip. y/n"<<endl;
					checkInput(check,qxss,undo,1);
					if(check=='n')undo=true;
					else{
						qxss.failed++;
					}
					break;
			}

			if(!undo){ 
				for(Dice d:rod)if(d.getColour()==c){
					p1=p1.pair(*d1,d);
					p2=p2.pair(*d2,d);
					face=d.getFace();
				}
				cout<<"You chose "<<colorlist[(int)c]<<" , its face is "<<face<<endl;
				cout<<"Sum of two sets with white dice is "<<endl<<p1<<p2<<endl;
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
				cout<<"Undo selection? y/n"<<endl;
				checkInput(check,qxss,undo,1);
			}
			
		}
		if(!(pass1&pass2)){
			if(p2){
				qxss.score(p2,c);
				cout<<p2<<"This set has added to your "<<colorlist[(int)c]<<" row."<<endl;
			}
			if(p1){
				qxss.score(p1,c);
				cout<<p1<<"This set has added to your "<<colorlist[(int)c]<<" row."<<endl;	
			}
		}
		else{
			cout<<"Please choose the one you like to add to your sheet: "<<endl;
			cout<<p1<<"is represented by a "<<endl<<p2<<"is represented by b."<<endl;
			checkInput(check,qxss,undo,2);
			cout<<"You chose ";
			if(check=='a'){
				qxss.score(p1,c);
				cout<<p1<<endl;
			}
			//nullllllll
			else{
				qxss.score(p2,c);
				cout<<p2<<endl;
			}
		}
		cout<<"DEBUG: score array at yellow:"<<endl;
		for(auto a:qxss.yellow.scoreArray){
			cout<<a<<" ";
		}
		cout<<endl<<"============================================================="<<endl<<endl;
	}
	else{
		check='f';
		p1=p1.pair(*d1,*d2);
		cout<<"Your action"<<endl;
		cout<<"Do you want to skip this round? y/n"<<endl;
		checkInput(check,qxss,undo,1);
		undo=true;
		cout<<"DEBUG: check="<<check<<endl;
		if(check=='n'){
			cout<<"Please choose the colour where you want to put the public number"<<endl;
			cout<<"You can choose ";
			if(!qxss.lock[0])cout<<"r for Red; ";
			if(!qxss.lock[1])cout<<"y for yellow; ";
			if(!qxss.lock[2])cout<<"g for green; ";
			if(!qxss.lock[3])cout<<"b for blue; ";
			cout<<"and m to skip. "<<endl;
			while(undo){
				undo=false;
				checkInput(check,qxss,undo);
				switch(check){
					case 'r':
						c=Colour::RED;
						break;
					case 'y':
						c=Colour::YELLOW;
						break;
					case 'g':
						c=Colour::GREEN;
						break;
					case 'b':
						c=Colour::BLUE;
						break;
					case 'm':
						cout<<"You chose to skip this round"<<endl;
						cout<<"You sure? y/n"<<endl;
						checkInput(check,qxss,undo,1);
						if(check=='y')break;
						else{
							undo=true;
							break;
						}
						}
				if(!undo){
					if(qxss.validate(p1,c)){
						cout<<"Public number "<<p1<<" will add to your "<<colorlist[(int)c]<<" row"<<endl;
						cout<<"You Sure? y/n"<<endl;
						checkInput(check,qxss,undo,1);
						if(check=='y'){
							Dice *nulldice=new Dice(c);
							p1.add(*nulldice);
							qxss.score(p1,c);
							cout<<"Number added."<<endl;
							break;
						}
					}
					else{
						cout<<"Oops, you can't place the number there"<<endl;
						undo=true;
						continue;
					}
				
				}
			}
			cout<<endl<<"============================================================="<<endl<<endl;
		}
	}

}
