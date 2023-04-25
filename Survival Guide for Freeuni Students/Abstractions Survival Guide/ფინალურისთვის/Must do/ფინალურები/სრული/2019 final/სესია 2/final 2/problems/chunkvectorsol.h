#ifndef _chunk_vector_sol_
#define _chunk_vector_sol_

#define CHUNK_SIZE 3
#include "console.h"
using namespace std;
class ChunkVectorSol {
public:
	ChunkVectorSol();
	~ChunkVectorSol();
	int size();
	int get(int index);
	void set(int index, int value);
	void add(int value);
	void remove(int index);
	int getChunkNumber();
	void insert(int index, int value);
private:
	//TODO:
	struct Chunk {
		int arr[CHUNK_SIZE];
		int chunkLogLen;
		Chunk * next;
	};
	int logLen;
	int chunkLen;
	Chunk * head;
};
/*
private:
	int length;
	int chunkSize;

	struct Chunk {
		int arr[CHUNK_SIZE];
		int logLen;
		Chunk *next;
	};

	Chunk *root, *end;

	Chunk *getChunk(int index, int &chunkIndex, Chunk *&prev);
	Chunk *addNewChunk(Chunk *curr);
};
*/
#endif