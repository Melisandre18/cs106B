#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
#include "vector.h"
#include "queue.h"
#include <time.h>
#include "lexicon.h"
#include "pairs.h"
#include "change.h"
#include "changeSol.h"
#include "random.h"
//#include "pairsSol.h"


using namespace std;

void clearGrid(Grid<bool> &likes, bool value = false) {
	for (int i=0; i<likes.numRows(); i++) {
		for (int j=0; j<likes.numCols(); j++) {
			likes[i][j] = value;
		}
	}
}
void fillGrid(Grid<bool> &likes, int pairs[][2], int len, bool value = true) {
	for (int i=0; i<len; i++) {
		likes[pairs[i][0]][pairs[i][1]] = value;
	}
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

bool checkOposite(bool b) {
	Vector<int> csh;
	Vector<int> cst;
	if (b) {
		csh += 100, 100, 100;
		cst += 100, 100, 100;
	} else {
		csh += 102, 2, 8;
		cst += 35, 30, 1, 3, 7;
	}
	return !b == giveChange(csh, cst, 2);
}

void generateRandomTest(Vector<int> &csh, Vector<int> &cst, int &amount) {
	csh.clear();
	cst.clear();
	amount = randomInteger(1, 20);
	int l = randomInteger(1, 15);
	for (int i=0; i<l; i++) {
		csh += randomInteger(1, 25);
	}
	l = randomInteger(1, 15);
	for (int i=0; i<l; i++) {
		cst += randomInteger(1, 25);
	}
	//cout << amount << endl;
	//cout << cst.toString() << endl;
	//cout << csh.toString() << endl;
}

void runChangeTests() {
	cout << "### Run Change tests ###" << endl;
	bool res;
	int testNum = 0;
	int passedNum = 0;
	Vector<int> cshBills;
	Vector<int> cstBills;
	//#1
	cstBills += 15, 30, 120, 5, 3;
	res = giveChange(cshBills, cstBills, 23);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#2
	cshBills.clear();
	cstBills.clear();
	cstBills += 35, 30, 1, 3, 7;
	cshBills += 102, 2, 8;
	res = giveChange(cshBills, cstBills, 55);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#3
	cshBills.clear();
	cstBills.clear();
	cstBills += 2, 3, 7, 100;
	cshBills += 3, 10, 1;
	res = giveChange(cshBills, cstBills, 4);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#4
	cshBills.clear();
	cstBills.clear();
	cstBills += 1, 13, 17, 22, 10;
	cshBills += 3, 7, 15;
	res = giveChange(cshBills, cstBills, 26);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#5
	cshBills.clear();
	cstBills.clear();
	cstBills += 1, 13, 18, 22, 10;
	cshBills += 3, 7, 15, 27;
	res = giveChange(cshBills, cstBills, 39);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#6
	cshBills.clear();
	cstBills.clear();
	cstBills += 100, 140, 160, 180, 200, 240, 340;
	cshBills += 3, 7, 15, 27, 30, 48;
	res = giveChange(cshBills, cstBills, 339);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#7
	cshBills.clear();
	cstBills.clear();
	cstBills += 100, 140, 160, 180, 200, 240, 340;
	cshBills += 3, 7, 15, 27, 30, 48;
	res = giveChange(cshBills, cstBills, 339);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#8
	cshBills.clear();
	cstBills.clear();
	cstBills += 107, 140, 160, 180, 200, 240, 340;
	cshBills += 3, 7, 15, 27, 30, 50;
	res = giveChange(cshBills, cstBills, 339);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#9
	cshBills.clear();
	cstBills.clear();
	cstBills += 10, 140, 160, 180, 200, 240, 340, 400, 430, 32;
	cshBills += 7, 15, 27, 30, 50, 3;
	res = giveChange(cshBills, cstBills, 29);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#10
	cshBills.clear();
	cstBills.clear();
	cstBills += 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2056;
	cshBills += 12, 14, 26, 48, 52, 1052;
	res = giveChange(cshBills, cstBills, 17);
	printTestResults(res == false && checkOposite(false), testNum, passedNum);
	//#11
	cshBills.clear();
	cstBills.clear();
	cstBills += 1001, 1000, 120, 160, 180, 1, 1, 1, 1, 1, 1;
	cshBills += 102, 200, 300, 800, 2500, 2300, 1200, 1400, 1004;
	res = giveChange(cshBills, cstBills, 7);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#12
	cshBills.clear();
	cstBills.clear();
	cstBills += 5, 5, 5, 5, 5, 5, 24;
	cshBills += 1, 1, 1, 1;
	res = giveChange(cshBills, cstBills, 50);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);
	//#13
	cshBills.clear();
	cstBills.clear();
	cstBills += 13, 227, 38, 101, 180, 204, 288, 128, 208, 13;
	cshBills += 10000, 10011, 1, 1, 5, 5;
	res = giveChange(cshBills, cstBills, 20);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);

	//#14
	cshBills.clear();
	cstBills.clear();
	cstBills += 1, 10, 17, 28, 58, 60, 35, 70, 75;
	cshBills += 1, 1, 3, 100, 20, 6, 102, 84, 56, 10, 5, 5, 5, 5, 5;
	res = giveChange(cshBills, cstBills, 310);
	printTestResults(res == true && checkOposite(true), testNum, passedNum);

	//#15
	cshBills.clear();
	cstBills.clear();
	cstBills += 1, 10, 17, 28, 40, 58, 60, 35, 70, 75;
	cshBills += 1, 1, 3, 100, 20, 6, 84, 56, 10, 5, 5;
	res = giveChange(cshBills, cstBills, 710);
	printTestResults(res == false && checkOposite(false), testNum, passedNum);

	for (int i=0; i<35; i++) {
		int am = 0;
		generateRandomTest(cshBills, cstBills, am);
		bool rightSol = giveChange(cshBills, cstBills, am);
		res = giveChange(cshBills, cstBills, am);
		printTestResults(res == rightSol && checkOposite(false), testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}

void generateRandomGrid(Grid<bool> &likes) {
	int size = randomInteger(6, 14);
	likes.resize(size, size);
	clearGrid(likes);	
	int connNum = randomInteger(2*size, 6*size);
	for (int i=0; i<connNum; i++) {
		int k = randomInteger(0, size) % size;
		int p = randomInteger(0, size) % size;
		if (k != p) {
			likes[k][p] = true;
		}
	}
}

void runPairsTests() {
	cout << "### Run Pairs tests ###" << endl;
	int testNum = 0;
	int passedNum = 0;
	int res = 0;
	Grid<bool> likes;
	//#1
	likes.resize(3, 3);
	clearGrid(likes);
	//{0, 1} pair means that person with number 0 likes person with number 1
	int arr1[3][2] = {{1, 0}, {1, 2}, {2, 0}};
	fillGrid(likes, arr1, 3);
	res = maxPairs(likes);
	printTestResults(res == 0, testNum, passedNum);
	//#2
	likes.resize(3, 3);
	clearGrid(likes);
	int arr2[6][2] = {{0, 1}, {2, 0}, {0, 2}, {1, 2}, {2, 1}, {1, 0}};
	fillGrid(likes, arr2, 6);
	res = maxPairs(likes);
	printTestResults(res == 2, testNum, passedNum);
	//#3
	likes.resize(4, 4);
	clearGrid(likes);
	int arr3[9][2] = {
		{0, 1}, {1, 0}, {0, 3}, {3, 0}, {0, 2}, {1, 2}, {2, 1}, {1, 3}, 
		{3, 2}};
	fillGrid(likes, arr3, 9);
	res = maxPairs(likes);
	printTestResults(res == 2, testNum, passedNum);
	//#4
	likes.resize(6, 6);
	clearGrid(likes);
	int arr4[10][2] = {
		{0, 1}, {1, 0}, {0, 3}, {3, 0}, {1, 2}, {2, 1}, {1, 4}, {4, 1}, 
		{2, 5}, {5, 2}};
	fillGrid(likes, arr4, 10);
	res = maxPairs(likes);
	printTestResults(res == 3, testNum, passedNum);
	//#5
	likes.resize(8, 8);
	clearGrid(likes);
	int arr5[18][2] = {
		{0, 1}, {1, 0}, {0, 2}, {2, 0}, {0, 3}, {3, 0}, {0, 4}, {4, 0}, 
		{0, 5}, {5, 0}, {1, 3}, {3, 1}, {2, 4}, {4, 2}, {2, 6}, {6, 2}, 
		{4, 7}, {7, 4}};
	fillGrid(likes, arr5, 18);
	res = maxPairs(likes);
	printTestResults(res == 4, testNum, passedNum);
	//#5.1
	likes.resize(8, 8);
	clearGrid(likes);
	int arr51[18][2] = {
		{0, 1}, {1, 0}, {0, 2}, {2, 0}, {0, 3}, {3, 0}, {0, 4}, {4, 0}, 
		{0, 5}, {5, 0}, {1, 3}, {3, 1}, {1, 6}, {6, 1}, {2, 3}, {3, 2}, 
		{4, 7}, {7, 4}};
	fillGrid(likes, arr51, 18);
	res = maxPairs(likes);
	printTestResults(res == 4, testNum, passedNum);
	//#6
	likes.resize(10, 10);
	clearGrid(likes);
	int arr6[24][2] = {
		{0, 1}, {1, 0}, {0, 2}, {2, 0}, {0, 3}, {3, 0}, {0, 4}, {4, 0}, 
		{0, 5}, {5, 0}, {1, 2}, {2, 1}, {1, 3}, {3, 1}, {1, 4}, {4, 1}, 
		{2, 7}, {7, 2}, {2, 8}, {8, 2}, {3, 7}, {7, 3}, {6, 9}, {9, 6}};
	fillGrid(likes, arr6, 24);
	res = maxPairs(likes);
	printTestResults(res == 5, testNum, passedNum);
	//#7
	likes.resize(12, 12);
	clearGrid(likes);
	int arr7[40][2] = {
		{0, 7}, {7, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, 
		{0, 8}, {0, 9}, {1, 3}, {3, 1}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, 
		{1, 8}, {1, 9}, {1, 11}, {11, 1}, {3, 10}, {10, 3}, {2, 9}, {9, 2}, 
		{4, 7}, {7, 4}, {2, 8}, {2, 10}, {3, 7}, {7, 3}, {6, 9}, {9, 6}, 
		{5, 9}, {9, 5}, {2, 4}, {2, 9}, {3, 4}, {4, 7}, {4, 10}, {5, 8}};
	fillGrid(likes, arr7, 40);
	res = maxPairs(likes);
	printTestResults(res == 4, testNum, passedNum);
	//#7.1
	likes.resize(12, 12);
	clearGrid(likes);
	int arr71[43][2] = {
		{0, 7}, {7, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, 
		{0, 8}, {0, 9}, {1, 3}, {3, 1}, {1, 0}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, 
		{1, 8}, {1, 9}, {1, 11}, {11, 1}, {3, 10}, {10, 3}, {2, 9}, {9, 2}, 
		{4, 7}, {7, 4}, {4, 8}, {8, 4}, {2, 8}, {2, 10}, {3, 7}, {7, 3}, {6, 9}, {9, 6}, 
		{5, 9}, {9, 5}, {2, 4}, {2, 9}, {3, 4}, {4, 7}, {4, 10}, {5, 8}};
	fillGrid(likes, arr71, 43);
	res = maxPairs(likes);
	printTestResults(res == 5, testNum, passedNum);
	//#8
	likes.resize(11, 11);
	clearGrid(likes);
	int arr8[44][2] = {
		{0, 6}, {6, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, 
		{0, 8}, {0, 9}, {1, 3}, {3, 1}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, 
		{1, 8}, {1, 9}, {1, 10}, {10, 1}, {3, 10}, {10, 3}, {2, 9}, {9, 2}, 
		{4, 7}, {7, 4}, {2, 8}, {2, 10}, {3, 7}, {7, 3}, {6, 9}, {9, 6}, 
		{5, 9}, {9, 5}, {2, 4}, {2, 9}, {3, 4}, {4, 7}, {4, 10}, {5, 8}, 
		{6, 10}, {2, 5}, {5, 6}, {5, 7}};
	fillGrid(likes, arr8, 44);
	res = maxPairs(likes);
	printTestResults(res == 4, testNum, passedNum);
	//#9
	likes.resize(14, 14);
	clearGrid(likes);
	int arr9[45][2] = {
		{0, 1}, {1, 0}, {0, 2}, {2, 0}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, 
		{0, 8}, {0, 9}, {1, 3}, {3, 1}, {1, 12}, {12, 1}, {1, 6}, {1, 7}, 
		{1, 8}, {1, 9}, {1, 10}, {10, 1}, {3, 4}, {4, 3}, {5, 9}, {9, 5}, 
		{5, 7}, {5, 8}, {5, 10}, {6, 10}, {6, 7}, {6, 12}, {6, 9}, {9, 6}, 
		{7, 8}, {7, 9}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {9, 11}, 
		{9, 12}, {9, 13}, {10, 11}, {10, 12}, {10, 13}};
	fillGrid(likes, arr9, 45);
	res = maxPairs(likes);
	printTestResults(res == 4, testNum, passedNum);
	//#10
	likes.resize(16, 16);
	clearGrid(likes);
	int arr10[36][2] = {
		{0, 1}, {1, 0}, {0, 2}, {2, 0}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, 
		{0, 7}, {0, 8}, {1, 3}, {3, 1}, {4, 5}, {4, 6}, {4, 7}, {4, 8}, 
		{6, 9}, {9, 6}, {6, 8}, {6, 9}, {6, 10}, {7, 14}, {14, 7}, {7, 15}, 
		{15, 7}, {8, 14}, {14, 8}, {9, 10}, {10, 11}, {10, 12}, {10, 13}, {10, 14}, 
		{11, 13}, {11, 14}, {11, 15}, {12, 13}};
	fillGrid(likes, arr10, 36);
	res = maxPairs(likes);
	printTestResults(res == 5, testNum, passedNum);

	for (int i=0; i<40; i++) {
		int am = 0;
		generateRandomGrid(likes);
		int rightSol = maxPairs(likes);
		res = maxPairs(likes);
		cout << rightSol << "; " << likes.numCols() << endl;
		printTestResults(res == rightSol, testNum, passedNum);

	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}

int main() {
	setRandomSeed(1);
	runChangeTests();
	//runPairsTests();
	return 0;
}