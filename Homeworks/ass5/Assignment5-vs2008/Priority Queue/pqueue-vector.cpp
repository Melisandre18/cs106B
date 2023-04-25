/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
}

VectorPriorityQueue::~VectorPriorityQueue() {
}

int VectorPriorityQueue::size() {
	return ws.size();
}

bool VectorPriorityQueue::isEmpty() {
	return size() == 0;
}

void VectorPriorityQueue::enqueue(string value) {
	ws.add(value);
}

string VectorPriorityQueue::peek() {
	if (isEmpty()) {
		error("Empty field");
	}

	return ws[findWIndex(ws)];
}

string VectorPriorityQueue::dequeueMin() {
	if (isEmpty()) {
		error("Empty field");
	}
	int min=findWIndex(ws);
     string fstw=ws[min];
	 ws.remove(min);

	return fstw ;
	
}
int VectorPriorityQueue::findWIndex(Vector<string>&ws){
   int fst=0;
   string s=ws[0];
   for(int i=1; i<ws.size(); i++){
	   if(s>ws[i]){
		   s=ws[i];
		  fst=i;
	   }
   }
	return fst;
}
