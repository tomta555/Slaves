#include <iostream>
#include <cmath>
#include <sstream>
#include "Deck2.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char player_action ,player_action0,pa_tmp;
int get1tmp;
bool check(vector<int>);
vector<int> ChooseCard(Player, bool);
int moreCard(vector<int> ,int);
vector<int> TradeCard(Player, bool);
bool is_digits(const string &);

int main(){
	mainmenu :
	srand(unsigned(time(NULL)));
	string K="King",P="People",S="Slave";
	vector<int> cardslave;
	vector<int> cardking;
	int lKing,lSlave;
	int num;
	int maxCard;
	int maxTable;
	vector<int> hand;
	int round=1;
	int old_kingchk=0;
	
	start :
	cout << "********************************************************************************************************\n";
	cout << "********************************************************************************************************\n";
	cout << "******                                                                                            ******\n";
	cout << "******    SSSS   L         A    V     V  EEEEE      M     M     A     SSSS  TTTTT  EEEEE  RRRR    ******\n";
	cout << "******   S       L         A     V   V   E          M M M M     A    S        T    E      R   R   ******\n";
	cout << "******    SSSS   L        A A     V V    EEEEE      M  M  M    A A    SSSS    T    EEEEE  RRRR    ******\n";
	cout << "******        S  L       AAAAA     V     E          M     M   AAAAA       S   T    E      R  R    ******\n";
	cout << "******    SSSS   LLLLL  A     A    V     EEEEE      M     M  A     A  SSSS    T    EEEEE  R   R   ******\n";
	cout << "******                                                                                            ******\n";
	cout << "********************************************************************************************************\n";
	cout << "********************************************************************************************************\n\n";

	cout << "    ---------------------------------------------------------------------------------------------------\n";
	cout << "|	 PPPP   L      EEEEE     A    SSSS   EEEEE     PPPP   L         A    Y     Y    OOOOO  N    N  |\n";
	cout << "|	 P   P  L      E         A   S       E         P   P  L         A     Y   Y     O   O  NN   N  |\n";
	cout << "|	 PPPP   L      EEEEE    A A   SSSS   EEEEE     PPPP   L        A A      Y       O   O  N N  N  |\n";
	cout << "|	 P      L      E       AAAAA      S  E         P      L       AAAAA     Y       O   O  N  N N  |\n";
	cout << "|	 P      LLLLL  EEEEE  A     A SSSS   EEEEE     P      LLLLL  A     A    Y       OOOOO  N   NN  |\n" << "\n\n";
	
	cout << "|	 	 FFFFF  U   U  L      L           SSSS    CCCC  RRRR   EEEEE  EEEEE  N    N  		  |\n";
	cout << "|		 F      U   U  L      L          S       C      R   R  E      E      NN   N  		  |\n";
	cout << "|		 FFFFF  U   U  L      L      ---  SSSS   C      RRRR   EEEEE  EEEEE  N N  N 		  |\n";
	cout << "|		 F      U   U  L      L               S  C      R  R   E      E      N  N N  		  |\n";
	cout << "|		 F       UUU   LLLLL  LLLLL       SSSS    CCCC  R   R  EEEEE  EEEEE  N   NN  		  |\n" << "\n";
	cout << "    ---------------------------------------------------------------------------------------------------\n\n";
		
	cout << "[1] Play with BOT(NOT AVALIABLE!!), [2] 2 Players, [3] 3 Players, [4] 4 Players\n"; //Add
	cout << "PLAY SELECT : ";  //Add
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
					cout << "\n\n----------------------------"<< p1.Getname()<< " play FIRST   ----------------------------\n\n";
				}else{
					state=2;
					cout << "\n\n----------------------------"<< p2.Getname()<< " play FIRST   ----------------------------\n\n";
				}
			}else{
				if(kingchk==1) {
					cout << "\n\n----------------------------"<< p2.Getname()<< " play FIRST   ----------------------------\n\n";
					state=2;
				}
				else if(kingchk==2){
					cout << "\n\n----------------------------"<< p1.Getname()<< " play FIRST   ----------------------------\n\n";
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
				}else cout << "\n--------There is no 3\5 in your selected card, choose your card again--------\n"; 
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
				}else cout << "\n--------There is no 3\5 in your selected card, choose your card again--------\n"; 
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
					cout << "\n\n------------------------------- Card Table -------------------------------\n\n\n\n\n\n\n\n\n\n\n";
					for(int i=0;i<Table.size();i++){
						cout << "		|" << Table[i] << "|  ";
					}
					cout << "\n\n\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------\n";
				cout << "\n\n----------------------------"<< p1.Getname()<< "'s turn   ----------------------------\n\n";		
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
					cout << "\n\n------------------------------- Card Table -------------------------------\n\n\n\n\n\n\n\n\n\n\n";
					for(int i=0;i<Table.size();i++){
						cout << "		|" << Table[i] << "|  ";
					}
					cout << "\n\n\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------\n";
				cout << "\n\n----------------------------"<< p2.Getname()<< "'s turn   ----------------------------\n\n";		
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
		int playernum=3;
		
		if(round>1){
			
			switch(lKing){
				case 1:
					p1.typechange(K);
					break;
				case 2: 
					p2.typechange(K);
					break;
				case 3:
					p3.typechange(K);
					break;
			}
			switch(lSlave){
				case 1:
					p1.typechange(S);
					break;
				case 2: 
					p2.typechange(S);
					break;
				case 3:
					p3.typechange(S);
					break;
			}	
		}
		
		
		system("cls");
		if(round>1){
		
		cout <<"-------------" << p1.Getname() << " is " << p1.Gettype() <<"-------------"<<"\n\n"; 
		cout <<"-------------" << p2.Getname() << " is " << p2.Gettype() <<"-------------"<<"\n\n"; 
		cout <<"-------------" << p3.Getname() << " is " << p3.Gettype() <<"-------------"<<"\n\n"; 
		
		cout<< "-----------------King select 2 cards to trade with slave-----------------\n";
		cin.ignore();
		if(lSlave==1){
			cardslave.push_back(p1.popbackcard());
			p1.eraseCard(cardslave[0]);
			cardslave.push_back(p1.popbackcard());
			p1.eraseCard(cardslave[1]);	
		}else if(lSlave==2){
			cardslave.push_back(p2.popbackcard());
			p2.eraseCard(cardslave[0]);
			cardslave.push_back(p2.popbackcard());
			p2.eraseCard(cardslave[1]);					
		}else if(lSlave==3){
			cardslave.push_back(p3.popbackcard());
			p3.eraseCard(cardslave[0]);
			cardslave.push_back(p3.popbackcard());
			p3.eraseCard(cardslave[1]);				
		}

		switch(lKing){
				case 1:{
					do{
						cardking.clear();
						cardking=TradeCard(p1,T_empty);						
					}while(cardking.size()!=2);	
					p1.eraseCard(cardking[0]);
					p1.eraseCard(cardking[1]);
					p1.addcard(cardslave[0]);
					p1.addcard(cardslave[1]);
					p1.sortcard();p1.sortface();
					break;
				}
					
				case 2: {
					do{

						cardking.clear();
						cardking=TradeCard(p2,T_empty);
					}while(cardking.size()!=2);
					p2.eraseCard(cardking[0]);
					p2.eraseCard(cardking[1]);
					p2.addcard(cardslave[0]);
					p2.addcard(cardslave[1]);
					p2.sortcard();p2.sortface();				
					break;					
				}

				case 3:{
					do{

						cardking.clear();
						cardking=TradeCard(p3,T_empty);
					}while(cardking.size()!=2);
					p3.eraseCard(cardking[0]);
					p3.eraseCard(cardking[1]);
					p3.addcard(cardslave[0]);
					p3.addcard(cardslave[1]);
					p3.sortcard();p3.sortface();		
					break;					
				}
			}
			switch(lSlave){
				case 1:{
					p1.addcard(cardking[0]);
					p1.addcard(cardking[1]);
					p1.sortcard();p1.sortface();
					break;
				}
				case 2: {
					p2.addcard(cardking[0]);
					p2.addcard(cardking[1]);
					p2.sortcard();p2.sortface();			
					break;
				}
				case 3:{
					p3.addcard(cardking[0]);
					p3.addcard(cardking[1]);
					p3.sortcard();p3.sortface();			
					break;
				}				
			}
		}
		

		
		while(true){

		if(turnc==1){
			if(round==1){
				if(find(gettmp.begin(),gettmp.end(),0) != gettmp.end()){ // Check if who play first
					state=1;
					cout << "\n\n----------------------------"<< p1.Getname()<< " play FIRST   ----------------------------\n\n";
				}else if(find(gettmp2.begin(),gettmp2.end(),0) != gettmp2.end()){
					state=2;
					cout << "\n\n----------------------------"<< p2.Getname()<< " play FIRST   ----------------------------\n\n";		
				}else{
					state=3;
					cout << "\n\n----------------------------"<< p3.Getname()<< " play FIRST   ----------------------------\n\n";
				}
			}else {
				if(p1.Gettype()==S){
					state=1;
					cout << "\n\n----------------------------"<< p1.Getname()<< " play FIRST   ----------------------------\n\n";
				}else if(p2.Gettype()==S){
					state=2;
					cout << "\n\n----------------------------"<< p2.Getname()<< " play FIRST   ----------------------------\n\n";
				}else if(p3.Gettype()==S){
					state=3;
					cout << "\n\n----------------------------"<< p3.Getname()<< " play FIRST   ----------------------------\n\n";
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
						p1.eraseCard(hand[i]);			
						p1.decCardCount();
							
					}
					maxTable=maxCard;				
					break;
				}else cout << "\n--------There is no 3\5 in your selected card, choose your card again--------\n"; 
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
						p2.eraseCard(hand[i]);
						
						p2.decCardCount();
						
						
					}

					maxTable=maxCard;	

					break;
				}else cout << "\n--------There is no 3\5 in your selected card, choose your card again--------\n"; 
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
				
				if(find(hand.begin(),hand.end(),0) != hand.end()){
				
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p3.eraseCard(hand[i]);
						
						p3.decCardCount();
						
						
					}

					maxTable=maxCard;				// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}else cout << "\n--------There is no 3\5 in your selected card, choose your card again--------\n"; 
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
			system("cls");
			
			if(kingchk==1&&kprintchk) {
				cout <<"-------------"<< p1.Getname()<<"is the Winner!! and now \"KING\" "<<"--------------\n";
				kprintchk=false;
			}
			else if(kingchk==2&&kprintchk) {
				cout <<"-------------"<< p2.Getname()<<"is the Winner!! and now \"KING\" "<<"-------------\n";
				kprintchk=false;
			}
			else if(kingchk==3&&kprintchk)  {
				cout <<"-------------"<< p3.Getname()<<"is the Winner!! and now \"KING\" "<<"-------------\n";
				kprintchk=false;
			}
			if(Table.size()>0) T_empty=false;
			else T_empty=true;
			
			if(state==1){
				
				if(p2.plpass&&pass==playernum-1){
					p1.newturn();
					p2.newturn();
					p3.newturn();
				}					
				if(pass==playernum-1)pass=0;
			
				while(true){
					
				if(kingchk==1)break;
					cout << "\n\n------------------------------- Card Table -------------------------------\n\n\n\n\n\n\n\n\n\n\n";
					for(int i=0;i<Table.size();i++){
						cout << "		|" << Table[i] << "|  ";
					}
					cout << "\n\n\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------\n";
					
					cout << "\n\n----------------------------"<< p1.Getname()<< "'s turn   ----------------------------\n\n";	
					hand.clear();
					if(maxCard<maxTable){				
							cout << "\n--------Choose your card again--------\n";}
					hand=ChooseCard(p1,T_empty);					// function choose card
					if(hand.size()>0){
						maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
						maxCard=moreCard(hand,maxCard);
						if(maxCard<maxTable){				// if cards on hand are less value than cards on the table ->  choose cards again! 
//							cout << "\n--------Choose your card again--------\n";
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
					if(pass==playernum-1){
						Table.clear();
						maxTable=0;
						if(p2.plpass)state=3;
						else state=2;
						p1.newturn();
						p2.newturn();
						p3.newturn();
						break;
					}
					else if(pass==1){ //first pass
						p1.pass();			
						break;
					}						
				}
				
				}
				if(kingchk==0){
					if(round==1){
						if(p1.isWin()){
							lKing=1;
							system("cls");
							kingchk=1;
							endchk+=1;
							playernum--;
						}
					}else {
						if(p1.isWin()&&p1.Gettype()==K){
							system("cls");
							kingchk=1;
							endchk+=1;
							playernum--;
						}else if(p1.isWin()&&p1.Gettype()!=K){
							kingchk=1;
							endchk+=1;
							lKing=1;
							playernum--;
							if(p2.Gettype()==K){
								cout << p1.Getname() << " is new King!! and "<< p2.Getname() <<" is slave\n";
								lSlave=2;
							}
							else if(p3.Gettype()==K){
								cout << p1.Getname() << " is new King!! and "<< p3.Getname() <<" is slave\n";
								lSlave=3;
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
									cout << p3.Getname() <<" is now slave \n ";
									lSlave=3;
								}
								else {
									cout << p2.Getname() <<" is now slave \n ";
									lSlave=2;
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
				if(pass!=playernum-1){
					if(p2.plpass)state=3;			
					else state=2;
				}
				
				
			}else if(state==2){
				if(pass==playernum-1)pass=0;
				while(true){
					if(kingchk==2)break;
					
					cout << "\n\n------------------------------- Card Table -------------------------------\n\n\n\n\n\n\n\n\n\n\n";
					for(int i=0;i<Table.size();i++){
						cout << "		|" << Table[i] << "|  ";
					}
					cout << "\n\n\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------\n";
					cout << "\n\n----------------------------"<< p2.Getname()<< "'s turn   ----------------------------\n\n";	
					hand.clear();
					if(maxCard<maxTable){				
							cout << "\n--------Choose your card again--------\n";}
					hand=ChooseCard(p2,T_empty);							// function choose card
					if(hand.size()>0){
						maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
						maxCard=moreCard(hand,maxCard);
						if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
//							cout << "\n--------Choose your card again--------\n";
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
						if(pass==playernum-1){
							Table.clear();
							maxTable=0;
							if(p3.plpass)state=1;
							else state=3;
							p1.newturn();
							p2.newturn();
							p3.newturn();
							break;
						}
						else if(pass==1){ //first pass
							p2.pass();			
							break;
						}
					}
				}
				if(kingchk==0){
					if(round==1){
						if(p2.isWin()){
							lKing=2;
							system("cls");
							kingchk=2;
							endchk+=1;
							playernum--;
						}
					}else {
						if(p2.isWin()&&p2.Gettype()==K){
							system("cls");
							kingchk=2;
							endchk+=1;
							playernum--;
						}else if(p2.isWin()&&p2.Gettype()!=K){
							kingchk=2;
							endchk+=1;
							lKing=2;
							playernum--;
							if(p1.Gettype()==K){
								cout << p2.Getname() << " is new King!! and "<< p1.Getname() <<" is slave\n";
								lSlave=1;
							}
							else if(p3.Gettype()==K){
								cout << p2.Getname() << " is new King!! and "<< p3.Getname() <<" is slave\n";
								lSlave=3;
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
								cout << p3.Getname() <<" is now slave \n ";
								lSlave=3;
							}
							else {
								cout << p1.Getname() <<" is now slave \n ";
								lSlave=1;
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
				if(pass!=playernum-1){
					if(p3.plpass)state=1;			
					else state=3;	
				}
			
			}else if(state==3){

				if(pass==2)pass=0;
				while(true){
					if(kingchk==3)break;
					
					cout << "\n\n------------------------------- Card Table -------------------------------\n\n\n\n\n\n\n\n\n\n\n";
					for(int i=0;i<Table.size();i++){
						cout << "		|" << Table[i] << "|  ";
					}
					cout << "\n\n\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------\n";
					cout << "\n\n----------------------------"<< p3.Getname()<< "'s turn   ----------------------------\n\n";	
					hand.clear();
					if(maxCard<maxTable){				
							cout << "\n--------Choose your card again--------\n";}
					hand=ChooseCard(p3,T_empty);							// function choose card
					if(hand.size()>0){
						maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
						maxCard=moreCard(hand,maxCard);
						if(maxCard<maxTable){					// if cards on hand are less value than cards on the table ->  choose cards again! 
//							cout << "\n--------Choose your card again--------\n";	
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
						if(pass==playernum-1){
							Table.clear();
							maxTable=0;
							if(p1.plpass)state=2;
							else state=1;
							p1.newturn();
							p2.newturn();
							p3.newturn();
							break;
						}
						else if(pass==1){ //first pass
							p3.pass();			
							break;
						}	
					}
				}
				if(kingchk==0){
					if(round==1){
						if(p3.isWin()){
							lKing=3;
							system("cls");
							kingchk=3;
							endchk+=1;
							playernum--;
						}
					}else {
						if(p3.isWin()&&p3.Gettype()==K){
							system("cls");
							kingchk=3;
							endchk+=1;
							playernum--;
						}else if(p3.isWin()&&p3.Gettype()!=K){
							kingchk=3;
							endchk+=1;
							lKing=3;
							playernum--;
							if(p1.Gettype()==K){
								cout << p3.Getname() << " is new King!! and "<< p1.Getname() <<" is slave\n";
								lSlave=2;
							}
							else if(p2.Gettype()==K){
								cout << p3.Getname() << " is new King!! and "<< p2.Getname() <<" is slave\n";
								lSlave=2;
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
								cout << p2.Getname() <<" is now slave \n ";
								lSlave=2;
							}
							else {
								cout << p1.Getname() <<" is now slave \n ";
								lSlave=1;
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
				if(pass!=playernum-1){
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
			if(!is_digits(strget))goto step1;
			stringstream stream(strget);
			int n;
			while(stream >> n) {
  				getcard.push_back(cardChoose[n]);
  				get1tmp=getcard.size();
			}
			if(getcard.size()==0) goto step1;
		}while(getcard.size()>4);
		}else {
				do{
			getcard.clear();
			cout<<"choose your [number] for card or [p] to pass ";
			getline(cin,strget);
			if(strget=="P"||strget=="p")break;
			else if(!is_digits(strget))goto step1;
			stringstream stream(strget);
			int n;
			while(stream >> n) {
  				getcard.push_back(cardChoose[n]);
			}
			if(getcard.size()==0) goto step1;
		}while(getcard.size()>4);
		
		if(strget=="P"||strget=="p")return getcard;
		if(get1tmp%2==getcard.size()%2) get1tmp=getcard.size();
		else {
			cout << "\n--------Please choose again--------\n";
			goto step1;
		}
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
vector<int> TradeCard(Player P,bool t_empty){
	bool chk;
	vector<int> getcard;
	vector<int> order;
	vector<int> cardChoose=P.GetCard();
	vector<string> cFace=P.GetFace();;
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
		
		TC1:
		if(t_empty){
			do{
				getcard.clear();
				cout<<"choose your [number] for card :";
				getline(cin,strget);
				if(!is_digits(strget))goto TC1;
				stringstream stream(strget);
				int n;
				while(stream >> n) {
  					getcard.push_back(cardChoose[n]);
				}
				if(getcard.size()==0) goto TC1;
			}while(getcard.size()>4);
		}

		if(getcard.size()!=2) {
			cout << "\n--------Please choose 2 card!!--------\n";
			goto TC1;
		}

	return getcard;
}
bool is_digits(const string &str) {
    return str.find_first_not_of("0123456789 ") == string::npos;
}
