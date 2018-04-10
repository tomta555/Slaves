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
//	if(num==2){
		Player p1(name[0],c1.cards,c1.faceShuff,0,26);
		Player p2(name[1],c1.cards,c1.faceShuff,26,52);	
//	
//	}else if(num==3){ 
//		Player p1(name[0],c1.cards,c1.faceShuff,0,17);
//		Player p2(name[1],c1.cards,c1.faceShuff,17,34);
//		Player p3(name[2],c1.cards,c1.faceShuff,34,52); //  1 more card than other
//	}else if(num==4){
//		Player p1(name[0],c1.cards,c1.faceShuff,0,13);
//		Player p2(name[1],c1.cards,c1.faceShuff,13,26);
//		Player p3(name[2],c1.cards,c1.faceShuff,26,39);
//		Player p4(name[3],c1.cards,c1.faceShuff,39,52);
//	}
	
//	vector<int> cax=p1.GetCard();
//	for(int i=0;i<26;i++){
//		cout << cax[i] << " ";
//	}
//	cout << endl;
//	vector<string> caf=p1.GetFace();
//	for(int i=0;i<26;i++){
//		cout << caf[i] << " ";
//	}
//	cout << endl;
//		vector<int> cax2=p2.GetCard();
//	for(int i=0;i<26;i++){
//		cout << cax2[i] << " ";
//	}
//	cout << endl;
//	vector<string> caf2=p2.GetFace();
//	for(int i=0;i<26;i++){
//		cout << caf2[i] << " ";
//	}

	
	
	
	

	
	return 0;
}
