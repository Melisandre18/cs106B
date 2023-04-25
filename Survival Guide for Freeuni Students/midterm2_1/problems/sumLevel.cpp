#include "sumLevel.h"
#include <iostream>
void sum(nodeT * root, int lvl,  int& tot){
	if(lvl==0){
		tot+=root->v;
		return;
	}
	if(root->left!=NULL) sum(root->left, lvl-1,tot);
	if(root->right!=NULL) sum(root->right, lvl-1,tot);
	return;
}
int sumLevel(nodeT * root, int lvl) {
	int tot;
	sum(root, lvl-1, tot=0);
	return tot;
}

//mishosiiiii

/*

int sumLevel(nodeT * root, int lvl) {
	if(root == NULL){
		return 0;
	}

	if(lvl == 1){
		return root->v;
	}

	return sumLevel(root->left, lvl - 1) + sumLevel(root->right, lvl - 1);
}
*/
