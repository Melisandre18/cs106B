
#include "TreeDistance.h"

void kDi(Node*root, int k, Set<int>&kDis){
	if(k==0){
		kDis.add(root->value);
		return;
	}
	if(root->right!=NULL) kDi(root->right, k-1,  kDis);
	if(root->left!=NULL)  kDi(root->left,k-1,kDis);
	   
}
Set<int> kDistance(Node * root, int k) {
	Set<int> s;
    kDi(root,k,s);
	return s;
}
