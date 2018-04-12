#include"classgame.h"
bool check(vector<int> card){
	int temp=card[0]/4;
	for(int i=0;i<card.size();i++){
		if(temp==card[i]/4)
		else return true;
	}
	return false;
}
void setcard(int turn,char &totle){

   	step1 :
		if(turn==1){
			cout<<"choose amount card [1] [2] [3] [4] ";
			cin>>totle;
			if(totle!='1'or totle!='2'or totle!='3'or totle!='4')
			goto step1;
		}
		else if(totle=1){cout<<"choose amount card [1] [3] ";
			cin>>totle;
			if(totle!='1'or totle!='3')
			goto step1;
		}
		else if(totle=2){cout<<"choose amount card [2] [4] ";
			cin>>totle;
			if(totle!='2'or totle!='4')
			goto step1;
		}
		else if(totle=3){cout<<"choose amount card [3] ";
			cin>>totle;
			if(totle!='3')
			goto step1;
		}
		else if(totle=4){cout<<"choose amount card [4] ";
			cin>>totle;
			if(totle!='4')
			goto step1;
		}

	step2 :	
		switch(totle){
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
	step3 : 
			

}

		
int main(){
//drawScreen;
	int state=1;
	char totle='0';
 	want/////maised
	vector<int> getcard={};
	char player_action ='\0';
	game_count=1;
	round_count=1;
	turn_count=1;
	
	turn_count++;
	while(true){
		while(finishround){//
			while(passall){//
				if(state==1){
				setcard(turn_count,totle);
					state=2;
					
				}
				else if(state==2){
					
					if(numplayer>2)state=3;
					else state=1;
				}
				else if(state==3){
					
					if(numplayer==4)state=4;
					else state=1;
				}
				else if(state==4){
					
					state=1;
				}
				

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
