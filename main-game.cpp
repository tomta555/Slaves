#include"classgame.h"
bool check(vector<int> card){
	int temp=card[0]/4;
	for(int i=0;i<card.size();i++){
		if(temp==card[i]/4)
		else return true;
	}
	return false;
}
int main(){
//drawScreen;
 	want/////maised
	vector<int> getcard={};
	char player_action ='\0';
	game_count=1;
	round_count=1;
	turn_count=1;
	step1 :
		cout<<"choose amount card [1] [2] [3] [4] ";
		cin>>player_action;
		if(player_action!='1'or player_action!='2'or player_action!='3'or player_action!='4')
			goto step1;
	step2 :	
		switch(player_action){
			case '1': 
					cin>>want;//
					getcard.push_back(want);//
					break;
			case '2':for(int i=0;i<2;i++){
					cin>>want;//
					getcard.push_back(want);//
					}
					break;
			case '3':for(int i=0;i<3;i++){
					cin>>want;//
					getcard.push_back(want);//
					}
					break;
			case '4':for(int i=0;i<4;i++){
					cin>>want;//
					getcard.push_back(want);//
					}
					break;
	}
	check(getcard);
	if(check){
		getcard.clear();
		goto step2;
	}
		
	turn_count++;
	while(true){
		while(finishround){//
			while(passall){//
				
				
			turn_count++;
			}
		round_count++;
		}
	cout<<"CONTINUE [C] or EXIT [E] "; 
	cin>>player_action;
	if(player_action=='E' or player_action=='e')break;
	game_count++;
	}
			//send.vector.toclass
		
	return 0;
}
