#include <iostream>
#include <string>
#include <fstream>
#include "simpio.h"
#include "random.h"
#include "console.h"
#include "foreach.h"
#include <time.h>
#include "lexicon.h"
#include "Vector.h"
#include "Set.h"
#include "Queue.h"
#include "islands.h"
#include "treeToList.h"


using namespace std;

int numIslandsSol(Grid<int> g);
void getRandomNodes(int size, Vector<nodeT *> &nodes);
void buildTree(nodeT * &root, Vector<nodeT *> &nodes);
void flattenSol(nodeT* root);
void builtRandomMap(Grid<int> &g, int &answ, int size);

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

void readBinaryTree(nodeT * &r, ifstream &input, Vector<nodeT *> &answ) {
	int n;
	input >> n;
	int w, v;
	for (int i=0; i<n; i++) {
		input >> v >> w;
		nodeT * node = insertNode(r, v, w);
		answ.add(node);
	}
}

void readTreeTest(nodeT * &root, Vector<nodeT *> &answ, int testNum) {
	string testFileName = string("flatten\\test") + integerToString(testNum) + ".txt";
	root = NULL;
	ifstream input;
	input.open(testFileName.c_str());
	readBinaryTree(root, input, answ);
	clearWeights(root);
	input.close();
}

bool isCorrectTree(nodeT* root, Vector<nodeT *> answ) {
	int size = 0;
	while (root != NULL) {
		if (root != answ[size++] || root->left != NULL) {
			return false;
		}
		root = root->right;
	}
	
	return size == answ.size();
}

void readGraphGrid(Grid<int> &g, int &answ, int testNum) {
	string testFileName = string("islands\\test") + integerToString(testNum) + ".txt";
	ifstream input;
	input.open(testFileName.c_str());
	int n, m;
	input >> n >> m >> answ;
	g.resize(n, m);
	string line;
	for (int i=0; i<g.numRows(); i++) {
		input >> line;
		for (int j=0; j<g.numCols(); j++) {
			g[i][j] = line[j] - '0';
		}
	}
	input.close();
}

void testIslands() {
	cout << "### Testing Islands view ###" << endl;
	int testNum = 0;
	int passed = 0;
	Grid<int> g;
	int answ, res;
	for (int i=1; i<=40; i++) {
		builtRandomMap(g, answ, i+9);
		res = numIslands(g);
		bool isCorrect = res == answ;
		printTestResults(isCorrect, testNum, passed);
	}

	cout << "passed: " << passed << endl;
}

void testFlatten() {
	cout << "### Testing Flatten ###" << endl;
	int testNum = 0;
	int passed = 0;

	Vector<nodeT *> nodes;
	Vector<nodeT *> answ;
	nodeT * root;
	for (int i=1; i<=40; i++) {
		answ.clear();
		getRandomNodes(i*50, nodes);
		root = NULL;
		buildTree(root, nodes);
		flatten(root);
		while (root != NULL) {
			answ.add(root);
			root = root->right;
		}
		
		buildTree(root, nodes);
		flattenSol(root);
		printTestResults(isCorrectTree(root, answ), testNum, passed);
	}
	cout << "passed: " << passed << endl;	
}

int main() {
	setRandomSeed(0);
	testIslands();
	testFlatten();
	return 0;
}

struct pointT {
	int row;
	int col;
};
int numIslandsSol(Grid<int> g) {
	int res = 0;
	for (int i=0; i<g.numRows(); i++) {
		for (int j=0; j<g.numCols(); j++) {
			if (g[i][j] == 1) {
				res++;
				Queue<pointT> q;
				pointT p;
				p.row = i;
				p.col = j;
				q.enqueue(p);
				while (!q.isEmpty()) {
					p = q.dequeue();
					g[p.row][p.col] = 2;
					for (int dx=-1; dx<2; dx++) {
						for (int dy=-1; dy<2; dy++) {
							if (dx * dy != 0) {
								continue;
							}
							pointT newp;
							newp.row = p.row+dx;
							newp.col = p.col+dy;
							if (g.inBounds(newp.row, newp.col) && g[newp.row][newp.col] == 1) {
								q.enqueue(newp);
							}
						}
					}
				}
			}
		}
	}	
	return res;
}
void builtRandomMap(Grid<int> &g, int &answ, int size) {
	g.resize(size, size);
	for (int i=0; i<g.numRows(); i++) {
		for (int j=0; j<g.numCols(); j++) {
			g[i][j] = randomChance(0.5) ? 0 : 1;
		}
	}
	answ = numIslandsSol(g);
}
nodeT* insertNodePointer(nodeT * &root, nodeT * node) {
	if (root == NULL) {
		root = node;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	if (root->weight < node->weight) {
		return insertNodePointer(root->right, node);
	} else {
		return insertNodePointer(root->left, node);
	}
}

void getRandomNodes(int size, Vector<nodeT *> &nodes) {
	for (int i=0; i<size; i++) {
		nodeT * n = new nodeT;
		n->left = NULL;
		n->right = NULL;
		n->v = 0;
		n->weight = randomInteger(0, 100000000);
		nodes.add(n);
	}
}

void buildTree(nodeT * &root, Vector<nodeT *> &nodes) {
	for (int i=0; i<nodes.size(); i++) {
		insertNodePointer(root, nodes[i]);
	}
}

void flattenSolRec(nodeT* root, nodeT** arr, int &indx) {
    if (root == NULL)
        return;
    
    arr[indx] = root;
    indx++;
    flattenSolRec(root->left, arr, indx);
    flattenSolRec(root->right, arr, indx);
}

int flattenSolTreeSize(nodeT* root) {
    if (root == NULL) 
        return 0;
    
    return flattenSolTreeSize(root->left) + flattenSolTreeSize(root->right) + 1;
}

void flattenSol(nodeT* root) {
    if (root == NULL)
        return;
    int indx = 0;
    int size = flattenSolTreeSize(root);
    nodeT ** arr = new nodeT*[size];

    flattenSolRec(root, arr, indx);
    int i=0;
    for (; i<size-1; i++) {
        arr[i]->right = arr[i+1];
        arr[i]->left = NULL;
    }
    arr[i]->right = NULL;
    arr[i]->left = NULL;
}
