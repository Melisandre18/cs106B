#include <iostream>
#include <string>
#include <fstream>
#include "simpio.h"
#include "random.h"
#include "console.h"
#include "vector.h"
#include <time.h>
#include "lexicon.h"
#include "sum.h"
#include "sumMap.h"


using namespace std;

void printTestResults(bool passed, int & testNum, int & passedCounter) {
	testNum++;
	if (passed) {
		cout << "test " << testNum << " passed" << endl;
		passedCounter++;
	} else {
		cout << "test " << testNum << " failed" << endl;
	}
}

void testSum() {
	cout << "### Testing Sum ###" << endl;
	int testNum = 0;
	int passed = 0;
	//# Test 1
	printTestResults(sum(1, 4) == 5, testNum, passed);
	//# Test 2
	printTestResults(sum(0, 4) == 4, testNum, passed);
	//# Test 3
	printTestResults(sum(10, 4) == 14, testNum, passed);
	//# Test 4
	printTestResults(sum(51, 4) == 55, testNum, passed);
	//# Test 5
	printTestResults(sum(1, 44) == 45, testNum, passed);

	cout << "passed: " << passed << endl;
}

void testSumMap() {
	cout << "### Testing Sum Map ###" << endl;
	int testNum = 0;
	int passed = 0;
	//# Test 1
	Map<int, int> map;
	printTestResults(sumMap(map) == 0, testNum, passed);
	//# Test 2
	map.clear();
	map.put(4, 1);
	printTestResults(sumMap(map) == 4, testNum, passed);
	//# Test 3
	map.clear();
	map.put(4, 1);
	map.put(10, 1);
	printTestResults(sumMap(map) == 14, testNum, passed);
	//# Test 4
	map.clear();
	map.put(4, 1);
	map.put(10, 1);
	map.put(41, 1);
	printTestResults(sumMap(map) == 55, testNum, passed);
	//# Test 5
	map.clear();
	map.put(4, 1);
	map.put(41, 1);
	printTestResults(sumMap(map) == 45, testNum, passed);
	cout << "passed: " << passed << endl;
}

int main() {
	setRandomSeed(0);
	testSum();
	testSumMap();
	return 0;
}