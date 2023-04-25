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
#include "Map.h"
#include "OrderedMap.h"


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

bool isEqual(OrderedMap &m1, Map<string, int> &m2) {
	if (m2.size() != m1.size()) 
		return false;

	foreach (string key in m2) {
		if (!m1.containsKey(key)) {
			return false;
		}
	}

	return true;
}

void addRandomNumber(OrderedMap &m1, Map<string, int> &m2, int size) {
	for (int i=0; i<size; i++) {
		int val = randomInteger(1, 1000);
		string key = string("key") + integerToString(randomInteger(1, 100));
		m1.put(key, val);
		m2.put(key, val);
	}
}

void removeRandomNumber(OrderedMap &m1, Map<string, int> &m2) {
	for (int i=0; i<1000; i++) {
		string key = string("key") + integerToString(randomInteger(1, 1000));
		m1.remove(key);
		m2.remove(key);
	}
}

void testMap() {
	cout << "### Testing Map ###" << endl;
	int testNum = 0;
	int passed = 0;

	//Test put, get, containsKey and size
	for (int i=1; i<=80; i++) {
		OrderedMap m1;
		Map<string, int> m2;
		addRandomNumber(m1, m2, i*10);		
		bool isCorrect = isEqual(m1, m2);
		printTestResults(isCorrect, testNum, passed);
	}

	//Test remove
	for (int i=1; i<=20; i++) {
		OrderedMap m1;
		Map<string, int> m2;
		addRandomNumber(m1, m2, i*10);
		removeRandomNumber(m1, m2);
		bool isCorrect = isEqual(m1, m2);
		printTestResults(isCorrect, testNum, passed);
	}

	cout << "passed: " << passed << endl;	
}

int main() {
	setRandomSeed(2);
	testMap();
	return 0;
}