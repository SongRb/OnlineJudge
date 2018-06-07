struct Block {
	string key;
	int value;
	Block(string k, int v) :key(k), value(v)
	{}
};

class CompareMinTop
{
public:
	bool operator() (const Block& lhs, const Block& rhs)
	{
		return lhs.value>rhs.value;
	}
};

class CompareMaxTop
{
public:
	bool operator() (const Block& lhs, const Block& rhs)
	{
		return lhs.value<rhs.value;
	}
};



class AllOne {
public:
	/** Initialize your data structure here. */

	priority_queue<Block, vector<Block>, CompareMinTop> min_pq;
	priority_queue<Block, vector<Block>, CompareMaxTop> max_pq;
	map<string, int> value;

	AllOne() {
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		if (value.find(key) != value.end())
		{
			value[key]++;
		}
		else
			value[key] = 1;
        			min_pq.push(Block(key, value[key]));
			max_pq.push(Block(key, value[key]));
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
        if(value.find(key)==value.end()) return;
		value[key]--;

		if (value[key] == 0)
			value.erase(value.find(key));
		else
		{
			min_pq.push(Block(key, value[key]));
			max_pq.push(Block(key, value[key]));
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMinKey() {
		if (min_pq.empty()) return "";
		else
		{
			string k = min_pq.top().key;
			while (true)
			{
				if (value.find(k) == value.end())
				{
					min_pq.pop();
				}
				else if (min_pq.top().value != value[k])
				{
					min_pq.pop();
					min_pq.push(Block(k, value[k]));
				}
				else
				{
					break;
				}
				if (min_pq.empty()) return "";
				k = min_pq.top().key;
			}
			return k;
		}
	}

	/** Returns one of the keys with Minimal value. */
	string getMaxKey() {
		if (max_pq.empty()) return "";
		else
		{
			string k = max_pq.top().key;
			while (true)
			{
				if (value.find(k) == value.end())
				{
					max_pq.pop();
				}
				else if (max_pq.top().value != value[k])
				{
					max_pq.pop();
					max_pq.push(Block(k, value[k]));
				}
				else
				{
					break;
				}
				if (max_pq.empty()) return "";
				k = max_pq.top().key;
			}
			return k;
		}
	}
};
