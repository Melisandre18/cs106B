/*
#include "LangRank.h"

bool isValid(int row, int col, char c, Grid<char> &grid, Grid<bool> &used) {
	if (!used.inBounds(row, col)) return false;
	if (used[row][col]) return false;
	if (grid[row][col] != c) return false;
	return true;
}

void dfs(int row, int col, char c, Grid<char> &grid, Grid<bool> &used) {
	used[row][col] = true;
	if (isValid(row - 1, col, c, grid, used)) dfs(row - 1, col, c, grid, used);
	if (isValid(row, col + 1, c, grid, used)) dfs(row, col + 1, c, grid, used);
	if (isValid(row + 1, col, c, grid, used)) dfs(row + 1, col, c, grid, used);
	if (isValid(row, col - 1, c, grid, used)) dfs(row, col - 1, c, grid, used);
}

Map<char, int> getLangRanks (Grid<char> grid) {
	Map<char, int> res;
	Grid<bool> used(grid.nRows, grid.nCols);
	for (int k = 0; k < grid.nRows; k++) {
		for (int i = 0; i < grid.nCols; i++) {
			if (used[k][i]) continue;
			dfs(k, i, grid[k][i], grid, used);
			res[grid[k][i]]++;
		}
	}
	return res;
}
*/