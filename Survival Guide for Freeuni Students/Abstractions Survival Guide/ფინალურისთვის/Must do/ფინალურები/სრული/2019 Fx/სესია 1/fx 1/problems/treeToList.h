#include <string>

using namespace std;
struct nodeT {
	int v;
	int weight;//ignore this field!!
	nodeT * left;
	nodeT * right;
};

void flatten(nodeT * root);
