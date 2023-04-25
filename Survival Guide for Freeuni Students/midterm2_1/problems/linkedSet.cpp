#include "linkedSet.h"
#include <iostream>

LinkedSet::LinkedSet() {
	len=0;
	head= new Node;
	tail=new Node;
	head->next=tail;
	tail->next=NULL;
	head->prev=NULL;
	tail->prev=head;
	iter=head;

}
void LinkedSet::add(int k) {
	
	if(!contains(k)){
	Node* tmp=new Node;
	tmp->val=k;
	tmp->prev=tail->prev;
	tmp->next=tail;
	tail->prev->next=tmp;
	tail->prev=tmp;
	len++;
	}
	
}
bool LinkedSet::contains(int k) {
	Node* tmp=head;
	while(tmp!=tail){
		if(tmp->val==k) return true;
		tmp=tmp->next;
	}
	return false;
}
int LinkedSet::size() {
	return len;
}
void LinkedSet::remove(int k) {
	if(contains(k)){
		Node* tmp= head;
		len--;
		while(tmp->val!=k){
		tmp=tmp->next;
		}
	tmp->prev->next=tmp->next;
	tmp->next->prev=tmp->prev;
	}
	

}
void LinkedSet::resetIterator() {
		iter=head;
}
bool LinkedSet::hasNext() {
	return iter->next!=tail;
}
int LinkedSet::next() {
	iter=iter->next;
	return iter->val;
}