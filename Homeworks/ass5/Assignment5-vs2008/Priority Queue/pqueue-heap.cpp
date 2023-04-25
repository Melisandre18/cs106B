/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"
const int kDefaultSize = 10;

HeapPriorityQueue::HeapPriorityQueue() {
	logicalLength = 0;
	allocatedLength = kDefaultSize;
	elems = new string[allocatedLength];
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] elems;
}
int HeapPriorityQueue::size() {
	return logicalLength;
}

bool HeapPriorityQueue::isEmpty() {
		return size() == 0;
}

void HeapPriorityQueue::enqueue(string value) {
	if (allocatedLength == logicalLength) {
		grow();
	}
	elems[logicalLength] = value;
	logicalLength++;
	bubbleUp(logicalLength-1);
	
}

string HeapPriorityQueue::peek() {
	if (isEmpty()) {
		error("Empty Field");
	}

	return elems[0];
}

string HeapPriorityQueue::dequeueMin() {
	string min=peek();
	swap(elems[0],elems[logicalLength-1]);
	logicalLength--;
	bubbleDown(0);
	return min;
}
void HeapPriorityQueue::grow() {
	allocatedLength*=2;
	string *tmp = new string[allocatedLength];
	for (int i=0; i<logicalLength; i++) {
		 tmp[i] = elems[i];
	} 
	delete [] elems;
	elems = tmp;
}
void HeapPriorityQueue::bubbleUp(int index){
	if(index<=0) return;
	int pindex;
	if(index%2==0){ 
		pindex=(index-2)/2;
	}
	else{ 
		pindex=(index-1)/2;
	}
	if(elems[index]<elems[pindex]){
		swap(elems[pindex],elems[index]);
		bubbleUp(pindex);
	}
}
void HeapPriorityQueue:: bubbleDown(int index){
	int rindex=2*index +2;
	int lindex=2*index +1;
	if (lindex <= logicalLength-1 && rindex <= logicalLength-1) {
		if (elems[lindex]< elems[rindex]) {
			if(elems[index]>elems[lindex])
			{
				swap(elems[index],elems[lindex]);
				 bubbleDown(lindex);
			}
		}
		else {
			if(elems[index]>elems[rindex])
			{
				swap(elems[index],elems[rindex]);
				 bubbleDown(rindex);
			}
		}
	}
    if (lindex <= logicalLength-1) {
        if (elems[index] > elems[lindex]) {
           swap(elems[index],elems[lindex]);
        }
    }
}

