#include "pairs.h"
#include "set.h"
#include "strlib.h"
#include "set.h"



/*

void findMaxPairs(Grid<bool> &likes, int &max, Set <int> &checked, Set<int> &used, int curMax){


	if(curMax > max)max = curMax;
	if(checked.size()==likes.nCols)return;
	for(int i = 0; i < likes.nCols; i++){
		for(int j = 0; j < likes.nRows; j++){
			if(!checked.contains(i) && !checked.contains(j)  && i != j && likes[i][j] && likes[j][i]){
				checked.add(i);
				used.add(i);
				used.add(j);
				curMax+=1;
				findMaxPairs(likes, max, checked, used, curMax);
			
				used.remove(i);
				used.remove(j);
				curMax-=1;
				findMaxPairs(likes, max, checked, used, curMax);
			}
		}
	}
	
}



int maxPairs(Grid<bool> &likes) {
	Set <int> used;
	Set <int> checked;
	int Max = -1;
	int n = 0;
	findMaxPairs(likes, Max, checked, used, 0);
	
	return Max;
	return 1;
}

*/

/////////////////////////////chemi


void getLikes(Grid<bool> &likes, int num, Set<int> used, Set<int> pairs, int &maxN){
	if(maxN<num) maxN=num;
	if(used.size()==likes.numCols()) return;

	for(int i=0; i<likes.numRows(); i++){
		for(int j=0; j<likes.numCols(); j++){
			if(likes[i][j] && likes[j][i]&& !pairs.contains(i) &&!pairs.contains(j)) {
				pairs.add(i);
				pairs.add(j);
				used.add(i);
				used.add(j);
				getLikes(likes,num++,used,pairs,maxN);
				used.remove(i);
				used.remove(j);
				pairs.remove(i);
				pairs.remove(j);
			}
					
}
	}
}


int maxPairs(Grid<bool> &likes){
Set<int>used;
Set<int>pairs;
int num=0;
int maxN=-1;
getLikes(likes, num,used,pairs,maxN);

	return maxN;
	}
