
#ifndef LinkedHashMap_Included
#define LinkedHashMap_Included

#include "console.h"
#include "error.h"
using namespace std;

class LinkedHashMap {

public:
	LinkedHashMap();
	
	void put(string key, int value);
	bool containsKey(string key);
	int get(string key);
	void remove(string key);
	
	void resetKeyIterator();
	bool hasNextKey();
	string nextKey();

	int size();

private:
	struct DoublyCell {
		string key;
		int value;
		DoublyCell * next;
		DoublyCell * prev;
	};

	struct Cell {
		string key;
		int value;
		Cell * next;
		DoublyCell * place;
	};

	Cell **buc;
	int maxSize;
	int len;
	DoublyCell *head;
	DoublyCell *tail;
	DoublyCell *iter;

};
#endif;