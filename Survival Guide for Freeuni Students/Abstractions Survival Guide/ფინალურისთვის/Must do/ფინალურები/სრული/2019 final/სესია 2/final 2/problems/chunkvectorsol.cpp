#include "chunkvectorsol.h"

ChunkVectorSol::ChunkVectorSol() {
	logLen = 0;
	head = NULL;
	chunkLen = 0;
	/*
	length = 0;
	chunkSize = 0;
	root = NULL;
	end = NULL;
	*/
}

ChunkVectorSol::~ChunkVectorSol() {
	Chunk * prev = head;
	while (head != NULL) {
		head = head->next;
		delete prev;
		prev = head;
	}
	/*
	while (root != NULL) {
		Chunk *tmp = root->next;
		delete root;
		root = tmp;
	}
	*/
}

int ChunkVectorSol::size() {
	return logLen;
	/* return length; */
}
int ChunkVectorSol::get(int index) {
	int counter = 0;
	Chunk * curr = head;
	while (true) {
		if (counter + curr->chunkLogLen > index) {
			return curr->arr[index - counter];
		}
		counter += curr->chunkLogLen;
		curr = curr->next;
	}

	return -1;

}
void ChunkVectorSol::set(int index, int value) {
	int counter = 0;
	Chunk * curr = head;
	while (true) {
		if (counter + curr->chunkLogLen > index) {
			curr->arr[index - counter] = value;
			return;
		}
		counter += curr->chunkLogLen;
		curr = curr->next;
	}

}

void ChunkVectorSol::add(int value) {
	if (head == NULL) {
		head = new Chunk;
		chunkLen++;
		head->next = NULL;
		head->chunkLogLen = 0;
	}

	Chunk * curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	
	if (curr->chunkLogLen == CHUNK_SIZE) {
		chunkLen++;
		Chunk * tmp = new Chunk;
		tmp->next = NULL;
		tmp->chunkLogLen = curr->chunkLogLen/2;
		curr->chunkLogLen -= tmp->chunkLogLen;
		for (int i=0; i<tmp->chunkLogLen; i++) {
			tmp->arr[i] = curr->arr[curr->chunkLogLen+i];
		}
		curr->next = tmp;
		curr = tmp;
	}
	curr->arr[curr->chunkLogLen++] = value;
	logLen++;
	/*
	if (root == NULL) {
		root = new Chunk;
		end = root;
		root->logLen = 0;
		root->next = NULL;
		chunkSize++;
	}

	if (end->logLen == CHUNK_SIZE)
		end = addNewChunk(end);

	end->arr[end->logLen++] = value;
	length++;
	*/

}

void ChunkVectorSol::remove(int index) {
	int counter = 0;
	Chunk * curr = head;
	Chunk * prev = NULL;
	while (true) {
		if (counter + curr->chunkLogLen > index) {
			break;
		}
		counter += curr->chunkLogLen;
		prev = curr;
		curr = curr->next;
	}
	for (int i=index-counter; i < curr->chunkLogLen-1; i++) {
		curr->arr[i] = curr->arr[i+1];
	}
	curr->chunkLogLen--;
	logLen--;
	if (curr->chunkLogLen == 0) {
		if (curr == head) {
			head = curr->next;
		} else {
			prev->next = curr->next;
		}
		chunkLen--;
		delete curr;
	}
	/* 	int chunkIndex = 0;
	Chunk *prev = NULL;
	Chunk *curr = getChunk(index, chunkIndex, prev);

	for (int i = chunkIndex + 1; i < curr->logLen; i++) 
		curr->arr[i - 1] = curr->arr[i];

	curr->logLen--;

	if (curr->logLen == 0) {
		if (prev != NULL) prev->next = curr->next;
		if (root == curr) root = root->next;
		if (end == curr) end = prev;
		delete curr;
		chunkSize--;
	}

	length--;
	*/
}

int ChunkVectorSol::getChunkNumber() {
	return chunkLen;
	/* return chunkSize; */
}

void ChunkVectorSol::insert(int index, int value) {
	if (index == size()) {
		add(value);
		return;
	}

	int counter = 0;
	Chunk * curr = head;
	Chunk * prev = NULL;
	while (true) {
		if (counter + curr->chunkLogLen > index) {
			break;
		}
		counter += curr->chunkLogLen;
		prev = curr;
		curr = curr->next;
	}

	if (curr->chunkLogLen == CHUNK_SIZE) {
		chunkLen++;
		Chunk * tmp = new Chunk;
		tmp->next = curr->next;
		tmp->chunkLogLen = curr->chunkLogLen/2;
		curr->chunkLogLen -= tmp->chunkLogLen;
		for (int i=0; i<tmp->chunkLogLen; i++) {
			tmp->arr[i] = curr->arr[curr->chunkLogLen+i];
		}
		curr->next = tmp;
	}

	if (counter + curr->chunkLogLen <= index) {
		counter += curr->chunkLogLen;
		curr = curr->next;
	}
	int i;
	for (i=curr->chunkLogLen; i>index-counter; i--) {
		curr->arr[i] = curr->arr[i-1];
	}
	curr->arr[i] = value;
	logLen++;
	curr->chunkLogLen++;
/*
if (index >= length) {
		add(value);
		return;
	}

	int chunkIndex = 0;
	Chunk *Null;
	Chunk *curr = getChunk(index, chunkIndex, Null);

	if (curr->logLen == CHUNK_SIZE) { 
		Chunk *newCh = addNewChunk(curr);
		if (end == curr) end = newCh;

		if (curr->logLen < chunkIndex) {
			chunkIndex -= curr->logLen;
			curr = curr->next;
		}
	}

	for (int i = curr->logLen; i > chunkIndex; i--) 
		curr->arr[i] = curr->arr[i - 1];

	curr->arr[chunkIndex] = value;
	curr->logLen++;
	length++;
	*/
}