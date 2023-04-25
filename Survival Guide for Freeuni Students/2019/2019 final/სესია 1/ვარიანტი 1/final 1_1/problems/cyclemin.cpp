#include "cyclemin.h"
#include "map.h"
#include "pqueue.h"
#include "set.h"
#include "map.h"
void findCycle(Vector<edgeT *> &g, int & result){
	Map<int, Vector<edgeT* > > map;
	for(int i=0; i<g.size(); i++){
		if(!map.containsKey(g[i]->from)){
			Vector<edgeT *> vect;
			vect.add(g[i]);
			map.put(g[i]->from, vect);
		}else{
			map[g[i]->from].add(g[i]);
		}
	}
	Vector<int> path;
	PriorityQueue<int> pqueue;
	Set<int> visited;
	int counter=0;
	int index = 0;
	pqueue.enqueue(g[0]->from, 0);
	while(!pqueue.isEmpty()){
		int m = pqueue.dequeue();
		if(!visited.contains(m)){
			visited.add(m);
			path.add(m);
			for(int i=0; i<map[m].size(); i++){
				pqueue.enqueue(map[m][i]->to, map[m][i]->weight);
			}
		}else{
			counter++;
			path.add(m);
			if(counter==1){
				for(int i=0; i<path.size(); i++){
					if(path[i]==m) {
						index = i;
						break;
					}
				} 
				int cycle = INT_MAX;
				for(int j=index; j<path.size()-1; j++){
					for(int q=0; q<map[path[j]].size();q++){
						if(map[path[j]][q]->to==path[j+1]){
							cycle = min(cycle, map[path[j]][q]->weight);
						}
			
					}
				}
				result=cycle;
			}else{
				result=-1;
			}
		}
		
	}
}
int removeCycleMin(Vector<edgeT *> &g) {
	int result = 0;
	findCycle(g, result);
	return result;
}
/*
void removeCycleMinRec(Map<int , Vector<edgeT *> > Nodes , edgeT* transfer , int current ,Set<int> been ,int & result, int sz ){
	if(been.size() ==sz) return;
	if(been.contains(current) && transfer->weight<result ) result = transfer->weight;
	been.insert(current);
	for(int q = 0 ; q<Nodes[current].size() ; q++){
		//cout<<Nodes[current].size()<<endl;
		removeCycleMinRec(Nodes , Nodes[current][q] , Nodes[current][q]->to , been , result, sz);
	}
	been.remove(current);
}
int removeCycleMin(Vector<edgeT *> &g) {
	int result = INT_MAX;
	Map<int, Vector<edgeT* > > map;
	for(int i=0; i<g.size(); i++){
		if(!map.containsKey(g[i]->from)){
			Vector<edgeT *> vect;
			vect.add(g[i]);
			map.put(g[i]->from, vect);
		}else{
			map[g[i]->from].add(g[i]);
		}
	}
	foreach(int q in map){
		Set<int> been;
		removeCycleMinRec(map ,g[0] , q , been , result , g.size());
	}
	if(result == INT_MAX) return -1;
	return result;
}*/