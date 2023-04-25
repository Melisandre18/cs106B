#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
#include "vector.h"
#include "queue.h"
#include <time.h>
#include "code.h"
#include "numbers.h"

using namespace std;

void printTestResults(bool passed, int testNum, int & passedCounter) {
	if (passed) {
		cout << "test " << testNum << " passed" << endl;
		passedCounter++;
	} else {
		cout << "test " << testNum << " failed" << endl;
	}
}


bool runCodeTest(int testNum) {
	bool passed = 0;
	//string fileName = string(PROJECT_ROOT_FOLDER) + string("code\\test") + integerToString(testNum) + ".txt"; 
	string fileName = string("code\\test") + integerToString(testNum) + ".txt";
	
	ifstream inp(fileName.c_str());
	if (inp.fail())
		return false;

	int n;
	string symbols;
	Vector<string> answ;
	inp >> n >> symbols;
	
	string code;
	while (inp >> code) {
		answ += code;
	}
	
	Vector<string> res = generateCodes(n, symbols);
	if (res.size() != answ.size())
		return false;
	for (int i=0; i<res.size(); i++) {
		if (res[i] != answ[i])
			return false;
	}
	return true;
}

const int codeTestsNum = 15;

void runCodeTests() {
	cout << "### Run Code tests ###" << endl;
	int passedNum = 0;
	int testNum = 1;

	for (; testNum<=codeTestsNum; testNum++) {
		bool res = runCodeTest(testNum);
		printTestResults(res, testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}


bool runNumbersTest(int testNum) {
	bool passed = 0;
	//string fileName = string(PROJECT_ROOT_FOLDER) + string("numbers\\test") + integerToString(testNum) + ".txt";; 
	string fileName = string("numbers\\test") + integerToString(testNum) + ".txt";
	ifstream inp(fileName.c_str());
	if (inp.fail())
		return false;

	int n, k;
	Vector<int> answ;
	inp >> n >> k;
	
	int numb;
	while (inp >> numb) {
		answ += numb;
	}

	Vector<int> res = numsSameConsecDiff(n, k);
	if (res.size() != answ.size())
		return false;
	for (int i=0; i<res.size(); i++) {
		if (res[i] != answ[i])
			return false;
	}
	
	return true;
}

const int numbersTestsNum = 15;

void runNumbersTests() {
	cout << "### Run Numbers tests ###" << endl;
	int passedNum = 0;
	int testNum = 1;

	for (; testNum<=numbersTestsNum; testNum++) {
		bool res = runNumbersTest(testNum);
		printTestResults(res, testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}


int main() {
	runCodeTests();
	runNumbersTests();
/*
	Map<string, problemDataT> map;
	problemDataT data;
	data.problemName = "code";
	data.foo = runCodeTest;
	data.totalTestNum = codeTestsNum;
	map.put(data.problemName, data);

	problemDataT dataNumbers;
	dataNumbers.problemName = "numbers";
	dataNumbers.foo = runNumbersTest;
	dataNumbers.totalTestNum = numbersTestsNum;
	map.put(dataNumbers.problemName, dataNumbers);


	runAllTestsInThreads(map);
*/
	cout << "end" << endl;

	return 0;
}