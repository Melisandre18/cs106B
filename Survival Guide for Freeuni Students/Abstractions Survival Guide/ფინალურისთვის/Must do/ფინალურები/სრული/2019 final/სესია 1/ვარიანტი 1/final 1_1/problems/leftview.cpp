#include "leftview.h"
#include "Set.h"

void dfs(nodeT *root, int dpth, Vector<nodeT *> &res, Set<int>&st){
	if(!st.contains(dpth)){
		res.add(root);
		st.add(dpth);
	}
	if(root->left!=NULL) dfs(root->left, dpth+1, res, st);
	if(root->right!=NULL) dfs(root->right, dpth+1, res, st);
}
Vector<nodeT *> leftView(nodeT * root) {
	Vector<nodeT *> res;
	Set<int>st;
	dfs(root,0,res,st);
	return res;
}
