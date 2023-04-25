#include "islands.h"

 void dfs(Grid<int>& g, int i, int j){
	 if( (i >= g.numRows()) || (i < 0) || (j >= g.numCols()) || (j < 0) )  return;
        if(g[i][j]==1){ 
                g[i][j]=0;
                dfs(g,i+1,j); 
                dfs(g,i-1,j);
                dfs(g,i,j+1);
                dfs(g,i,j-1);
             }
    }

int numIslands(Grid<int> &g) {
        int ans=0;
		for(int i=0;i<g.numRows();i++){
			for(int j=0;j<g.numCols();j++){
                if(g[i][j]==1){
					ans++; 
                    dfs(g,i,j);
                    
                }
                
            }
        }
        return ans;
}
