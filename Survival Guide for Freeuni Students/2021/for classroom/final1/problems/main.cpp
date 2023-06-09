#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
#include "vector.h"
#include "HashMap.h"
#include <time.h>
#include "LinkedHashMap.h"
#include "random.h"

using namespace std;

void printTestResults(bool passed, int testNum, int & passedCounter) {
	if (passed) {
		cout << "test " << testNum << " passed" << endl;
		passedCounter++;
	} else {
		cout << "test " << testNum << " failed" << endl;
	}
}


bool runLinkedHashMapTest(int testNum);

const int linkedHashMapTestsNum = 20;

void runLinkedHashMapTests() {
	cout << "### Run LInkedHashMap tests ###" << endl;
	int passedNum = 0;
	int testNum = 1;

	for (; testNum<=linkedHashMapTestsNum; testNum++) {
		bool res = runLinkedHashMapTest(testNum);
		printTestResults(res, testNum, passedNum);
	}

	cout << "###### passed " << passedNum << " tests ######" << endl;
}




int main() {
	runLinkedHashMapTests();
	cout << "end" << endl;
	return 0;
}

//ადარებს ერთმანეთს LinkedHashMap და HashMap ობიექტებს, თუ ზუსტად ერთი და იგივე წყვილებს ინახავენ ბრუნდება true
bool isEqual(LinkedHashMap &m1, HashMap<string, int> &m2) {
	if (m2.size() != m1.size()) 
		return false;

	foreach (string key in m2) {
		if (!m1.containsKey(key)) {
			return false;
		}
		if (m1.get(key) !=  m2.get(key)) {
			return false;
		}
	}

	return true;
}

bool isCorrectOrder(LinkedHashMap &m, Vector<string> &order) {
	int index = 0;
	m.resetKeyIterator();
	while (m.hasNextKey()) {
		string key = m.nextKey();
		if (key != order[index]) {
			return false;
		}
		index++;
	}

	return index == order.size();
}

//ამატებს თქვენს მეფში n key, value წყვილს. key და value ს მნიშვნელობები გენერირდება  minVal, maxVal შუალედში
//ზუსტად იგივეს აკეთებს HashMap ობიექტშიც და შემდეგ ხდება მათი შედარება. თუ order ვექტორი NULL ისგან განსხვავებულია, ინახავს key ებს იმ რიგითობით რა რიგითობითაც მოხდა მათი დამატება 
void addRandomKeyValues(LinkedHashMap &m1, HashMap<string, int> &m2, int n, int minVal, int maxVal, Vector<string> *order = NULL) {
	for (int i=0; i<n; i++) {
		int val = randomInteger(minVal, maxVal);
		string key = string("key") + integerToString(randomInteger(minVal, maxVal));

		if (order != NULL) {
			if (m2.containsKey(key)) {
				for (int i=0; i<order->size(); i++) {
					if (order->get(i) == key) {
						order->remove(i);
						break;
					}
				}
			}
			order->add(key);
		}
		m1.put(key, val);
		m2.put(key, val);
	}
}

//შლის თქვენს მეფიდან n key, value წყვილს. key -ს მნიშვნელობები გენერირდება  minVal, maxVal შუალედში
//ზუსტად იგივეს აკეთებს HashMap ობიექტშიც და შემდეგ ხდება მათი შედარება. თუ order ვექტორი NULL ისგან განსხვავებულია, ინახავს key ებს იმ რიგითობით რა რიგითობითაც მოხდა მათი დამატება 
void removeRandomKeys(LinkedHashMap &m1, HashMap<string, int> &m2, int n, int minVal, int maxVal, Vector<string> *order = NULL) {
	for (int i=0; i<n; i++) {
		string key = string("key") + integerToString(randomInteger(minVal, maxVal));
		if (order != NULL && m2.containsKey(key)) {
			for (int i=0; i<order->size(); i++) {
				if (order->get(i) == key) {
					order->remove(i);
					break;
				}
			}
		}
		m1.remove(key);
		m2.remove(key);
	}
}

bool runLinkedHashMapTest(int testNum) {
	bool passed = false;
	LinkedHashMap map;
	HashMap<string, int> cloneMap;
	Vector<string> order;
	int counter = 0;

	setRandomSeed(testNum*10);
	
	switch (testNum) {
		case 1:
			addRandomKeyValues(map, cloneMap, 5, 1, 2);
			passed = isEqual(map, cloneMap);
			break;
		case 2:
			addRandomKeyValues(map, cloneMap, 10, 1, 10);
			passed = isEqual(map, cloneMap);
			break;
		case 3:
			addRandomKeyValues(map, cloneMap, 50, 1, 30);
			passed = isEqual(map, cloneMap);
			addRandomKeyValues(map, cloneMap, 50, 1, 30);
			passed = passed && isEqual(map, cloneMap);
			break;
		case 4:
			addRandomKeyValues(map, cloneMap, 250, 1, 200);
			passed = isEqual(map, cloneMap);
			addRandomKeyValues(map, cloneMap, 250, 1, 200);
			passed = passed && isEqual(map, cloneMap);
			break;
		case 5:
			addRandomKeyValues(map, cloneMap, 5, 1, 5);
			removeRandomKeys(map, cloneMap, 3, 1, 5);
			passed = isEqual(map, cloneMap);
			break;
		case 6:
			addRandomKeyValues(map, cloneMap, 20, 1, 20);
			removeRandomKeys(map, cloneMap, 5, 1, 20);
			addRandomKeyValues(map, cloneMap, 20, 1, 20);
			removeRandomKeys(map, cloneMap, 15, 1, 20);
			passed = isEqual(map, cloneMap);
			break;
		case 7:
			addRandomKeyValues(map, cloneMap, 100, 1, 50);
			removeRandomKeys(map, cloneMap, 50, 1, 50);
			passed = isEqual(map, cloneMap);
			break;
		case 8:
			addRandomKeyValues(map, cloneMap, 200, 1, 150);
			removeRandomKeys(map, cloneMap, 150, 1, 200);
			addRandomKeyValues(map, cloneMap, 200, 1, 150);
			removeRandomKeys(map, cloneMap, 150, 1, 200);
			passed = isEqual(map, cloneMap);
			break;
		case 9:
			addRandomKeyValues(map,  cloneMap, 5, 1, 20, &order);
			passed = isEqual(map, cloneMap) && isCorrectOrder(map, order);
			break;
		case 10:
			addRandomKeyValues(map,  cloneMap, 20, 1, 20, &order);
			passed = isEqual(map, cloneMap) && isCorrectOrder(map, order);
			break;
		case 11://add, check, add
			addRandomKeyValues(map,  cloneMap, 30, 1, 50, &order);
			passed = isEqual(map, cloneMap) && isCorrectOrder(map, order);
			addRandomKeyValues(map,  cloneMap, 30, 1, 50, &order);
			passed = passed && isEqual(map, cloneMap) && isCorrectOrder(map, order);
			break;
		case 12://add, check, remove all, check
			addRandomKeyValues(map,  cloneMap, 10, 1, 2, &order);
			passed = isEqual(map, cloneMap) && isCorrectOrder(map, order);
			removeRandomKeys(map, cloneMap, 10, 1, 2, &order);			
			passed = passed && isEqual(map, cloneMap) && isCorrectOrder(map, order);
			break;
		case 13://add, check, add, check, add, check
			addRandomKeyValues(map,  cloneMap, 11, 1, 50, &order);
			passed = isEqual(map, cloneMap) && isCorrectOrder(map, order);
			addRandomKeyValues(map,  cloneMap, 11, 1, 50, &order);
			passed = passed && isEqual(map, cloneMap) && isCorrectOrder(map, order);
			addRandomKeyValues(map,  cloneMap, 11, 1, 50, &order);
			passed = passed && isEqual(map, cloneMap) && isCorrectOrder(map, order);
			break;
		case 14://add, check, remove, check, add
			addRandomKeyValues(map,  cloneMap, 11, 1, 50, &order);
			passed = isEqual(map, cloneMap) && isCorrectOrder(map, order);
			removeRandomKeys(map, cloneMap, 10, 1, 50, &order);
			passed = passed && isEqual(map, cloneMap);
			passed = passed && isCorrectOrder(map, order);
			addRandomKeyValues(map,  cloneMap, 11, 1, 50, &order);
			passed = passed && isEqual(map, cloneMap);
			passed = passed && isCorrectOrder(map, order);
			break;
		case 15://add, check, remove, add, check, remove, check
			addRandomKeyValues(map,  cloneMap, 30, 1, 50, &order);
			passed = isEqual(map, cloneMap) && isCorrectOrder(map, order);
			removeRandomKeys(map, cloneMap, 20, 1, 50, &order);
			addRandomKeyValues(map,  cloneMap, 30, 1, 50, &order);
			passed = passed && isEqual(map, cloneMap) && isCorrectOrder(map, order);
			removeRandomKeys(map, cloneMap, 20, 1, 50, &order);
			passed = passed && isEqual(map, cloneMap) && isCorrectOrder(map, order);			
			break;

		//check time complexity
		case 16:
			addRandomKeyValues(map,  cloneMap, 100000, 1, 2000000);
			passed = isEqual(map, cloneMap);
			break;
		case 17:
			addRandomKeyValues(map,  cloneMap, 100000, 1, 200000);
			removeRandomKeys(map,  cloneMap, 200000, 1, 200000);
			passed = isEqual(map, cloneMap);
			break;
		case 18:
			addRandomKeyValues(map,  cloneMap, 100000, 1, 200000);
			removeRandomKeys(map,  cloneMap, 200000, 1, 200000);
			passed = isEqual(map, cloneMap);
			break;
		case 19:
			addRandomKeyValues(map,  cloneMap, 100000, 1, 200000);
			counter = 0;
			map.resetKeyIterator();
			while (map.hasNextKey()) {
				counter++;
				string key = map.nextKey();
			}
			passed = isEqual(map, cloneMap) && counter == map.size();
			break;
		case 20:
			addRandomKeyValues(map,  cloneMap, 100000, 1, 200000);
			counter = 0;
			map.resetKeyIterator();
			while (map.hasNextKey()) {
				counter++;
				string key = map.nextKey();
			}
			passed = isEqual(map, cloneMap) && counter == map.size();
			addRandomKeyValues(map,  cloneMap, 100000, 1, 200000);
			map.resetKeyIterator();
			counter = 0;
			map.resetKeyIterator();
			while (map.hasNextKey()) {
				counter++;
				string key = map.nextKey();
			}
			passed = passed && isEqual(map, cloneMap) && counter == map.size();
			break;

	}

	return passed;
}