#include "cache_map.h"



CacheMap::CacheMap(int size)
{
	maxSize=size;
	info = new Map*[maxSize];
	length=0;
}

void CacheMap::put(int key, int value)
{
	Map* rame = new Map();
	rame->key = key ;
	rame->val = value;
	if(containsKey(key)){
    for(int w = 0 ; w<length ; w++){
		if(info[w]->key==key)info[w]->val=value ;

			}
	}else{
		if(maxSize>length){
			info[length] = rame;
			length++;
		}else{
			for(int w = 0 ; w<length-1 ; w++){
				info[w] = info[w+1];
			}
		info[length-1] = rame;
		}
	}
		
}

int CacheMap::get(int key)
{
	if(containsKey(key)){
		for(int i=0; i<length; i++){
		if(info[i]->key==key) return info[i]->val;
	}
	}
	return NULL;
}

int CacheMap::size()
{
	return length;
	
}

void CacheMap::remove(int key)
{
	if(containsKey(key)){
	int index=0;
	for(int i=0; i<length-1; i++){
		if(info[i]->key==key) index=i;
	}
	for(int i=index; i<length-1; i++){
		info[i]->key=info[i+1]->key;
		info[i]->val=info[i+1]->val;
		
	}
		length--;
}
	
}

bool CacheMap::containsKey(int key)
{
	for(int i=0; i<length; i++){
		if(info[i]->key==key) return true;
	}
	return false;

}