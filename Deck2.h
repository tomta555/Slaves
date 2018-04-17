#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<cstdlib>

using namespace std;

class Deck{ 
		
	public:
		vector<int> cards;
		vector<string> cardFace;
		vector<string> faceShuff;
		Deck();
		void ShuffleCard();
		void ShuffleFace();
//		vector<string> GetDeckFace();
};
Deck::Deck(){
	string vectmp[52]={"3\5","3\4","3\3","3\6","4\5","4\4","4\3","4\6","5\5","5\4","5\3","5\6","6\5","6\4","6\3","6\6","7\5","7\4","7\3","7\6","8\5","8\4","8\3","8\6",
	"9\5","9\4","9\3","9\6","10\5","10\4","10\3","10\6","J\5","J\4","J\3","J\6","Q\5","Q\4","Q\3","Q\6","K\5","K\4","K\3","K\6","A\5","A\4","A\3","A\6","2\5","2\4","2\3","2\6"};
	
	cardFace.assign(&vectmp[0], &vectmp[0]+52);
	
	for(int i=0;i<52;i++){
		cards.push_back(i);
	}
}
void Deck::ShuffleCard(){
		random_shuffle(cards.begin(),cards.end());
	}

void Deck::ShuffleFace(){
	for(int i=0;i<52;i++){	
		faceShuff.push_back(cardFace[cards[i]]);
	}
}
//vector<string> Deck::GetDeckFace(){
//	return cardFace;
//}

class Player{
	string name;
	string type;
	int cardcount,cardcountcst;
	vector<string> allfaces;
	vector<int> plcards;
	vector<string> plfaces;
	vector<int> sortedcards;
	vector<string> sortedfaces;
	public:
		
		Player(string,vector<string>,vector<int>,vector<string>,int,int);
		bool plpass;
		vector<int> GetCard();
		vector<string> GetFace();
		bool isWin();
		bool isEmptyHand();
		void sortcard();
		void sortface();
		void eraseCard(int);
		void decCardCount();
		void pass();
		void newturn();
//		vector<int> GetCardd();
//		vector<string> GetFaced();
};
Player::Player(string n,vector<string> af ,vector<int> c, vector<string> f,int first,int last){
	allfaces = af;
	name = n;
	type = "People";
	plpass=false;
	cardcountcst=last-first;
	cardcount=last-first;
	for(int i=first;i<last;i++){
		plcards.push_back(c[i]);
		plfaces.push_back(f[i]);
	}
	sortedcards=plcards;
}
void Player::pass(){
	plpass=true;
}
void Player::newturn(){
	plpass=false;
}
void Player::sortcard(){
	sort(sortedcards.begin(),sortedcards.end());
}
void Player::sortface(){
	for(int i=0;i<cardcountcst;i++){
		sortedfaces.push_back(allfaces[sortedcards[i]]);
	}
}
void Player::eraseCard(int idx){
	vector<int>::iterator loc;
	int faceIndex;
	loc=find(sortedcards.begin(),sortedcards.end(),idx);
	faceIndex=distance(sortedcards.begin(),loc);
	sortedcards.erase(loc);
	sortedfaces.erase(sortedfaces.begin()+faceIndex); 
}
void Player::decCardCount(){
	cardcount--;
}
//vector<int> Player::GetCardd(){
//	vector<int> Pcards = plcards;
//	return Pcards;
//}
//vector<string> Player::GetFaced(){
//	vector<string> PcardFace = plfaces;
//	return PcardFace;
//}
vector<int> Player::GetCard(){
	vector<int> Pcards = sortedcards;
	return Pcards;
}
vector<string> Player::GetFace(){
	vector<string> PcardFace = sortedfaces;
	return PcardFace;
}
bool Player::isWin(){
	if(cardcount == 0){
		type = "King";
		return true;	
	}else return false;	
}
bool Player::isEmptyHand(){
	if(cardcount == 0){
		type = "People";
		return true;	
	}else return false;	
}
