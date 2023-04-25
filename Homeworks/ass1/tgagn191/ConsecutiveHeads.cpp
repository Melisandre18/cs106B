/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Consecutive Heads problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "random.h"
using namespace std;

int flipNum(){
	int heads=0;
	int tails=0;
	int num=0;
	while(true){
	int ran=randomInteger(0,1);
	if(ran==0){
		tails=0;
		heads++;
		num++;
		cout<<"heads"<<endl;
	}else{
		tails++;
		num++;
		cout<<"tails"<<endl;
	}
	if(tails>0&&heads>0) heads=0;
	if(heads==3) break;
	}
	return num;
};
int main() {
    cout<<"It took "<<flipNum()<<" flips to get 3 consecutive heads"<<endl;
    return 0;
}
