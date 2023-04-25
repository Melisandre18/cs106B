
#include "SumOfLeftLeaves.h"
#include <iostream>
#include "set.h"

void sum(TreeNode * root,int &num, bool left){
	if(root==NULL) return;
	if(root->left==NULL && root->right==NULL && left) {
		
		num+=root->v;
		return;
	}
	sum(root->left, num, true);
	sum(root->right, num, false);

}
int sumOfLeftLeaves(TreeNode * root) {
	if(root->left==NULL && root->right==NULL)  return 0;
	int num=0;
	sum(root,num, true);
	return num;
}

