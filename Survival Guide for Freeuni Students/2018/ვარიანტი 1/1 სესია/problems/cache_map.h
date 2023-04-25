#include <iostream>
#include "simpio.h"
#include "error.h"
#include <limits.h>
using namespace std;


class CacheMap {
	public:
		CacheMap(int cacheSize);
		void put(int key, int value);
		int get(int key);
		int size();
		void remove(int key);
		bool containsKey(int key);

	private:
		struct Cell{
			int key;
			int valueNum;
		};
		Cell** map;
		int length;
		int maxSize;


};