#include "pairsSol.h"
#include "set.h"
#include "strlib.h"

/*
string pairs;

void maxPairsRec(Grid<bool> &likes, Set<int> &paired, int &max, string str) {
	if (max < paired.size() / 2) {
		max = paired.size() / 2;
		pairs = str;
	}
	for (int i=0; i<likes.numRows(); i++) {
		for (int j=0; j<likes.numRows(); j++) {
			if (likes[i][j] && likes[j][i] && !paired.contains(i) && !paired.contains(j)) {
				paired.add(i);
				paired.add(j);
				maxPairsRec(likes, paired, max, str + integerToString(i) + "<>" + integerToString(j) + ",");
				paired.remove(i);
				paired.remove(j);
			}
		}
	}
}

int maxPairsSol(Grid<bool> &likes) {
	int max = 0;
	Set<int> s;
	maxPairsRec(likes, s, max, "");
	//cout << "pairs: " << pairs << endl;
	return max;
}
*/

