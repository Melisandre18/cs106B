#include "change.h"
#include "foreach.h"

/*
int countChange(Vector<int> &cstBills, int price){
	int payed = 0;
	if(!cstBills.isEmpty()){
		for(int i = 0; i < cstBills.size(); i++){
			payed += cstBills[i];
		}
	}
	int res = payed - price;
	return res;
}

bool isPossible(Vector<int> &cshBills, int neededChange){
	if(neededChange < 0 )return false;
	if(neededChange==0){
		return true;
	}else{
		for(int i = 0; i < cshBills.size(); i++){
			int n = cshBills[i];
			if(n > neededChange)
			cshBills.remove(i);
			if(isPossible(cshBills, neededChange-n)){
				return true;
			}else{
				return isPossible(cshBills, neededChange);
			}
		}
	}
return false;
}
void removeUnnecessaryBills(Vector<int> &cshBills, int neededChange){
	if(!cshBills.isEmpty()){
		for(int i = 0; i < cshBills.size(); i++){
			if(cshBills[i] > neededChange){
				cshBills.remove(i);
			}
		}
	}
}


bool giveChange(Vector<int> &cshBills, Vector<int> &cstBills, int price) {
	int neededChange = countChange(cstBills, price);
	if(neededChange < 0) return false; 
	cshBills += cstBills;
	
	removeUnnecessaryBills(cshBills, neededChange);

	bool res = isPossible(cshBills, neededChange);
	return res;
}
*/
/*

bool getC(Vector<int> &cshBills, Vector<int> &vec, int left){
	if(left==0) return true;
}




bool giveChange(Vector<int> &cshBills, Vector<int> &cstBills, int price){
	Vector<int>vec;
	for(int i=0; i<cstBills.size(); i++){
		int n=cstBills.get(i)-price;
		if(n>=0) vec.add(n);
		else vec.add(n*-1);
	}
	return false;
}*/
