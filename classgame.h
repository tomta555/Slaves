#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<algorithm>

using namespace std;
class game{
		int topscore;
	public	
		bool pass();
		void passturn();
		void newround();
};

void game::newround(){
	pass = true;
}

void game::passturn(){
	pass = false;
}
