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
		int length ;
		int maxSize ;
		struct Map {
			int val ;
			int key ;
		};
		Map** info;

};