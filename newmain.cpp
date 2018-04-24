#include <iostream>
#include <cmath>
#include <sstream>
#include "Deck2.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char player_action ,player_action0,pa_tmp;
int get1tmp;
bool check(vector<int>);
vector<int> ChooseCard(Player,bool);
int moreCard(vector<int> ,int);

int main(){
	mainmenu :
	srand(unsigned(time(NULL)));
	int num;
	int maxCard;
	int maxTable;
	vector<int> hand;
	int round=1;
	int old_kingchk=0;
	
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
	
	playagain :
		
	Deck c1;
	c1.ShuffleCard();
	c1.ShuffleFace();

	if(num==2){
		char paga='\0';
		vector<string> tmpface=c1.cardFace;
		vector<string> Table;
		int state=0;
		int kingchk=0;
		int turnc=1;
		bool T_empty=true;
		vector<int> gettmp;
		Player p1(name[0],c1.cardFace,c1.cards,c1.faceShuff,0,26);   // get cards from deck
		Player p2(name[1],c1.cardFace,c1.cards,c1.faceShuff,26,52);
		p1.sortcard(); p1.sortface(); p2.sortcard(); p2.sortface();  // sorting card that get from deck
		gettmp=p1.GetCard();
		
		while(true){
		if(turnc==1){
			if(round==1){
				if(find(gettmp.begin(),gettmp.end(),0) != gettmp.end()){ // Check if who play first
					state=1;
					cout <<"\n--------" << p1.Getname() <<" play first--------\n";
				}else{
					state=2;
					cout <<"\n--------" << p2.Getname() <<" play first--------\n";	
				}
			}else{
				if(kingchk==1) {
					cout <<"\n--------" << p2.Getname() <<" play first--------\n";
					state=2;
				}
				else if(kingchk==2){
					cout <<"\n--------" << p1.Getname() <<" play first--------\n";
					state=1;
				} 
			}
			
			if(state==1){//Player 1 first play
				    
				while(true){
				hand.clear();
				hand=ChooseCard(p1,T_empty);
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(round==1){
				if(find(hand.begin(),hand.end(),0) != hand.end()){
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p1.eraseCard(hand[i]);			// Erase cards that already used
						p1.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}else cout << "\n--------No 3\5 in your card, choose your card again--------\n";
				}else {
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p1.eraseCard(hand[i]);			// Erase cards that already used
						p1.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}
				}
				
				state=2;
				
			}else if(state==2){
				
				while(true){
				hand.clear();
				hand=ChooseCard(p2,T_empty);							// function choose card
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(round==1){
				if(find(hand.begin(),hand.end(),0) != hand.end()){
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p2.eraseCard(hand[i]);			// Erase cards that already used
						p2.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}else cout << "\n--------No 3\5 in your card, choose your card again--------\n"; 
				}else {
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p2.eraseCard(hand[i]);			// Erase cards that already used
						p2.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}
				}
				
				state=1;	
				
			}
			turnc++;	
				
		}else{
			if(Table.size()>0) T_empty=false;
			else T_empty=true;
			if(state==1){
				
				while(true){
					cout << "\n-------- Table card ";
					for(int i=0;i<Table.size();i++){
						cout << Table[i] << " ";
					}
					cout << "--------\n";
				cout << "\n--------"<< p1.Getname()<<"'s turn--------\n";	
				hand.clear();
				hand=ChooseCard(p1,T_empty);					// function choose card
				if(hand.size()>0){
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
					if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
						cout << "\n--------Choose your card again--------\n";
						
					}else{
						Table.clear();
						for(int i=0;i<hand.size();i++){
							Table.push_back(tmpface[hand[i]]);
							p1.eraseCard(hand[i]);			// Erase cards that already used
							p1.decCardCount();
						}
						maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
						break;
					}	
				}else {
					Table.clear();
					maxTable=0;
					p1.newturn();
					p2.newturn();
					break;
				}
				}
				if(p1.isWin()){
					system("cls");
					kingchk=1;
					round++;
					cout << p1.Getname()<<"is the Winner!! and now \"KING\" \n";
					cout << "Play again ?\n";
					cout << "[Y] play again [N] Exit to main menu [E] Exit :";
					cin >> paga;
					
					if(paga=='Y'||paga=='y') goto playagain;
					else if(paga=='N'||paga=='n') goto mainmenu;
					else if(paga=='E'||paga=='e') break;
				}
				state=2;
				
			}else if(state==2){
						
				while(true){
					cout << "\n-------- Table card ";
					for(int i=0;i<Table.size();i++){
						cout << Table[i] << " ";
					}
					cout << "--------\n";
				cout << "\n--------"<< p2.Getname()<<"'s turn--------\n";	
				hand.clear();
				hand=ChooseCard(p2,T_empty);							// function choose card
				if(hand.size()>0){
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
					if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
						cout << "\n--------Choose your card again--------\n";	
					}else{
						Table.clear();
						for(int i=0;i<hand.size();i++){
							Table.push_back(tmpface[hand[i]]);
							p2.eraseCard(hand[i]);			// Erase cards that already used
							p2.decCardCount();
						}
						maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
						break;
					}
				}else {
					Table.clear();
					maxTable=0;
					p1.newturn();
					p2.newturn();
					break;
				}
				}
				if(p2.isWin()){
					system("cls");
					kingchk=2;
					round++;
					cout << p2.Getname()<<"is the Winner!! and now \"KING\" \n";
					cout << "Play again ?\n";
					cout << "[Y] play again [N] Exit to main menu [E] Exit :";
					cin >> paga;
					
					if(paga=='Y'||paga=='y') goto playagain;
					else if(paga=='N'||paga=='n') goto mainmenu;
					else if(paga=='E'||paga=='e') break;
				}
				state=1;
				}
			}
		}
		
	}else if(num==3){ 
		Player p1(name[0],c1.cardFace,c1.cards,c1.faceShuff,0,17);
		Player p2(name[1],c1.cardFace,c1.cards,c1.faceShuff,17,34);
		Player p3(name[2],c1.cardFace,c1.cards,c1.faceShuff,34,52); //  1 more card than other
		p1.sortcard();p1.sortface();p2.sortcard();p2.sortface();p3.sortcard();p3.sortface();
		
		bool kprintchk=true;
		char paga='\0';
		vector<string> tmpface=c1.cardFace;
		vector<string> Table;
		int state=0;
		int kingchk=0;
		int endchk=0;
		int turnc=1;
		bool T_empty=true;
		vector<int> gettmp;
		vector<int> gettmp2;
		gettmp=p1.GetCard();
		gettmp2=p2.GetCard();
		int pass=0;
		while(true){

		if(turnc==1){
			if(round==1){
				if(find(gettmp.begin(),gettmp.end(),0) != gettmp.end()){ // Check if who play first
					state=1;
					cout <<"\n--------" << p1.Getname() <<" play first--------\n";
				}else if(find(gettmp2.begin(),gettmp2.end(),0) != gettmp2.end()){
					state=2;
					cout <<"\n--------" << p2.Getname() <<" play first--------\n";			
				}else{
					state=3;
					cout <<"\n--------" << p3.Getname() <<" play first--------\n";
				}
			}else {
				if(p1.Gettype()=="Slave"){
					state=1;
					cout <<"\n--------" << p1.Getname() <<" play first--------\n";
				}else if(p2.Gettype()=="Slave"){
					state=2;
					cout <<"\n--------" << p2.Getname() <<" play first--------\n";	
				}else if(p3.Gettype()=="Slave"){
					state=3;
					cout <<"\n--------" << p3.Getname() <<" play first--------\n";
				}
			}
				
			if(state==1){//Player 1 first play
				    
				while(true){
				hand.clear();
				hand=ChooseCard(p1,T_empty);
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(round==1){
					
//				if(find(hand.begin(),hand.end(),0) != hand.end()){
					
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p1.eraseCard(hand[i]);
									
						p1.decCardCount();
						
						
					}
					cout<< " Ha123";
					maxTable=maxCard;
					cout<< " Ha1";					
					break;
//				}else cout << "\n--------No 3\5 in your card, choose your card again--------\n\n"; 
				}else {
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p1.eraseCard(hand[i]);			// Erase cards that already used
						p1.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}
				}
				
				state=2;
				
		}else if(state==2){
				
			while(true){
				hand.clear();
				hand=ChooseCard(p2,T_empty);							// function choose card
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(round==1){
			
//				if(find(hand.begin(),hand.end(),0) != hand.end()){
						
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p2.eraseCard(hand[i]);
						
						p2.decCardCount();
						
						
					}

					maxTable=maxCard;	
			// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
//				}else cout << "\n--------No 3\5 in your card, choose your card again--------\n\n"; 
				}else {
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p2.eraseCard(hand[i]);			// Erase cards that already used
						p2.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}
			}
				
			state=3;	
				
		}else if(state==3){
				
			while(true){
				hand.clear();
				hand=ChooseCard(p3,T_empty);							// function choose card
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(round==1){
				
//				if(find(hand.begin(),hand.end(),0) != hand.end()){
				
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p3.eraseCard(hand[i]);
						
						p3.decCardCount();
						
						
					}

					maxTable=maxCard;				// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
//				}else cout << "\n--------No 3\5 in your card, choose your card again--------\n\n"; 
				}else {
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p3.eraseCard(hand[i]);			// Erase cards that already used
						p3.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}
			}				
			state=1;			
		}
		turnc++;	
			
		}else{
//			system("cls");
			
//			if(kingchk==1&&kprintchk) {
//				cout << p1.Getname()<<"is the Winner!! and now \"KING\" \n";
//				kprintchk=false;
//			}
//			else if(kingchk==2&&kprintchk) {
//				cout << p2.Getname()<<"is the Winner!! and now \"KING\" \n";
//				kprintchk=false;
//			}
//			else if(kingchk==3&&kprintchk)  {
//				cout << p3.Getname()<<"is the Winner!! and now \"KING\" \n";
//				kprintchk=false;
//			}
			if(Table.size()>0) T_empty=false;
			else T_empty=true;
			
			if(state==1){
				
				if(p2.plpass&&pass==2){
					p1.newturn();
					p2.newturn();
					p3.newturn();
				}					
				if(pass==2)pass=0;
			
				while(true){
					
				if(kingchk==1)break;
					cout << "\n-------- Table card ";
					for(int i=0;i<Table.size();i++){
						cout << Table[i] << " ";
					}
					cout << "--------\n";
					cout << "\n--------"<< p1.Getname()<<"'s turn--------\n";	
					hand.clear();
					hand=ChooseCard(p1,T_empty);					// function choose card
					if(hand.size()>0){
						maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
						maxCard=moreCard(hand,maxCard);
						if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
							cout << "\n--------Choose your card again--------\n";
						}else{
							Table.clear();
							for(int i=0;i<hand.size();i++){
								Table.push_back(tmpface[hand[i]]);
								p1.eraseCard(hand[i]);			// Erase cards that already used
								p1.decCardCount();
							}
							maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
							break;
						}
				}else{ // if player pass code goes here
					pass++;
					
					if(pass==1){ //first pass
						p1.pass();			
						break;
					}else if(pass==2){
						Table.clear();
						maxTable=0;
						if(p2.plpass)state=3;
						else state=2;
						p1.newturn();
						p2.newturn();
						p3.newturn();
						break;
					}	
				}
				
				}
				if(kingchk==0){
					if(round==1){
						if(p1.isWin()){
							p1.typechange("King");
							system("cls");
							kingchk=1;
							endchk+=1;
						}
					}else {
						if(p1.isWin()&&p1.Gettype()=="King"){
							system("cls");
							kingchk=1;
							endchk+=1;
						}else if(p1.isWin()&&p1.Gettype()!="King"){
							p1.typechange("King");
							if(p2.Gettype()=="King"){
								cout << p1.Getname() << " is new King!! and "<< p2.Getname() <<" is slave\n";
								p2.typechange("Slave");
							}
							else if(p3.Gettype()=="King"){
								cout << p1.Getname() << " is new King!! and "<< p3.Getname() <<" is slave\n";
								p3.typechange("Slave");
							}
							cout << "Play again ?\n";
							cout << "[Y] play again [N] Exit to main menu [E] Exit :";
							cin >> paga;
							if(paga=='Y'||paga=='y') goto playagain;
							else if(paga=='N'||paga=='n') goto mainmenu;
							else if(paga=='E'||paga=='e') break;
						}				
					}
				}else {
						if(p1.isEmptyHand()&&kingchk!=1){					
							endchk+=1;
							if(endchk==2){
								round++;
								system("cls");
								cout << "You are People\n";
								if(kingchk==2) {
									cout << p3.Getname() <<"is now slave \n ";
									p3.typechange("Slave");
								}
								else {
									cout << p2.Getname() <<"is now slave \n ";
									p2.typechange("Slave");
								}
								cout << "Play again ?\n";
								cout << "[Y] play again [N] Exit to main menu [E] Exit :";
								cin >> paga;
								if(paga=='Y'||paga=='y') goto playagain;
								else if(paga=='N'||paga=='n') goto mainmenu;
								else if(paga=='E'||paga=='e') break;
							}
							}
				} 	
				if(pass!=2){
					if(p2.plpass)state=3;			
					else state=2;
				}
				
				
			}else if(state==2){	
				if(pass==2)pass=0;
				while(true){
					if(kingchk==2)break;
					
					cout << "\n-------- Table card ";
					for(int i=0;i<Table.size();i++){
						cout << Table[i] << " ";
					}
					cout << "--------\n";
					cout << "\n--------"<< p2.Getname()<<"'s turn--------\n";	
					hand.clear();
					hand=ChooseCard(p2,T_empty);							// function choose card
					if(hand.size()>0){
						maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
						maxCard=moreCard(hand,maxCard);
						if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
							cout << "\n--------Choose your card again--------\n";
						}else{
							Table.clear();
							for(int i=0;i<hand.size();i++){
								Table.push_back(tmpface[hand[i]]);
								p2.eraseCard(hand[i]);			// Erase cards that already used
								p2.decCardCount();
							}
							maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
							break;
						}
					}else {
						pass++;
						if(pass==1){ //first pass
						p2.pass();			
						break;
					}else if(pass==2){
						Table.clear();
						maxTable=0;
						if(p3.plpass)state=1;
						else state=3;
						p1.newturn();
						p2.newturn();
						p3.newturn();
						break;
					}
					}
				}
				if(kingchk==0){
					if(round==1){
						if(p2.isWin()){
							p2.typechange("King");
							system("cls");
							kingchk=1;
							endchk+=1;
						}
					}else {
						if(p2.isWin()&&p2.Gettype()=="King"){
							system("cls");
							kingchk=1;
							endchk+=1;
						}else if(p2.isWin()&&p2.Gettype()!="King"){
							p2.typechange("King");
							if(p1.Gettype()=="King"){
								cout << p2.Getname() << " is new King!! and "<< p1.Getname() <<" is slave\n";
								p2.typechange("Slave");
							}
							else if(p3.Gettype()=="King"){
								cout << p2.Getname() << " is new King!! and "<< p3.Getname() <<" is slave\n";
								p3.typechange("Slave");
							}
							cout << "Play again ?\n";
							cout << "[Y] play again [N] Exit to main menu [E] Exit :";
							cin >> paga;
							if(paga=='Y'||paga=='y') goto playagain;
							else if(paga=='N'||paga=='n') goto mainmenu;
							else if(paga=='E'||paga=='e') break;
						}				
					}
				}else {
					if(p2.isEmptyHand()&&kingchk!=2){
						system("cls");
						endchk+=1;
						if(endchk==2){
							round++;
							cout << "You are People\n";
							if(kingchk==1) {
								cout << p3.Getname() <<"is now slave \n ";
								p3.typechange("Slave");
							}
							else {
								cout << p1.Getname() <<"is now slave \n ";
								p1.typechange("Slave");
							}
							cout << "Play again ?\n";
							cout << "[Y] play again [N] Exit to main menu [E] Exit :";
							cin >> paga;
							if(paga=='Y'||paga=='y') goto playagain;
							else if(paga=='N'||paga=='n') goto mainmenu;
							else if(paga=='E'||paga=='e') break;
						}
						
					}
					
				}
				if(pass!=2){
					if(p3.plpass)state=1;			
					else state=3;	
				}
			
			}else if(state==3){

				if(pass==2)pass=0;
				while(true){
					if(kingchk==3)break;
					
					cout << "\n-------- Table card ";
					for(int i=0;i<Table.size();i++){
						cout << Table[i] << " ";
					}
					cout << "--------\n";
					cout << "\n--------"<< p3.Getname()<<"'s turn--------\n";	
					hand.clear();
					hand=ChooseCard(p3,T_empty);							// function choose card
					if(hand.size()>0){
						maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
						maxCard=moreCard(hand,maxCard);
						if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
							cout << "\n--------Choose your card again--------\n";	
						}else{
							Table.clear();
							for(int i=0;i<hand.size();i++){
								Table.push_back(tmpface[hand[i]]);
								p3.eraseCard(hand[i]);			// Erase cards that already used
								p3.decCardCount();
							}
							maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
							break;
						}
					}else {
						pass++;
						
						if(pass==1){ //first pass
							p3.pass();			
							break;
						}else if(pass==2){
							Table.clear();
							maxTable=0;
							if(p1.plpass)state=2;
							else state=1;
							p1.newturn();
							p2.newturn();
							p3.newturn();
							break;
						}	
					}
				}
				if(kingchk==0){
					if(round==1){
						if(p3.isWin()){
							p3.typechange("King");
							system("cls");
							kingchk=1;
							endchk+=1;
						}
					}else {
						if(p3.isWin()&&p3.Gettype()=="King"){
							system("cls");
							kingchk=1;
							endchk+=1;
						}else if(p3.isWin()&&p3.Gettype()!="King"){
							p3.typechange("King");
							if(p1.Gettype()=="King"){
								cout << p3.Getname() << " is new King!! and "<< p1.Getname() <<" is slave\n";
								p1.typechange("Slave");
							}
							else if(p2.Gettype()=="King"){
								cout << p3.Getname() << " is new King!! and "<< p2.Getname() <<" is slave\n";
								p2.typechange("Slave");
							}
							cout << "Play again ?\n";
							cout << "[Y] play again [N] Exit to main menu [E] Exit :";
							cin >> paga;
							if(paga=='Y'||paga=='y') goto playagain;
							else if(paga=='N'||paga=='n') goto mainmenu;
							else if(paga=='E'||paga=='e') break;
						}				
					}
				}else {
					if(p3.isEmptyHand()&&kingchk!=3){
						system("cls");
						endchk+=1;
						if(endchk==2) {
							round++;
							cout << "You are now People\n";
							if(kingchk==1) {
								cout << p2.Getname() <<"is now slave \n ";
								p2.typechange("Slave");
							}
							else {
								cout << p1.Getname() <<"is now slave \n ";
								p1.typechange("Slave");
							}
							cout << "Play again ?\n";
							cout << "[Y] play again [N] Exit to main menu [E] Exit :";
							cin >> paga;
							if(paga=='Y'||paga=='y') goto playagain;
							else if(paga=='N'||paga=='n') goto mainmenu;
							else if(paga=='E'||paga=='e') break;
						}
						
					}
					
				}
				if(pass!=2){
					if(p1.plpass)state=2;
					else state=1;
				}
			}
			turnc++;
			}

		}
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
	exit :
	return 0;
}

int moreCard(vector<int> hand,int max){
	if(hand.size()==2)max+=100;
	else if(hand.size()==3)max+=200;
	else if(hand.size()==4)max+=300;
	return max;
}
bool check(vector<int> card){
	int temp=card[0]/4;
	for(int i=0;i<card.size();i++){
		if(temp==card[i]/4);
		else return true;
	}
	return false;
}
vector<int> ChooseCard(Player P,bool t_empty){
	bool chk;
	vector<int> getcard;
	vector<int> order;
	vector<int> cardChoose=P.GetCard();
	vector<string> cFace=P.GetFace();
	int choose1,choose2,choose3,choose4;
//	vector<char> cardbag;
	string strget;
	for(int i=0;i<cardChoose.size();i++){
		order.push_back(i);
	}
	for(int i=0;i<cFace.size();i++){
		if(i<=9 && (cardChoose[i]>=28&&cardChoose[i]<=31)) cout << order[i] <<"   ";
		else if(i<=9) cout << order[i] <<"  ";
		else{
			if(cardChoose[i]>=28&&cardChoose[i]<=31) cout << order[i] <<"  ";
			else cout << order[i] <<" ";
		} 	
	}
	
	cout << "\n";
	for(int i=0;i<cFace.size();i++){
		cout << cFace[i]<< " ";
	}
	cout << "\n\n";
		

		step1:
		if(t_empty){
			do{
			getcard.clear();
			cout<<"choose your [number] for card :";
			getline(cin,strget);
			if(strget=="P"||strget=="p")goto step1;
			stringstream stream(strget);
			int n;
			while(stream >> n) {
  				getcard.push_back(cardChoose[n]);
  				get1tmp=getcard.size();
			}


		}while(getcard.size()>4);
		}else {
				do{
			getcard.clear();
			cout<<"choose your [number] for card or [p] to pass ";
			getline(cin,strget);
			if(strget=="P"||strget=="p")break;
			stringstream stream(strget);
			int n;
			while(stream >> n) {
  				getcard.push_back(cardChoose[n]);
  			if(!stream)
  		    	break;
			}
		
		}while(getcard.size()>4);
		if(strget=="P"||strget=="p")return getcard;
		if(get1tmp%2==getcard.size()%2) get1tmp=getcard.size();
		else goto step1;
	
		}
		
		
		
	
	
	if(getcard.size()>=1){
		chk=check(getcard);	
		if(chk){
		getcard.clear();
		cout << "\n-------- Your cards not match, Please choose again--------\n";
		goto step1;
		}
	}
	
	
	return getcard;
	
}
