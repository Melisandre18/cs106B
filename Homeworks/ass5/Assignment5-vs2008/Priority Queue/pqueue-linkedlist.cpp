/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	head=NULL;
	l=0;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	Cell * empt;
		while(head!=NULL) {
			empt=head;
			head=head->next;
			delete empt;
		}
}

int LinkedListPriorityQueue::size() {
	return l;
}

bool LinkedListPriorityQueue::isEmpty() {
	return l==0;
}

void LinkedListPriorityQueue::enqueue(string value) {
	Cell * nCell=new Cell;
	nCell->v=value;
	nCell->next=NULL;
	l++;
	if(head==NULL){
		head=nCell;
		return;
	}
	for(Cell* cell=head; cell!=NULL; cell=cell->next){
		Cell * curr= cell->next;
		if(cell==head&&nCell->v<=head->v){
			nCell->next=head;
			head=nCell;
			return;

		}
		if(curr==NULL){
			cell->next=nCell;
			return;
		}
		if(value>cell->v &&value<=curr->v){
			nCell->next=curr;
			cell->next=nCell;
			return;

		}

	}
}

string LinkedListPriorityQueue::peek() {
	if(isEmpty()){
		error("Empty field");
	}
	return  head->v;
}

string LinkedListPriorityQueue::dequeueMin() {
	string val=peek();
	l--;
	Cell*emp=head;
	head=head->next;
	delete emp;
	return val;
}

