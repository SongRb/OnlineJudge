struct Block
{
	int key;
	int value;
	Block(int k, int v) :key(k), value(v) {}
};

class Compare
{
public:
	bool operator() (const Block& lhs, const Block& rhs)
	{
		return lhs.value>rhs.value;
	}
};

class LRUCache {
public:
	int val[10000];
	int valid[10000];
	int lastAccess[10000];

	// Used to find least time and compare with last access time
	priority_queue<Block, vector<Block>, Compare> pq;
	int heap_capacity;
	int heap_size;
	int counter;

	LRUCache(int capacity) {
		heap_size = 0;
		counter = 0;
		heap_capacity = capacity;
		memset(lastAccess, 0, sizeof(int) * 10000);
		memset(val, 0, sizeof(int) * 10000);
		memset(valid, 0, sizeof(int) * 10000);
	}

	int get(int key) {
		if (valid[key] == 1)
		{
			counter++;
			lastAccess[key] = counter;
			return val[key];
		}
		else
		{
			return -1;
		}
	}

	void put(int key, int value) {
		if (valid[key] == 1)
		{
			counter++;
			lastAccess[key] = counter;
			val[key] = value;
		}
		else
		{
			if (heap_size == heap_capacity)
			{
				// pop from first index, and update last accessed time
				int k = pq.top().key;
				while (lastAccess[k] != pq.top().value)
				{
					pq.push(Block(k, lastAccess[k]));
					pq.pop();
					k = pq.top().key;
				}
				int lastK = pq.top().key;
				valid[lastK] = 0;
				pq.pop();
				heap_size--;
			}
			valid[key] = 1;
			counter++;
			lastAccess[key] = counter;
			val[key] = value;
			pq.push(Block(key, lastAccess[key]));
			heap_size++;
		}


	}
};
