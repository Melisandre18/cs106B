#include <string>

using namespace std;


class LinkedSet {
public:	
	LinkedSet();
	void add(int k);
	bool contains(int k);
	int size();
	void remove(int k);
	void resetIterator();
	bool hasNext();
	int next();
private:

	struct Node {
		int val;
		Node* next;
		Node* prev;
	};
	int len;
	Node* head;
	Node* tail;
	Node* iter;

};