#include <iostream>
#include <cmath>
#include "Deck2.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char player_action ,player_action0;
bool check(vector<int> card){
	int temp=card[0]/4;
	for(int i=0;i<card.size();i++){
		if(temp==card[i]/4);
		else return true;
	}
	return false;
}
vector<int> ChooseCard(Player P,int turnc ){
	bool chk;
	vector<int> getcard;
	vector<int> cardChoose=P.GetCard();
	vector<int> order;
	vector<string> cFace=P.GetFace();
	int choose1,choose2,choose3,choose4;
	
//	system("cls");
	for(int i=0;i<cardChoose.size();i++){
		order.push_back(i);
	}
	for(int i=0;i<cFace.size();i++){
		cout << order[i] <<"  ";
	}
	cout << "\n";
	for(int i=0;i<cFace.size();i++){
		cout << cFace[i]<< "  ";
	}
	cout << "\n";
		
	step1 :
		if(turnc==1){
			cout<<"choose amount card [1] [2] [3] [4] : ";
			cin>>player_action;
			if(player_action=='1'or player_action=='2'or player_action=='3'or player_action=='4')
			goto step2;
			else goto step1;
		}
		else if(player_action0=='1'){do{
				cout<<"choose amount card [1] [3] or pass [p] : ";
				cin>>player_action;
			}while(player_action!='1'and player_action!='3'and player_action!='p');
			goto step2;
			
		}
		else if(player_action0=='2'){
			do{
				cout<<"choose amount card [2] [4] or pass [p] : ";
				cin>>player_action;
			}while(player_action!='2'and player_action!='4'and player_action!='p');
			goto step2;
			
		}
		else if(player_action0=='3'){
			do{
				cout<<"choose amount card [3] or pass [p] : ";
				cin>>player_action;
			}while(player_action!='3'and player_action!='p');
			 goto step2;
		}
		else if(player_action0=='4'){
			do{
				cout<<"choose amount card [4] or pass [p] :";
				cin>>player_action;
			}while(player_action!='4'and player_action!='p');
			goto step2;
		}
		
	step2 :
		switch(player_action){
			case '1': 	cout << "Choose card from up here:";
					cin>>choose1;//
					getcard.push_back(cardChoose[choose1]);
					break;
			case '2':	cout << "Choose card from up here:";
					cin>>choose1>>choose2;//
					getcard.push_back(cardChoose[choose1]);
					getcard.push_back(cardChoose[choose2]);
					break;
			case '3':	cout << "Choose card from up here:";
					cin>>choose1>>choose2>>choose3;//
					getcard.push_back(cardChoose[choose1]);
					getcard.push_back(cardChoose[choose2]);
					getcard.push_back(cardChoose[choose3]);
					break;
			case '4':	cout << "Choose card from up here:";
					cin>>choose1>>choose2>>choose3>>choose4;//
					getcard.push_back(cardChoose[choose1]);
					getcard.push_back(cardChoose[choose2]);
					getcard.push_back(cardChoose[choose3]);
					getcard.push_back(cardChoose[choose4]);
					break;
//			case 'p':
//			case 'P':return NULL;
//					break;
	}
	chk=check(getcard);
	if(chk){
		getcard.clear();
		cout << "\n-------- Your card not match, Please choose again--------\n";
		goto step1;
	}else {
	player_action0=player_action;
	return getcard;
	}
}
int moreCard(vector<int> hand,int max){
	if(hand.size()==2)max+=100;
	else if(hand.size()==3)max+=200;
	else if(hand.size()==4)max+=300;
	return max;
}
int main(){
	srand(unsigned(time(NULL)));
	int num;
	int maxCard;
	int maxTable;
	vector<int> hand;
	start :
	cout << "2 : 2 Player\n3 : 3 Player\n4 : 4 Player\n";
	cout << "Select : ";
	cin >> num;
	
	if(num>4) {
		cout << "Please select again\n";
		goto start;
	}
	
	string name[num];
	cin.ignore();
	for(int i=0;i<num;i++){
		cout << "Please input Player "<< i+1 << " name: ";
		getline(cin,name[i]);	
	}
	
	Deck c1;
	c1.ShuffleCard();
	c1.ShuffleFace();

	if(num==2){
		vector<string> tmpface=c1.cardFace;
		vector<string> Table;
		int state=0;
		int turnc=1;
		vector<int> gettmp;
		Player p1(name[0],c1.cardFace,c1.cards,c1.faceShuff,0,26);   // get cards from deck
		Player p2(name[1],c1.cardFace,c1.cards,c1.faceShuff,26,52);
		p1.sortcard(); p1.sortface(); p2.sortcard(); p2.sortface();  // sorting card that get from deck
		while(true){
		if(turnc==1){
			gettmp=p1.GetCard();
		
			if(find(gettmp.begin(),gettmp.end(),0) != gettmp.end()){ // Check if who play first
					state=1;
					cout << "\n--------Player1 play first--------\n";
			}else{
					state=2;
					cout << "\n--------Player2 play first--------\n";	
				}
		
			if(state==1){
				player1:      //Player 1 first play
			
				hand.clear();
				hand=ChooseCard(p1,turnc);	
//				if(hand==NULL){
//				
//				}						// function choose card
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
					cout << "\n--------Choose your card again--------\n";
					goto player1;
				}else{
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p1.eraseCard(hand[i]);			// Erase cards that already used
						p1.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
				}
				state=2;
				
			}else if(state==2){
				player2:      //Player 2 first play
			
				hand.clear();
				hand=ChooseCard(p2,turnc);							// function choose card
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
					cout << "\n--------Choose your card again--------\n";
					goto player2;
				}else{
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p2.eraseCard(hand[i]);			// Erase cards that already used
						p2.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
				}
				state=1;
			}
			turnc++;		
		}else{
			if(state==1){
				
				getAg1:
					cout << "\n-------- Table card ";
					for(int i=0;i<Table.size();i++){
						cout << Table[i] << " ";
					}
					cout << "--------\n";
				cout << "\n--------Player1 turn--------\n";	
				hand.clear();
				hand=ChooseCard(p1,turnc);						// function choose card
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
					if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
						cout << "\n--------Choose your card again--------\n";
						goto getAg1;
					}else{
						Table.clear();
						for(int i=0;i<hand.size();i++){
							Table.push_back(tmpface[hand[i]]);
							p1.eraseCard(hand[i]);			// Erase cards that already used
							p1.decCardCount();
						}
						maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					}
					p1.isWin();
					state=2;
				}else if(state==2){
						
				getAg2:
					cout << "\n-------- Table card ";
					for(int i=0;i<Table.size();i++){
						cout << Table[i] << " ";
					}
					cout << "--------\n";
				cout << "\n--------Player2 turn--------\n";	
				hand.clear();
				hand=ChooseCard(p2,turnc);							// function choose card
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
					if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
						cout << "\n--------Choose your card again--------\n";
						goto getAg2;
					}else{
						Table.clear();
						for(int i=0;i<hand.size();i++){
							Table.push_back(tmpface[hand[i]]);
							p2.eraseCard(hand[i]);			// Erase cards that already used
							p2.decCardCount();
						}
						maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					}
					p2.isWin();
					state=1;
				}
			}
		}
				
	}else if(num==3){ 
		Player p1(name[0],c1.cardFace,c1.cards,c1.faceShuff,0,17);
		Player p2(name[1],c1.cardFace,c1.cards,c1.faceShuff,17,34);
		Player p3(name[2],c1.cardFace,c1.cards,c1.faceShuff,34,52); //  1 more card than other
			p1.sortcard();
			p1.sortface();
			p2.sortcard();
			p2.sortface();
			p3.sortcard();
			p3.sortface();
	}else if(num==4){
		Player p1(name[0],c1.cardFace,c1.cards,c1.faceShuff,0,13);
		Player p2(name[1],c1.cardFace,c1.cards,c1.faceShuff,13,26);
		Player p3(name[2],c1.cardFace,c1.cards,c1.faceShuff,26,39);
		Player p4(name[3],c1.cardFace,c1.cards,c1.faceShuff,39,52);
			p1.sortcard();
			p1.sortface();
			p2.sortcard();
			p2.sortface();
			p3.sortcard();
			p3.sortface();
			p4.sortcard();
			p4.sortface();
	}

	return 0;
}