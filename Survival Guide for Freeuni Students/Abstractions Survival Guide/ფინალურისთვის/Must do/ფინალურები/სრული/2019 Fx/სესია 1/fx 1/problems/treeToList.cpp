#include "treeToList.h"
#include "vector.h"
#include "stack.h"


void flatten(nodeT* root) {
    if(root==NULL)return;
        Stack<nodeT *> s;
        s.push(root);
        nodeT *prev = NULL;
        
		while(!s.isEmpty()){
            nodeT *p = s.top();
            s.pop();
            
            if(prev!=NULL){
                prev->left = NULL;
                prev->right = p;
                
            }
            prev = p;
            if(p->right!=NULL)
                s.push(p->right);
            if(p->left!=NULL)
                s.push(p->left);
        }
    }


