#include "cache_map.h"


const int kNumValue = 1000;
CacheMap::CacheMap(int size)
{
	maxSize=size;
	length = 0;
	map = new Cell*[maxSize];
}

void CacheMap::put(int key, int value)
{
    Cell* c= new Cell;
	c->key=key;
	c->valueNum=value;
	if(containsKey(key)){
	for(int i=0; i<length; i++){
		if(map[i]->key==key) map[i]->valueNum=value;
	}
	}else{
		if(length<maxSize){
			map[length]=c;
			length++;
		}else{
			for(int i=0; i<length-1; i++){
		     map[i]=map[i+1];
		}
			map[length-1]=c;
		}
	}
	
}

int CacheMap::get(int key)
{
	if(containsKey(key)){
	for(int i=0; i<length; i++){
		if(map[i]->key==key) return map[i]->valueNum;
		}
	}
}

int CacheMap::size()
{
	return length;
}

void CacheMap::remove(int key)
{
	if(containsKey(key)){
	int index=0;
	for(int i=0;i<length; i++){
		if(map[i]->key==key){
			index=i;
		}
	}
	for(int i=index; i<length-1; i++){
		map[i]=map[i+1];
	}
	length--;
	}
	
}

bool CacheMap::containsKey(int key)
{
	for(int i=0; i<length; i++){
		if(map[i]->key==key) return true;
	}
	return false;
}
