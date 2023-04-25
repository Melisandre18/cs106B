#include "change.h"
bool possibleChange(Vector<int>&v, int cash){
	if(cash==0) return true;
	if(cash<0) return false;
	for(int i=0; i<v.size(); i++){
		if(possibleChange(v,cash-v.get(i))) return true;
	}
	return false;
};


bool giveChange(Vector<int> &cshBills, Vector<int> &cstBills, int price) {
	Vector<int>vec=cshBills+cstBills;
	return possibleChange(vec,price);
}
