#include "Palindromic.h"
#include "set.h"
#include <iostream>


void getAmount(TreeNode * root, int &num, Set<int>s){
	if(root==NULL) return;
	if(!s.contains(root->v)) s.add(root->v);
	else s.remove(root->v);
	if(s.size()<=1&& root->left==NULL &&root->right==NULL) 
	{
		num+=1;
		return;
	}
	getAmount( root ->left, num, s);
	getAmount ( root->right, num, s);
	}

    
int pseudoPalindromicPaths (TreeNode * root) {
	Set<int>s;
	int num=0;
	getAmount(root, num, s);
    return num;
}