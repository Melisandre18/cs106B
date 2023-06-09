#include "rightview.h"
#include "map.h"
#include "Set.h"

void rec(nodeT * root, int h, Set<int>&st, Vector<nodeT *> &res) {
	if (root == NULL) {
		return;
	}
	if(!st.contains(h)){
		st.add(h);
		res.add(root);
	}
	
	rec(root->right, h+1,st, res);
	rec(root->left, h+1,st, res);
}

Vector<nodeT *> rightView(nodeT * root) {
	Vector<nodeT *> res;
	Set<int>st;
	rec(root, 0, st, res);
	return res;
}
/*
meore amoxsna map it
Map<int, nodeT*> map;
if (!map.containsKey(h)) {
		map.put(h, root);
		res.add(root);
	}
*/