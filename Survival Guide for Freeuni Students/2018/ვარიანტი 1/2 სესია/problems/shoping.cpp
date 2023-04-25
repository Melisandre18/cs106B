#include "shoping.h"

/*
int getMaxWeight(Vector<item> &items, int cap1, int cap2, int money, int weight){
	if( money < 0 || cap1 < 0 || cap2 < 0) return 0;
	if(items.isEmpty()) return weight;
	int temp;
	item it = items[items.size() - 1];
	items.remove(items.size() - 1);
	int res1 = getMaxWeight(items, cap1 - it.weight, cap2, money - it.price, weight+it.weight);
	int res2 = getMaxWeight(items, cap1, cap2-it.weight, money - it.price, weight + it.weight);
	int res3 = getMaxWeight(items, cap1, cap2, money, weight);
	items.add(it);
	return max(res1,max(res3,res2));
}



int findBestComb(Vector<item> &items, Vector<bag> &bags, int money) {
	int ans  = 0;
	for(int i = 0; i < bags.size()-1; i++){
		for(int j = 0 ; j < bags.size(); j++){
			int moneyLeft = money - bags[i].price - bags[j].price;
			if( moneyLeft > 0)
				ans = max(ans, getMaxWeight(items, bags[i].cap, bags[j].cap, moneyLeft, 0));
		}
	}
	return ans;
}


*/





int getMax(Vector<item> &items, int  one, int  two, int mon, int c){
	if(mon<0 ||one<0 || two<0) return 0;
	if(items.isEmpty()) return c;
	item it =items[items.size()-1];
	items.remove(items.size()-1);
	int first= getMax(items, one-it.weight, two, mon-it.price, c+it.weight);
	int second= getMax(items, one, two-it.weight, mon-it.price, c+it.weight);
	int third= getMax(items, one, two, mon, c);
	items.add(it);
   return max(first, max(second,third));
}



int findBestComb(Vector<item> &items, Vector<bag> &bags, int money) {
	int ans=0;
	for(int i=0; i<bags.size()-1; i++){
		for(int j=0; j<bags.size(); j++){
			int mon=money-(bags[i].price)-(bags[j].price);
			
				ans= max(ans,getMax(items, bags[i].cap, bags[j].cap, mon, 0));
			
			
	  }
	}
	return ans;
}
