#include "cyclemin.h"
#include <iostream>
#include <string>
#include <fstream>
#include "set.h"
#include "stack.h"
#include "queue.h"
#include "vector.h"
#include "simpio.h"
#include "console.h"
#include "random.h"


void dfs(Vector<edgeT *> &g, edgeT* startNode, int &num){
	Set<int> visitedNodes;
	Stack<edgeT *> toVisit;
	Vector<edgeT *> match;
	toVisit.push(startNode);
	while(!toVisit.isEmpty()) {
		edgeT* nextNode = toVisit.pop();
		if (!visitedNodes.contains(nextNode->weight)) {
			visitedNodes += nextNode->weight;
			if(!toVisit.contains(nextNode->from) toVisit.push(nextNode->from);
			if(!toVisit.contains(nextNode->to)toVisit.push(nextNode->to);
		} else {
			g.remove(nextNode->weight);
		    num=nextNode->weight;
		    dfs(g,g[0],num);
		}
	}
}

int removeCycleMin(Vector<edgeT *> &g) {
     int num=-1;
	dfs(g,g[0],num);
	return num;
}