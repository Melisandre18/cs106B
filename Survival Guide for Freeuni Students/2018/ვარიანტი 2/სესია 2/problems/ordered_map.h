
using namespace std;

class OrderedMap {
	public:
		OrderedMap();
		void put(int key, int value);
		int get(int key);
		int size();
		void remove(int key);
		bool containsKey(int key);
		void resetIterator();
		bool hasNext();
		int next();

	private:
		struct Cell{
			int key;
			int val;
		};

		Cell** map;
		int len;
		int iter;
		
};