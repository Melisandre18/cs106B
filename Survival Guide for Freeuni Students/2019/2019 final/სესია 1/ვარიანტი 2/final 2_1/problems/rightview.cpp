#include "rightview.h"
#include "map.h"


void left(nodeT * root, Vector<nodeT*> &res, int &maxLevel, int currLevel, bool rightChild){
	if(root==NULL)	return;
	if(currLevel>maxLevel ){
		maxLevel++;
		res.add(root);
	}
	left(root->right, res, maxLevel, currLevel+1, true);
	left(root->left, res, maxLevel, currLevel+1, false);
	
}


Vector<nodeT *> rightView(nodeT * root) {
	Vector<nodeT *> res;
	int maxLevel = 0;
	res.add(root);
	left(root, res, maxLevel, 0, false);
	return res;
}