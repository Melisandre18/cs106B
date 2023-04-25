#include <string>
#include "map.h"

using namespace std;

class OrderedMap {
public:
	OrderedMap();
	void put(string key, int value);
	bool containsKey(string key);
	int get(string key);
	void remove(string key);

	int size();

private:
	struct Node {
		//TODO:
	};

};