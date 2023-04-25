#include "LangRank.h"

void dfs(Grid<char> &grid, Grid<bool>&g, int r, int c, char ch);
bool free( int r, int c, char ch, Grid<char> &grid, Grid<bool>&g);
Map<char, int> getLangRanks (Grid<char> grid) {
	Map<char, int> res;
	Grid<bool>g(grid.nRows,grid.nCols);
	for(int i=0; i<grid.nRows; i++){
		for(int j=0; j<grid.nCols; j++){
			if(!g[i][j]){
		dfs(grid, g,i,j,grid[i][j]);
		res[grid[i][j]]++;
			}
		}
	}
	return res;
}

void dfs(Grid<char> &grid, Grid<bool>&g, int r, int c, char ch){
	g[r][c]=true;
	if(free(r-1,c,ch,grid, g)) dfs(grid, g, r-1, c, ch);
    if (free(r, c-1, ch, grid, g)) dfs( grid, g, r, c-1, ch);
    if(free(r+1, c, ch, grid,g)) dfs(grid, g, r+1, c, ch);
	if(free(r, c+1, ch, grid, g )) dfs(grid, g, r, c+1, ch);
}
bool free( int r, int c, char ch, Grid<char> &grid, Grid<bool>&g){
	return !g.inBounds(r,c) || g[r][c] || grid[r][c]!=ch ? false: true;
}


