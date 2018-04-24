#include <iostream>
#include <cmath>
#include "Deck2.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char player_action ,player_action0,pa_tmp;
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
	
	if(num>4 || num<1) {
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
		int turnc=1;
		bool T_empty=true;
		vector<int> gettmp;
		Player p1(name[0],c1.cardFace,c1.cards,c1.faceShuff,0,26);   // get cards from deck
		Player p2(name[1],c1.cardFace,c1.cards,c1.faceShuff,26,52);
		p1.sortcard(); p1.sortface(); p2.sortcard(); p2.sortface();  // sorting card that get from deck
		gettmp=p1.GetCard();
		
		while(true){
		if(turnc==1){
			if(find(gettmp.begin(),gettmp.end(),0) != gettmp.end()){ // Check if who play first
					state=1;
					cout << "\n----------------Player[1] Play FIRST----------------\n";
			}else{
					state=2;
					cout << "\n----------------Player[2] Play FIRST----------------\n";	
				}
			if(state==1){//Player 1 first play
				    
				while(true){
				hand.clear();
				hand=ChooseCard(p1,T_empty);
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(find(hand.begin(),hand.end(),0) != hand.end()){
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p1.eraseCard(hand[i]);			// Erase cards that already used
						p1.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}else cout << "\n--------There is no 3\5 in your selected card, choose your card again--------\n"; 
				}
				
				state=2;
				
			}else if(state==2){
				
				while(true){
				hand.clear();
				hand=ChooseCard(p2,T_empty);							// function choose card
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(find(hand.begin(),hand.end(),0) != hand.end()){
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p2.eraseCard(hand[i]);			// Erase cards that already used
						p2.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}else cout << "\n--------There is no 3\5 in your selected card, choose your card again--------\n"; 
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
				cout << "\n\n----------------------------   Player[1] turn   ----------------------------\n\n";	
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
					cout << "Player 1 is the Winner!! and now \"KING\" \n";
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
					
					cout <<"\n\n\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------\n";
				cout << "\n\n----------------------------  Player[2] turn  ----------------------------\n\n";	
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
					cout << "Player 2 is the Winner!! and now \"KING\" \n";
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
			
			if(find(gettmp.begin(),gettmp.end(),0) != gettmp.end()){ // Check if who play first
					state=1;
					cout << "\n--------Player1 play first--------\n";
			}else if(find(gettmp2.begin(),gettmp2.end(),0) != gettmp2.end()){
					state=2;
					cout << "\n--------Player2 play first--------\n";					
			}else{
					state=3;
					cout << "\n--------Player3 play first--------\n";	
				}
				
			if(state==1){//Player 1 first play
				    
				while(true){
				hand.clear();
				hand=ChooseCard(p1,T_empty);
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(find(hand.begin(),hand.end(),0) != hand.end()){
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p1.eraseCard(hand[i]);			// Erase cards that already used
						p1.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}else cout << "\n--------There is no 3\5 in your selected card, choose your card again--------\n\n"; 
				}
				
				state=2;
				
		}else if(state==2){
				
			while(true){
				hand.clear();
				hand=ChooseCard(p2,T_empty);							// function choose card
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(find(hand.begin(),hand.end(),0) != hand.end()){
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p2.eraseCard(hand[i]);			// Erase cards that already used
						p2.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}else cout << "\n--------There is no 3\5 in your selected card, choose your card again--------\n\n"; 
			}
				
			state=3;	
				
		}else if(state==3){
				
			while(true){
				hand.clear();
				hand=ChooseCard(p3,T_empty);							// function choose card
				maxCard=*max_element(hand.begin(),hand.end());   // find maximun value of cards on hand to compare with value of cards on table
				maxCard=moreCard(hand,maxCard);
				if(find(hand.begin(),hand.end(),0) != hand.end()){
					for(int i=0;i<hand.size();i++){
						Table.push_back(tmpface[hand[i]]);
						p3.eraseCard(hand[i]);			// Erase cards that already used
						p3.decCardCount();
					}
					maxTable=maxCard;					// if value of cards on hand > value of cards on table you can use that cards -> put card on table
					break;
				}else cout << "\n--------There is no 3\5 in your selected card, choose your card again--------\n\n"; 
			}
				
			state=1;			
		}
		turnc++;	
			
		}else{
			
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
				cout << "\n\n------------------------------- Card Table -------------------------------\n\n\n\n\n\n\n\n\n\n\n";
					for(int i=0;i<Table.size();i++){
						cout << "		|" << Table[i] << "|  ";
					}
					
					cout <<"\n\n\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------\n";
				cout << "\n\n----------------------------  Player[1] turn  ----------------------------\n\n";	
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
					if(p1.isWin()){
						system("cls");
						cout << "Player 1 is the Winner!! and now \"KING\" \n";
						kingchk=1;
						endchk+=1;
					}
				}else {
					if(p1.isEmptyHand()&&kingchk!=1){
						system("cls");
						endchk+=1;
						if(endchk==2) cout << "You are now People\n";
						else cout << "You are now Slave";
						if(endchk==3){
							cout << "Play again ?\n";
							cout << "[Y] Play again [N] Exit to main menu [E] Exit :";
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
					cout << "\n\n------------------------------- Card Table -------------------------------\n\n\n\n\n\n\n\n\n\n\n";
					for(int i=0;i<Table.size();i++){
						cout << "		|" << Table[i] << "|  ";
					}
					
					cout <<"\n\n\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------\n";
				cout << "\n\n----------------------------  Player[2] turn  ----------------------------\n\n";	
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
					if(p2.isWin()){
						system("cls");
						cout << "Player 2 is the Winner!! and now \"KING\" \n";
						kingchk=2;
						endchk+=1;
					}
				}else {
					if(p2.isEmptyHand()&&kingchk!=2){
						system("cls");
						endchk+=1;
						if(endchk==2) cout << "You are now People\n";
						else cout << "You are now Slave";
						if(endchk==3){
							cout << "Play again ?\n";
							cout << "[Y] Play again [N] Exit to main menu [E] Exit :";
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
					cout << "\n\n------------------------------- Card Table -------------------------------\n\n\n\n\n\n\n\n\n\n\n";
					for(int i=0;i<Table.size();i++){
						cout << "		|" << Table[i] << "|  ";
					}
					
					cout <<"\n\n\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------\n";
				cout << "\n\n----------------------------  Player[3] turn  ----------------------------\n\n";	
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
					if(p3.isWin()){
						system("cls");
						cout << "Player 3 is the Winner!! and now \"KING\" \n";
						kingchk=2;
						endchk+=1;
					}
				}else {
					if(p3.isEmptyHand()&&kingchk!=1){
						system("cls");
						endchk+=1;
						if(endchk==2) cout << "You are now People\n";
						else cout << "You are now Slave";
						if(endchk==3){
							cout << "Play again ?\n";
							cout << "[Y] Play again [N] Exit to main menu [E] Exit :";
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
//	system("cls");
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
		

		step1 :
//		if (player_action0=='p'){do{
//			cout<<"choose your action \n [1] 1 card [2] 2 card [3] 3 card [4] 4 card : ";
//			cin>>player_action;
//			}while(player_action!='1'and player_action!='2'and player_action!='3'and player_action!='4');
//			goto step2;
//		}
		 if(t_empty==true){
			do{
				cout << "[1] One card, [2] Pair, [3] Three of kind, [4] Four of kind \n\nChoose your action = ";
				cin>>player_action;
			}while(player_action!='1'and player_action!='2'and player_action!='3'and player_action!='4');
			goto step2;
		}
	 	else if(player_action0=='1'){
			do{
				cout<<"[1] One card, [3] Three of kind, [p] Pass \n\nChoose your action = ";
				cin>>player_action;
			}while(player_action!='1'and player_action!='3'and player_action!='p');
			goto step2;
		}
		else if(player_action0=='2'){
			do{
				cout<<"[2] One card, [4] TFour of kind, [p] Pass \n\nChoose your action = ";
				cin>>player_action;
			}while(player_action!='2'and player_action!='4'and player_action!='p');
			goto step2;
			
		}
		else if(player_action0=='3'){
			do{
				cout<<"[3] Three of kind, [p] Pass \n\nChoose your action = ";
				cin>>player_action;
			}while(player_action!='3'and player_action!='p');
			 goto step2;
		}
		else if(player_action0=='4'){
			do{
				cout<<"[4] TFour of kind, [p] Pass \n\nChoose your action = ";
				cin>>player_action;
			}while(player_action!='4'and player_action!='p');
			goto step2;
		}
	
		
	step2 :
		switch(player_action){
			case '1': 	cout << "Choose card from number up here:";
					cin>>choose1;
					getcard.push_back(cardChoose[choose1]);
					break;
			case '2':	cout << "Choose card from number up here (use space):";
					cin>>choose1>>choose2;
					getcard.push_back(cardChoose[choose1]);
					getcard.push_back(cardChoose[choose2]);
					break;
			case '3':	cout << "Choose card from number up here (use space):";
					cin>>choose1>>choose2>>choose3;
					getcard.push_back(cardChoose[choose1]);
					getcard.push_back(cardChoose[choose2]);
					getcard.push_back(cardChoose[choose3]);
					break;
			case '4':	cout << "Choose card from number up here (use space):";
					cin>>choose1>>choose2>>choose3>>choose4;
					getcard.push_back(cardChoose[choose1]);
					getcard.push_back(cardChoose[choose2]);
					getcard.push_back(cardChoose[choose3]);
					getcard.push_back(cardChoose[choose4]);
					break;
			case 'p':
			case 'P':{
				player_action0=pa_tmp;
				return getcard;
			}
					
	}
	chk=check(getcard);
	if(chk){
		getcard.clear();
		cout << "\n-------- Your cards are not match, Please choose again--------\n";
		goto step1;
	}else {
	pa_tmp=player_action0=player_action;
	return getcard;
	}
}
