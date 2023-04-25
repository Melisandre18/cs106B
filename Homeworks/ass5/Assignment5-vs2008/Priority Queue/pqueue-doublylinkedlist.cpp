/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	head=NULL;
	l=0;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	Cell * empt;
		while(head!=NULL) {
			empt=head;
			head=head->next;
			delete empt;
		}
}

int DoublyLinkedListPriorityQueue::size() {
	return l;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	return l==0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
	Cell * nCell=new Cell;
	nCell->v=value;
	nCell->next=head;
	nCell->pre=NULL;
	l++;
	if(head!=NULL){
		head->pre=nCell;
	}
	head=nCell;
}

string DoublyLinkedListPriorityQueue::peek() {
	if(isEmpty()){
		error("Empty field");
	}
	string min = head->v;
    for (Cell* cell = head; cell !=NULL; cell = cell->next) {
        if (cell->v < min) {
            min = cell->v;
        }
    }
    
    return min;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	string val=peek();
	l--;
	Cell*emp=head;
	while(emp->v !=val){
		emp=emp->next;
	}
	if(emp->next==NULL && emp->pre==NULL){
		head=NULL;
	}else if(emp->next==NULL && emp->pre!=NULL){
		emp->pre->next=NULL;
	}else if(emp->next!=NULL && emp->pre==NULL){
		head=emp->next;
		head->pre=NULL;
	}else{
		emp->next->pre=emp->pre;
		emp->pre->next=emp->next;
	}
	delete emp;
	return val;
}

