/******************************************************************************
 * File: Trailblazer.cpp
 *
 * Implementation of the graph algorithms that comprise the Trailblazer
 * assignment.
 */

#include "Trailblazer.h"
#include "TrailblazerGraphics.h"
#include "TrailblazerTypes.h"
#include "TrailblazerPQueue.h"
#include "random.h"
#include "pqueue.h"
using namespace std;

/* Function: shortestPath
 * 
 * Finds the shortest path between the locations given by start and end in the
 * specified world.	 The cost of moving from one edge to the next is specified
 * by the given cost function.	The resulting path is then returned as a
 * Vector<Loc> containing the locations to visit in the order in which they
 * would be visited.	If no path is found, this function should report an
 * error.
 *
 * In Part Two of this assignment, you will need to add an additional parameter
 * to this function that represents the heuristic to use while performing the
 * search.  Make sure to update both this implementation prototype and the
 * function prototype in Trailblazer.h.
 */
Vector<Loc>
shortestPath(Loc start,
             Loc end,
             Grid<double>& world,
             double costFn(Loc from, Loc to, Grid<double>& world),
			 double heuristic(Loc start, Loc end, Grid<double>& world)) {
    Map<Loc, Node*> visited;
   TrailblazerPQueue<Loc> pq;
    Node *startNode = new Node;
    startNode->parent = NULL;
    startNode->loc = start;
    startNode->dis = 0;
    colorCell(world, start, YELLOW);
    visited.put(start, startNode);
    pq.enqueue(start,heuristic(start, end, world));
    while (!pq.isEmpty()) {
        Loc curr = pq.dequeueMin();
        Node *currNode = visited.get(curr);
        colorCell(world, curr, GREEN);
        if (currNode->loc== end) {
            Stack<Loc> s;
            Vector<Loc> path;
            Node *step = currNode;
            s.push(curr);
            while ((step = step->parent) != NULL) {
               s.push(step->loc);
            }
            while (!s.isEmpty()) {
                path.add(s.pop());
            }
            return path;
		}
        
        for (int i = -1; i<= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                Loc now;
                now.row = curr.row + i;
                now.col = curr.col + j;
                if (world.inBounds(now.row, now.col)) {
                    double len = costFn(curr, now, world);
                    double vlen = currNode->dis + len;
                    if (!visited.containsKey(now)) {
                        colorCell(world, now, YELLOW);
                        Node *v = new Node;
                        v->loc = now;
                        v->parent = currNode;                       
                        v->dis = vlen;
                        visited.put(now, v);
                        pq.enqueue(now, vlen+ heuristic(now, end, world));
                    } else if (currNode->dis + len< visited.get(now)->dis) {
                        Node *v = visited.get(now);
                        v->loc = now;
                        v->parent = currNode;                       
                        v->dis= vlen;
                        visited.put(now, v);
                        pq.decreaseKey(now, vlen+ heuristic(now, end, world));
                    }
                }
            }
        }
    }
}
void merge(Map<Loc, Set<Loc> *>&m, Loc l1, Loc l2) {
  	Set<Loc> *small = m[l1], *large = m[l2];
  	if (small->size() > large->size())
      	swap(small, large);	
  
    *large += *small;
  
    foreach(Loc key in *small) {
        m[key] = large;
    }
}

Set<Edge> createMaze(int numRows, int numCols) {
    Set<Edge> spanTree;
    Set<Edge> edges;
	Map<Loc, Set<Loc> *> m;
	Set<Set<Loc> *> all;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (i + 1 < numRows) {
                Loc up = makeLoc(i, j);
                Loc down = makeLoc(i+1, j);
                edges.add(makeEdge(up,down));
            }
            if (j + 1 < numCols) {
                Loc l = makeLoc(i,j);
                Loc r= makeLoc(i, j+1);
                edges.add(makeEdge(l,r));
            }
			Loc l = makeLoc(i,j);
            Set<Loc> *s = new Set<Loc>;
            s->add(l);
            m[l] = s;
          	all.add(s);
        }
    }
    TrailblazerPQueue<Edge> pq;
    foreach (Edge e in edges) {
        double lvl =randomReal(0,1);
        pq.enqueue(e, lvl);
    }
    while (!pq.isEmpty()) {
        Edge e = pq.dequeueMin();
      	Loc l1 = e.start;
      	Loc l2 = e.end;
        if (!m[l1]->contains(l2)) {
        	merge(m,l1,l2);
			spanTree.add(e);
		}
    }
  
  	foreach (Set<Loc> *s in all)
      	delete s;
  
    return spanTree;
}