#include <iostream>
#include <string>
#include <fstream>
#include "simpio.h"
#include "random.h"
#include "console.h"
#include "vector.h"
#include "foreach.h"
#include <time.h>
#include "lexicon.h"
#include "Set.h"
#include "Map.h"
#include "cyclemax.h"
#include "rightview.h"
#include <sys/types.h>
#include <sys/timeb.h>
#include <ctime>

using namespace std;

long long currTimeMs() {
	struct _timeb timebuffer;
	_ftime64_s( &timebuffer );
	time_t time;
	unsigned short millitm;
    time = timebuffer.time;
    millitm = timebuffer.millitm;

	long long timeInMs = time*1000 + millitm;
	return timeInMs;
}


void printTestResults(bool passed, int & testNum, int & passedCounter) {
	testNum++;
	if (passed) {
		cout << "test " << testNum << " passed" << endl;
		passedCounter++;
	} else {
		cout << "test " << testNum << " failed" << endl;
	}
}

void clearWeights(nodeT * root) {
	if (root == NULL) {
		return;
	}
	root->weight = 0;
	clearWeights(root->left);
	clearWeights(root->right);
}

nodeT* insertNode(nodeT * &root, int value, int weight) {
	if (root == NULL) {
		root = new nodeT;
		root->v = value;
		root->weight = weight;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	if (root->weight < weight) {
		return insertNode(root->right, value, weight);
	} else {
		return insertNode(root->left, value, weight);
	}
}

void generateRandomTree(nodeT * &r, int size) {
	r = NULL;
	for (int i=0; i<size; i++) {
		int v = randomInteger(0, 10000);
		int w = randomInteger(0, 1000000000);
		nodeT * node = insertNode(r, v, w);
	}
}

void readBinaryTree(nodeT * &r, ifstream &input, Vector<nodeT *> &answ) {
	int n;
	input >> n;
	int w, v;
	for (int i=0; i<n; i++) {
		input >> v >> w;
		nodeT * node = insertNode(r, v, w);
		if (w % 10 == 1) {
			answ.add(node);
		}
	}
}

void readTreeTest(nodeT * &root, Vector<nodeT *> &answ, int testNum) {
	string testFileName = string("rightview1\\test") + integerToString(testNum) + ".txt";
	root = NULL;
	ifstream input;
	input.open(testFileName.c_str());
	readBinaryTree(root, input, answ);
	clearWeights(root);
	input.close();
}

bool isEqualVector(Vector<nodeT *> v1, Vector<nodeT *> v2) {
	if (v1.size() != v2.size()) {
		return false;
	}
	for (int i=0; i<v1.size(); i++) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}


void testRightView() {
	cout << "### Testing Tree Right View###" << endl;
	int testNum = 0;
	int passed = 0;

	nodeT * root;
	Vector<nodeT *> res;
	Vector<nodeT *> answ;
	for (int i=1; i<=10; i++) {
		answ.clear();
		readTreeTest(root, answ, i);
		res = rightView(root);
		bool isCorrect = isEqualVector(res, answ);
		printTestResults(isCorrect, testNum, passed);
	}

	//Test O(n*log(n))
	int initialSize = 1000;
	int mult = 64;
	long long startTime;
	long long timeElapsed1, timeElapsed2;
	generateRandomTree(root, initialSize);
	startTime = currTimeMs();
	res = rightView(root);
	timeElapsed1 = currTimeMs() - startTime + 2;

	generateRandomTree(root, mult*initialSize);
	startTime = currTimeMs();
	res = rightView(root);
	timeElapsed2 = currTimeMs() - startTime;

	if (timeElapsed1 <= timeElapsed2 / (mult*8)) {
		cout << "#### NOT O(n*log(n))! ####" << endl;
	}

	cout << "passed: " << passed << endl;
}

void readGraph(Grid<int> &g, ifstream &input, int &answ) {
	int n, m;
	input >> n >> m >> answ;
	g.resize(m, m);
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			g[i][j] = -1;
		}
	}
	for (int i=0; i<n; i++) {
		int from, to, weight;
		input >> from >> to >> weight;
		g[from][to] = weight;
		g[to][from] = weight;
	}
}

void readGraphTest(Grid<int> &g, int &answ, int testNum) {
	string testFileName = string("cycle1\\test") + integerToString(testNum) + ".txt";
	ifstream input;
	input.open(testFileName.c_str());
	readGraph(g, input, answ);
	input.close();
}



void testCycle() {
	cout << "### Testing Cycle ###" << endl;
	int testNum = 0;
	int passed = 0;
	int answ;
	Grid<int> g;
	for (int i=1; i<=10; i++) {
		readGraphTest(g, answ, i);
		int res = removeCycleMax(g);
		bool isCorrect = res == answ;
		printTestResults(isCorrect, testNum, passed);
	}
	cout << "passed: " << passed << endl;	
}

int main() {
	setRandomSeed(1);
	testRightView();
	testCycle();
	return 0;
}