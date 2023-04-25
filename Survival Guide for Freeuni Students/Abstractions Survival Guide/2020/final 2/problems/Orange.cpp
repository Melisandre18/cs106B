#include "Orange.h"
#include "set.h"
#include "queue.h"

bool valid(int** grid,Set<int>&v, int w, int h, int x, int y){
	return !(x<0 || y<0 ||  v.contains(w*x+y) || x>=h ||y>=w||grid[x][y]==0);
}

void insert(Set<int>&v, Queue<int>&q, int w, int h, int x, int y){
	v.insert(w*x+y);
	q.enqueue(w*x+y);
}
int orangesRotting(int** grid, int w, int h, int x, int y) {
	Set<int>v;
	Queue<int>q;
	int num=0;
	int level=0; 
	int left=1;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(grid[i][j]==1) num++;
		}
	}
	insert(v,q,w,h,x,y);

	while(!q.isEmpty()){
		if(num==0) return level;
		num--;

		int curr= q.dequeue();
		int cx=curr/w;
		int cy=curr%w;
		if (valid(grid,v,w,h,cx, cy+1)) insert(v,q,w,h,cx,cy+1);
		if (valid(grid,v,w,h,cx+1, cy)) insert(v,q,w,h,cx+1,cy);
		if (valid(grid,v,w,h,cx-1, cy)) insert(v,q,w,h,cx-1,cy);
		if (valid(grid,v,w,h,cx, cy-1)) insert(v,q,w,h,cx,cy-1);
		left--;
		if(left==0) {
			level++;
			left=q.size();
		}
	}

	return -1;
}