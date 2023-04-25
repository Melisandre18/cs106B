#include "error.h"
#include "ordered_map.h"

const int kNumBuckets = 70;

OrderedMap::OrderedMap() {
	 
	len=0;
	map = new Cell*[kNumBuckets];

}


int OrderedMap::get(int key) {

	for(int i=0; i<len; i++)
		if(map[i]->key==key) return map[i]->val;
	
}

bool OrderedMap::containsKey(int key) {
	for(int i=0; i<len; i++){
			if(map[i]->key==key) return true;
		}
	return false;
}

void OrderedMap::put(int key, int value) {

	if(containsKey(key)){
		for(int i=0; i<len; i++){
			if(map[i]->key==key) map[i]->val=value;
		}
	}else{

		Cell* m= new Cell;
		m->key=key;
		m->val=value;
		map[len]=m;
		len++;
	}

	iter=len-1;

}

void OrderedMap::remove(int key) {
	int index=0;
	if(containsKey(key)){
		for(int i=0; i<len; i++){
			if(map[i]->key==key) index=i;
		}
		for(int i=index; i<len-1; i++){
			map[i]=map[i+1];
		}
		len--;
	}
	iter=len-1;
}

int OrderedMap::size() {
	return len;
}

void OrderedMap::resetIterator() {
	iter=len-1;
}

bool OrderedMap::hasNext(){
	if(len-1>=iter && iter>=0) return true;
	return false;
}

int OrderedMap::next(){
	int k = map[iter]->key;
	iter--;
	return k;
}
