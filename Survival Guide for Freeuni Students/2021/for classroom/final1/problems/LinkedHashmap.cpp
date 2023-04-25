
#include "LinkedHashMap.h"

const int kHashMask = 0x7FFFFFFF;
int hashCode(string key) {
    int hashVal = 0;
    for (int x = 0; x < key.length(); ++x) {
        hashVal ^= (hashVal << 5) +
                   (hashVal >> 2) +
                   key[x];
    }
    return hashVal & kHashMask;
}

const int kNumBuckets = 5;



LinkedHashMap::LinkedHashMap() {
	
	maxSize=kNumBuckets;
	len=0;
	iter=0;
	head = new DoublyCell;
	tail = new DoublyCell;
	head -> next = tail;
	head -> prev = NULL;
	tail -> prev = head;
	tail -> next = NULL;
	 iter=head->next;
	 buc= new Cell* [maxSize];
	 for(int i=0; i<maxSize; i++){
		 buc[i]=NULL;
	 }

}
	
void LinkedHashMap::put(string key, int value) {

	if (len >= 2 * maxSize) {
	int new_size = 2* maxSize;
	Cell** new_buckets = new Cell*[new_size];
	for (int i = 0; i < new_size; i++)
		new_buckets[i] = NULL;

	for (int i = 0; i < maxSize; i++) {
		Cell* cur = buc[i];
		while (cur != NULL) {
			int index = hashCode(cur -> key) % new_size;
			Cell* tmp = cur -> next;
			cur -> next = new_buckets[index];
			new_buckets[index] = cur;
			cur = tmp;
		}
	}
	delete buc;
	buc = new_buckets;
	maxSize = new_size;
	}
	

	if(!containsKey(key)){
		DoublyCell* d= new DoublyCell;
		d->key=key;
		d->value=value;
		d->prev = tail->prev;
		d->next = tail;
		tail->prev->next = d;
		tail->prev = d;
	
		Cell *c = new Cell;
		c->key=key;
		c->value=value;
		c->place=d;
		int index= hashCode(key)%maxSize;
		c->next=buc[index];
		buc[index]=c;
		len++;
	}else{
				int index= hashCode(key)%maxSize;
				Cell * tmp= buc[index];
				while(tmp!=NULL){
					if(tmp->key==key) break;
						tmp=tmp->next;
					}
				tmp->value=value;
				tmp->place->value=value;
				tmp->place->prev->next = tmp->place->next;
		tmp->place->next->prev = tmp->place->prev;
		tmp->place->next = tail;
		tmp->place->prev = tail->prev;
		tail->prev->next = tmp->place;
		tail->prev = tmp->place;
		}
	}


bool LinkedHashMap::containsKey(string key) {
	int index= hashCode(key)%maxSize;
	Cell * tmp= buc[index];
	while(tmp!=NULL){
			if(tmp->key==key) return true;
			tmp=tmp->next;
	}
	return false;
}

int LinkedHashMap::get(string key) {
	int index= hashCode(key)%maxSize;
	Cell * tmp= buc[index];
	while(tmp!=NULL){
		if(tmp->key==key) return tmp->value;
			tmp=tmp->next;
	}
	return 0;
}

void LinkedHashMap::remove(string key) {
	int index= hashCode(key)%maxSize;
	Cell * tmp= buc[index];
	Cell *prev=NULL;
	while(tmp!=NULL){
		if(tmp->key==key) break;
		prev=tmp;
		tmp=tmp->next;
	}
	if (tmp==NULL) return;
	if(prev==NULL) buc[index]= tmp->next;
	else prev->next = tmp->next;
	DoublyCell * d = tmp ->place;
	if(d->prev!=NULL) {
		d->prev->next=d->next; 
	}else{
		head=d->next;
	}
	if(d->next!=NULL) {
		d->next->prev=d->prev; 
	}
	delete d;
	delete tmp;
	len--;
}

void LinkedHashMap::resetKeyIterator() {
	iter=head->next;
}

bool LinkedHashMap::hasNextKey() {
	if(iter!=tail) return true;
	return false;
}

string LinkedHashMap::nextKey() {
	string k = iter->key;
	iter=iter->next;
	return k;
}

int LinkedHashMap::size() {
	return len;
}

