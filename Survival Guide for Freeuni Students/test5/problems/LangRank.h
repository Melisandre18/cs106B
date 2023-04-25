#ifndef Lang_Included
#define Lang_Included

#include "console.h"
#include "Map.h"
#include "Grid.h"

Map<char, int> getLangRanks (Grid<char> grid);
void dfs(Grid<char> &grid, Grid<bool>&g, int r, int c, char ch);
bool free( int r, int c, char ch, Grid<char> &grid, Grid<bool>&g);

#endif;
