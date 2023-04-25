
#ifndef MyGrid_Included
#define MyGrid_Included

#include "console.h"
using namespace std;

class MyGrid {
public:
	MyGrid(int numRows, int numCols);
	int NumRows();
	int NumColumns();
	void SetValue(int i, int j, int value);
	int GetValue(int i, int j);
	void RemoveRow(int indx);
	void RemoveColumn(int indx);
	void InsertRow(int indx);
	void InsertColumn(int indx);


private:
	int nRows;
	int nCols;
	int* values; 
};


#endif;