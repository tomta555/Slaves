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
};
Deck::Deck(){
	string vectmp[52]={"3\5","3\4","3\3","3\6","4\5","4\4","4\3","4\6","5\5","5\4","5\3","5\6","6\5","6\4","6\3","6\6","7\5","7\4","7\3","7\6","8\5","8\4","8\3","8\6",
	"9\5","9\4","9\3","9\6","10\5","10\4","10\3","10\6","J\5","J\4","J\3","J\6","Q\5","Q\4","Q\3","Q\6","K\5","K\4","K\3","K\6","A\5","A\4","A\3","A\6","2\5","2\4","2\3","2\6"};
	for(int i=0;i<52;i++){
		cards.push_back(i);
	}
	cardFace.assign(&vectmp[0], &vectmp[0]+52);
}
void Deck::ShuffleCard(){
	vector<int> x;
		random_shuffle(cards.begin(),cards.end());
	}

void Deck::ShuffleFace(){
//	vector<string> faceShuff;
	for(int i=0;i<52;i++){	
		faceShuff.push_back(cardFace[cards[i]]);
	}

}

class Player{
	string name;
	string type;
	int cardcount;
	vector<int> cardOrder;
	vector<int> allcards;
	vector<string> allfaces;	
	public:
		Player(string,vector<int>,vector<string>,int,int);
		bool isKing();
		bool isEmptyHand();
		vector<int> GetCard();
		vector<string> GetFace();
};
Player::Player(string n,vector<int> c, vector<string> f,int first,int last){
	name = n;
	for(int i=first;i<last;i++){
//		cardOrder.push_back(i);
		allcards.push_back(c[i]);
		allfaces.push_back(f[i]);
	}
}
vector<int> Player::GetCard(){
	vector<int> Pcards = allcards;
	return Pcards;
}
vector<string> Player::GetFace(){
	vector<string> PcardFace = allfaces;
	return PcardFace;
}
//bool Player::isKing(){
//	if(cardcount == 0){
//		type = "King";
//		return true;	
//	}else return false;	
//}
//bool isEmptyHand(){
//	if(cardcount == 0){
//		type = "People";
//		return true;	
//	}else return false;	
//}
