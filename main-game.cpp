#include"classgame.h"
char totle='0';
int maxscore=0,want1,want2,want3,want4,topscorenew=0,topscoreold=0;
vector<int> getcard;
vector<int> p1;
vector<int> p2;
vector<int> p3;
vector<int> p4;
int pass1,pass2,pass3,pass4;
char player_action ='\0';

bool check(vector<int> card){
	int temp=card[0]/4;
	for(int i=0;i<card.size();i++){
		if(temp==card[i]/4);
		else return true;
	}
	return false;
}

int setcard(int turn,char &totle,vector<int> player,int topscore){

   	step1 :
		if(turn==1){
			cout<<"choose amount card [1] [2] [3] [4] ";
			cin>>totle;
			if(totle!='1'or totle!='2'or totle!='3'or totle!='4')
			goto step1;
		}
		else if(totle=1){cout<<"choose amount card [1] [3] or pass [p] ";
			cin>>totle;
			if(totle!='1'or totle!='3'or totle!='p')
			goto step1;
		}
		else if(totle=2){cout<<"choose amount card [2] [4] or pass [p] ";
			cin>>totle;
			if(totle!='2'or totle!='4'or totle!='p')
			goto step1;
		}
		else if(totle=3){cout<<"choose amount card [3] or pass [p] ";
			cin>>totle;
			if(totle!='3'or totle!='p')
			goto step1;
		}
		else if(totle=4){cout<<"choose amount card [4] or pass [p] ";
			cin>>totle;
			if(totle!='4'or totle!='p')
			goto step1;
		}

	step2 :	
		switch(totle){
			case '1': 
					cin>>want1;//
					getcard.push_back(player[want1]);//
					break;
			case '2':
					cin>>want1>>want2;//
					getcard.push_back(player[want1]);
					getcard.push_back(player[want2]);//
					break;
			case '3':
					cin>>want1>>want2>>want3;//
					getcard.push_back(player[want1]);
					getcard.push_back(player[want2]);
					getcard.push_back(player[want3]);//
					break;
			case '4':
					cin>>want1>>want2>>want3>>want4;//
					getcard.push_back(player[want1]);//
					getcard.push_back(player[want2]);
					getcard.push_back(player[want3]);
					getcard.push_back(player[want4]);
					break;
			case 'P':
				return -1;
			case 'p':
				return -1;
	}
	check(getcard);
	if(check){
		getcard.clear();
		goto step2;
	}
	step3 : 
		for(int i=0;i<getcard.size();i++){
			if(getcard[i]>maxscore)
			maxscore=getcard[i];	
		}
		if(getcard.size()==2)
		maxscore+=100;
		else if(getcard.size()==3)
		maxscore+=200;
		else if(getcard.size()==4)
		maxscore+=300;
	step4 :
		if(maxscore>topscore)
		topscore=maxscore;
		maxscore=0;
		else goto step1;
return topscore;
}

		
int main(){
//drawScreen;
	bool passall=true;
	int state=1,;
	int game_count=1;
	int round_count=1;
	int turn_count=1;
	
	while(true){
		while(finishround){
			while(passall){
			//drawScreen;	
				if(state==1){
					while(pass1!=-1)topscorenew=setcard(turn_count,totle,p1,topscoreold);
						if(topscorenew==-1){
							pass++;	
							pass1=-1;
						}
						else topscoreold=topscorenew;
					state=2;
				}
				else if(state==2){
					while(pass2!=-1)topscorenew=setcard(turn_count,totle,p2,topscoreold);
						if(topscorenew==-1){
							pass2=-1;
							pass++;
						}
						else topscoreold=topscorenew;
					if(numplayer>2)state=3;
					else state=1;
				}
				else if(state==3){
					while(pass3!=-1)topscorenew=setcard(turn_count,totle,p3,topscoreold);
						if(topscorenew==-1{
							pass++;
							pass3=-1;
						}
						else topscoreold=topscorenew;
					if(numplayer==4)
						state=4;
					else state=1;
				}
				else if(state==4){
					while(pass4!=-1)topscorenew=setcard(turn_count,totle,p4,topscoreold);
						if(topscorenew==-1){	
							pass4=-1;
							pass++;
						}
						else topscoreold=topscorenew;
					state=1;
				}
			turn_count++;
			if(pass=numplayer-1) passall=false;
			}
		passall=true;	
		topscoreold=0;
		round_count++;
		}
	cout<<"CONTINUE [C] or EXIT [E] "; 
	cin>>player_action;
	if(player_action=='E' or player_action=='e')break;
	game_count++;
	}

		
	return 0;
}
