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
#include "chunkvector.h"
#include "chunkvectorsol.h"
#include <vld.h>

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

void addSomeNumbers(int size, ChunkVector * v1, ChunkVectorSol * v2) {
	for (int i=0; i< size; i++) {
		v1->add(i);	
		v2->add(i);	
	}
}

void setSomeNumbers(int size, ChunkVector * v1, ChunkVectorSol * v2) {
	for (int i=0; i< size; i++) {
		int index = randomInteger(0, v2->size()-1);
		v1->set(index, -index);	
		v2->set(index, -index);	
	}
}

void removeSomeNumbers(int size, ChunkVector * v1, ChunkVectorSol * v2) {
	for (int i=0; i< size; i++) {
		int index = randomInteger(0, v2->size()-1);
		v1->remove(index);	
		v2->remove(index);	
	}
}

void insertSomeNumbers(int size, ChunkVector * v1, ChunkVectorSol * v2) {
	v1->insert(0, 0);
	v2->insert(0, 0);
	for (int i=1; i<size; i++) {
		int index = randomInteger(0, v2->size()-1);
		v1->insert(index, i);	
		v2->insert(index, i);	
	}
}

bool isEqual(ChunkVector * v1, ChunkVectorSol * v2) {
	bool equal = v1->size() == v2->size();
	for (int i=0; i<v1->size(); i++) {
		equal = equal && v1->get(i) == v2->get(i);
	}
	return equal && v1->getChunkNumber() == v2->getChunkNumber();
}

void testChunkVector() {
	cout << "### Run ChunkVector tests ###" << endl;
	bool passed = false;
	int testNum = 0; 
	int passedCounter = 0;
	ChunkVector *v1;
	ChunkVectorSol *v2;
	//#1
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(1, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#2
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(2, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#3
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(3, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#4
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(4, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#5
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(14, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#6
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(15, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#7
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(16, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#8
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(20, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#9
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(29, v1, v2);
	setSomeNumbers(4, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#10
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(41, v1, v2);
	setSomeNumbers(14, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#11
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(1, v1, v2);
	removeSomeNumbers(1, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#12
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(4, v1, v2);
	removeSomeNumbers(4, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#13
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(25, v1, v2);
	removeSomeNumbers(18, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#14
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(48, v1, v2);
	removeSomeNumbers(21, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#15
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	addSomeNumbers(74, v1, v2);
	removeSomeNumbers(44, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#16
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	insertSomeNumbers(7, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#17
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	insertSomeNumbers(12, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#18
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	insertSomeNumbers(12, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#19
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	insertSomeNumbers(22, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;
	//#20
	v1 = new ChunkVector;
	v2 = new ChunkVectorSol;
	insertSomeNumbers(47, v1, v2);
	printTestResults(isEqual(v1, v2), testNum, passedCounter);
	delete v1;
	delete v2;

	cout << "###### passed " << passedCounter << " tests ######" << endl;
}

int main() {
	setRandomSeed(0);
	testChunkVector();
	return 0;
}