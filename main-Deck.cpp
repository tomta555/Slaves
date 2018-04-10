#include <iostream>
#include "Deck2.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	srand(unsigned(time(NULL)));
	int num;
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
		Player p1(name[0],c1.cardFace,c1.cards,c1.faceShuff,0,26);
		Player p2(name[1],c1.cardFace,c1.cards,c1.faceShuff,26,52);
			p1.sortcard();
			p1.sortface();
			p2.sortcard();
			p2.sortface();
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



//      print    shuffle      cards
//	vector<int> caxx=p1.GetCardd();
//	for(int i=0;i<26;i++){
//		cout << caxx[i] << " ";
//	}
//	cout << endl;
//	vector<string> caff=p1.GetFaced();
//	for(int i=0;i<26;i++){
//		cout << caff[i] << " ";
//	}
//	cout << endl;
	
//      print     sort       cards

//	vector<int> cax=p1.GetCard();
//	for(int i=0;i<17;i++){
//		cout << cax[i] << " ";
//	}
//	cout << endl;
//	vector<string> caf=p1.GetFace();
//	for(int i=0;i<17;i++){
//		cout << caf[i] << " ";
//	}
//	cout << endl;
//	vector<int> caxx=p2.GetCard();
//	for(int i=0;i<17;i++){
//		cout << caxx[i] << " ";
//	}
//	cout << endl;
//	vector<string> caff=p2.GetFace();
//	for(int i=0;i<17;i++){
//		cout << caff[i] << " ";
//	}
//	cout << endl;
//	vector<int> caxxx=p3.GetCard();
//	for(int i=0;i<18;i++){
//		cout << caxxx[i] << " ";
//	}
//	cout << endl;
//	vector<string> cafff=p3.GetFace();
//	for(int i=0;i<18;i++){
//		cout << cafff[i] << " ";
//	}
//	cout << endl;



	
	
	
	

	
	return 0;
}
