#include "Palindromic.h"
#include "map.h"

void pseudoPalindromicPaths (TreeNode * root, Map<int, int>map, int &res) {
	if(root==NULL) return;
	map[root->v]++;
	
	if(root->left==NULL && root->right==NULL){
		int odd=0;
		for(int i=0; i<map.size(); i++){
			if (map[i]%2!=0) odd++;
		}
		if(odd<2) res++;
	}
	
	pseudoPalindromicPaths (root->left, map, res);
	pseudoPalindromicPaths (root->right, map, res) ;

}
    
int pseudoPalindromicPaths (TreeNode * root) {
	Map<int, int>m;
	int res=0;
	pseudoPalindromicPaths (root, m,res);
    return res;
}