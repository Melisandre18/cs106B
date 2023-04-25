#include "cyclemax.h"
#include "set.h"

bool hasCycle(Grid<int> &g, int curr, Set<int> &visited, int parent) {
	if (visited.contains(curr)) {
		return true;
	}

	visited.add(curr);
	for (int i=0; i<g.numRows(); i++) {
		if (g[curr][i] != -1 && i != parent) {
			bool b = hasCycle(g, i, visited, curr);
			if (b) {
				return true;
			}
		}
	}

	return false;
}

int removeCycleMax(Grid<int> &g) {
	int res = -1;
	for (int i=0; i<g.numRows(); i++) {
		for (int j=0; j<g.numRows(); j++) {
			int saved = g[i][j];
			g[i][j] = -1;
			g[j][i] = -1;
			
			Set<int> visited;
			bool has = false;
			for (int k=1; k<g.numRows(); k++) {
				visited.clear();
				if (hasCycle(g, k, visited, -1)) {
					has = true;
					break;
				}			
			}
			if (!has) {
				if (res == -1) {
					res = saved;
				} else if (res < saved){
					res = saved;
				}
			}

			g[i][j] = saved;
			g[j][i] = saved;
		}
	}
	return res;
}