#include "MyGrid.h"
#include <iostream>

MyGrid::MyGrid(int numRows, int numCols) {
	nRows=numRows;
	nCols=numCols;
	values = new int[nRows*nCols];
	for(int i=0; i<nRows*nCols; i++)
		values[i]=0;
}

int MyGrid::NumRows() {
	return nRows;
}

int MyGrid::NumColumns() {
	return nCols;
}

void MyGrid::SetValue(int i, int j, int value) {
	values[i*nRows+j*nCols-1] = value;
}

int MyGrid::GetValue(int i, int j) {
	return values[i*nRows+j*nCols-1];
}

void MyGrid::RemoveRow(int indx) {
	
}

void MyGrid::RemoveColumn(int indx) {
	
}

void MyGrid::InsertRow(int indx) {
	
}

void MyGrid::InsertColumn(int indx) {
	
}

