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
#include "passcode.h"
#include "vitamins.h"

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


string pass;
bool isCorrectCode(string code) {
	return pass == code;
}

void testPasscode() {
	cout << "### Testing Passcode ###" << endl;
	int testNum = 0;
	int passed = 0;
	string s;
	//# Test 1
	pass = "22222";
	s = crackCode("2", 5, isCorrectCode);
	printTestResults(s == pass, testNum, passed);
	
	//# Test 2
	pass = "5321";
	s = crackCode("1235", 4, isCorrectCode);
	printTestResults(s == pass, testNum, passed);

	//# Test 3
	pass = "711222";
	s = crackCode("217", 6, isCorrectCode);
	printTestResults(s == pass, testNum, passed);

	//# Test 4
	pass = "6001202";
	s = crackCode("6012", 7, isCorrectCode);
	printTestResults(s == pass, testNum, passed);

	//# Test 5
	pass = "3333333";
	s = crackCode("3", 7, isCorrectCode);
	printTestResults(s == pass, testNum, passed);

	//# Test 6
	pass = "21121";
	s = crackCode("21", 7, isCorrectCode);
	printTestResults(s == pass, testNum, passed);

	//# Test 7
	pass = "1211114";
	s = crackCode("421", 7, isCorrectCode);
	printTestResults(s == pass, testNum, passed);

	//# Test 8
	pass = "6162345";
	s = crackCode("654321", 7, isCorrectCode);
	printTestResults(s == pass, testNum, passed);

	//# Test 9
	pass = "0101091";
	s = crackCode("190", 7, isCorrectCode);
	printTestResults(s == pass, testNum, passed);

	//# Test 10
	pass = "2134567";
	s = crackCode("7654321", 7, isCorrectCode);
	printTestResults(s == pass, testNum, passed);

	cout << "passed: " << passed << endl;
}

Set<string> stringToSet(string vitamins) {
	Set<string> s;
	for (int i=0; i<vitamins.length(); i++) {
		s += vitamins.substr(i, 1);
	}
	return s;
}

bool coversAllVit(Set<string> &vitamins, Vector<int> &res, Vector< Set<string> > &fruits) {
	Set<string> tmp;
	for (int i = 0; i < res.size(); i++) {
		if (res[i] < 0 || res[i] >= fruits.size()) {
			cout << "returned index " << res[i] << "out of range,";
			cout << " fruits vector size is " << fruits.size() << endl;
			return false;
		}
		tmp += fruits[res[i]];
	}
	
	bool result = vitamins.isSubsetOf(tmp);
	if (!result) {
		cout << "given fruits do not cover all vitamins!" << endl;
	}
	return result;
}

void testVitamins() {
	cout << "### Testing Vitamins ###" << endl;
	int testNum = 0;
	int passed = 0;
	int answerSize = 0;
	Set<string> vitamins;
	Vector<int> res;
	Vector< Set<string> > fruits;
	bool result;
	
	// Test 1
	vitamins.clear();
	fruits.clear();
	answerSize = 2; // answer
	vitamins += "A", "B", "C";
	fruits.push_back(stringToSet("A"));
	fruits.push_back(stringToSet("AB"));
	fruits.push_back(stringToSet("C"));

	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	// Test 2
	vitamins.clear();
	fruits.clear();
	answerSize = 3; // answer
	vitamins += "A", "B", "C";
	fruits.push_back(stringToSet("A"));
	fruits.push_back(stringToSet("C"));
	fruits.push_back(stringToSet("A"));
	fruits.push_back(stringToSet("B"));

	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	// Test 3
	vitamins.clear();
	fruits.clear();
	answerSize = 2; // answer
	vitamins += "Z", "B", "C", "D";
	fruits.push_back(stringToSet("ZD"));
	fruits.push_back(stringToSet("ZBTK"));
	fruits.push_back(stringToSet("BC"));
	fruits.push_back(stringToSet("K"));


	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	// Test 4
	vitamins.clear();
	fruits.clear();
	answerSize = 3; // answer
	vitamins += "A", "B", "C", "D", "K";
	fruits.push_back(stringToSet("ABUI"));
	fruits.push_back(stringToSet("AK"));
	fruits.push_back(stringToSet("DB"));
	fruits.push_back(stringToSet("C"));

	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	// Test 5
	vitamins.clear();
	fruits.clear();
	answerSize = 2; // answer
	vitamins += "A", "B", "C", "D";
	fruits.push_back(stringToSet("AB"));
	fruits.push_back(stringToSet("AC"));
	fruits.push_back(stringToSet("CB"));
	fruits.push_back(stringToSet("AD"));
	fruits.push_back(stringToSet("BC"));
	

	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	// Test 6
	vitamins.clear();
	fruits.clear();
	answerSize = 3; // answer
	vitamins += "A", "B", "C", "D", "E", "F";
	fruits.push_back(stringToSet("BC"));
	fruits.push_back(stringToSet("ADE"));
	fruits.push_back(stringToSet("CE"));
	fruits.push_back(stringToSet("BD"));
	fruits.push_back(stringToSet("C"));
	fruits.push_back(stringToSet("F"));
	
	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	// Test 7
	vitamins.clear();
	fruits.clear();
	answerSize = 4; // answer
	vitamins += "A", "B", "C", "D", "E", "F", "G";
	fruits.push_back(stringToSet("AE"));
	fruits.push_back(stringToSet("E"));
	fruits.push_back(stringToSet("CF"));
	fruits.push_back(stringToSet("BDF"));
	fruits.push_back(stringToSet("AF"));
	fruits.push_back(stringToSet("AC"));
	fruits.push_back(stringToSet("G"));
	
	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	// Test 8
	vitamins.clear();
	fruits.clear();
	answerSize = 4; // answer
	vitamins += "A", "B", "C", "D", "E", "F", "G", "H";
	fruits.push_back(stringToSet("CEG"));
	fruits.push_back(stringToSet("AD"));
	fruits.push_back(stringToSet("GH"));
	fruits.push_back(stringToSet("EHB"));
	fruits.push_back(stringToSet("AGC"));
	fruits.push_back(stringToSet("AD"));
	fruits.push_back(stringToSet("DH"));
	fruits.push_back(stringToSet("FG"));
	
	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	// Test 9
	vitamins.clear();
	fruits.clear();
	answerSize = 4; // answer
	vitamins += "A", "B", "C", "D", "E", "F", "G", "H", "I";
	fruits.push_back(stringToSet("EI"));
	fruits.push_back(stringToSet("AG"));
	fruits.push_back(stringToSet("GH"));
	fruits.push_back(stringToSet("DCG"));
	fruits.push_back(stringToSet("BEH"));
	fruits.push_back(stringToSet("FHI"));
	fruits.push_back(stringToSet("GH"));
	fruits.push_back(stringToSet("DFH"));
	fruits.push_back(stringToSet("DF"));
	
	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	
	// Test 10
	vitamins.clear();
	fruits.clear();
	answerSize = 4; // answer
	vitamins += "A", "B", "C", "D", "E", "F", "G", "H", "I", "J";
	fruits.push_back(stringToSet("AGH"));
	fruits.push_back(stringToSet("CFI"));
	fruits.push_back(stringToSet("CG"));
	fruits.push_back(stringToSet("EF"));
	fruits.push_back(stringToSet("ADGH"));
	fruits.push_back(stringToSet("BEH"));
	fruits.push_back(stringToSet("AGH"));
	fruits.push_back(stringToSet("I"));
	fruits.push_back(stringToSet("CFGI"));
	fruits.push_back(stringToSet("DEJH"));

	
	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	// Test 11
	vitamins.clear();
	fruits.clear();
	answerSize = 6; // answer
	vitamins += "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O";
	fruits.push_back(stringToSet("CHN"));
	fruits.push_back(stringToSet("D"));
	fruits.push_back(stringToSet("EHMN"));
	fruits.push_back(stringToSet("CFKO"));
	fruits.push_back(stringToSet("ABCFHL"));
	fruits.push_back(stringToSet("CEFGN"));
	fruits.push_back(stringToSet("JLMN"));
	fruits.push_back(stringToSet("AFHJ"));
	fruits.push_back(stringToSet("FILMN"));
	fruits.push_back(stringToSet("CGIN"));
	fruits.push_back(stringToSet("EHI"));
	fruits.push_back(stringToSet("BEHIM"));
	fruits.push_back(stringToSet("HILO"));
	
	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);
	
	
	// Test 12
	vitamins.clear();
	fruits.clear();
	answerSize = 7; // answer
	vitamins += "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O";
	fruits.push_back(stringToSet("EH"));
	fruits.push_back(stringToSet("FGLO"));
	fruits.push_back(stringToSet("HIR"));
	fruits.push_back(stringToSet("BT"));
	fruits.push_back(stringToSet("CKO"));
	fruits.push_back(stringToSet("FI"));
	fruits.push_back(stringToSet("BFIR"));
	fruits.push_back(stringToSet("JMR"));
	fruits.push_back(stringToSet("LOS"));
	fruits.push_back(stringToSet("IJOP"));
	fruits.push_back(stringToSet("DKN"));
	fruits.push_back(stringToSet("CF"));
	fruits.push_back(stringToSet("AFR"));
	
	res = fruitList(vitamins, fruits);
	result = res.size() == answerSize && coversAllVit(vitamins, res, fruits);
	printTestResults(result, testNum, passed);

	cout << "passed: " << passed << endl;
}


int main() {
	setRandomSeed(0);
	testPasscode();
	testVitamins();
	return 0;
}