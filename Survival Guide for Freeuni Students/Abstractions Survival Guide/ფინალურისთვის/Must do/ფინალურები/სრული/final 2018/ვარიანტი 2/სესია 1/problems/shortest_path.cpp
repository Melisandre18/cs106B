#include "shortest_path.h"
#include "queue.h"
#include "set.h"
#include "grid.h"
#include "math.h"
void shortestUp(Grid<int> &table, int& result, int i, int j, int temp){
	if(i==table.numRows()-1 && j==table.numCols()-1){
		if(temp<result) result = temp;
		return;
	}
	if(table.inBounds(i,j+1) && table[i][j]<table[i][j+1]) shortestUp(table, result, i, j+1, temp+1);
	if(table.inBounds(i,j-1) && table[i][j]<table[i][j-1]) shortestUp(table, result, i, j-1, temp+1);
	if(table.inBounds(i+1,j) && table[i][j]<table[i+1][j]) shortestUp(table, result, i+1, j, temp+1);
}
void shortestDown(Grid<int> &table, int& result, int i, int j, int temp){
	if(i==table.numRows()-1 && j==table.numCols()-1){
		if(temp<result) result = temp;
		return;
	}
	if(table.inBounds(i,j+1) && table[i][j]>table[i][j+1]) shortestDown(table, result, i, j+1, temp+1);
	if(table.inBounds(i,j-1) && table[i][j]>table[i][j-1]) shortestDown(table, result, i, j-1, temp+1);
	if(table.inBounds(i+1,j) && table[i][j]>table[i+1][j]) shortestDown(table, result, i+1, j, temp+1);
}
int getShortestPath(Grid<int> &table) {
	int result = INT_MAX;
	int res = INT_MAX;
	shortestUp(table, result,0,0,0);
	if(result==INT_MAX) result=-1;
	shortestDown(table, res,0,0,0);
	if(res==INT_MAX) res=-1;
	if(res==-1 && result!=-1) return result;
	if(res!=-1 && result==-1) return res;
	return -1;
}

