class Solution {
public:
	struct Node
	{
		int index;
		vector<int> next;
		Node(int i) :index(i) {}
	};



	int visited[10000];
	int pathLength[10000];
	int minLength;
	int start = -1, end = -1;
	vector<deque<int>> res;
	vector<Node> vec;

	int maxDepth = 2;
	int found = false;

	bool isOnlyCharDiff(const string& str1, const string& str2)
	{
		int length = str1.size();
		bool hasDiff = false;
		for (int i = 0; i < length; i++)
		{
			if (!hasDiff && str1[i] != str2[i])
			{
				hasDiff = true;
			}
			else if (hasDiff && str1[i] != str2[i])
			{
				return false;
			}
		}
		return hasDiff;
	}



	void DFS(deque<int>& stk, int depth)
	{
		if (stk.size() > maxDepth)
			return;
		int top = stk.back();
		int stkSize = stk.size();
		if (pathLength[top] == 0 || pathLength[top] > stkSize)
			pathLength[top] = stkSize;
		else if (pathLength[top] < stkSize)
			return;

		//printQueue(stk);
		auto it = vec[top].next.begin();
		for (; it != vec[top].next.end(); it++)
		{
			// TODO Queue size and search depth
			if (visited[*it] == 0)
			{
				if (*it == end)
				{
					found = true;
					// Assume minLength > size
					if (minLength > stk.size() + 1)
					{
						//cout << "Update min length from " << minLength << " to ";
						res.clear();
						minLength = stk.size() + 1;
						cout << minLength << endl;
					}
					//cout << "Add path" << endl;
					stk.push_back(*it);
					res.push_back(stk);
					stk.pop_back();
					return;
				}
				else
				{
					// path expanded is shorter than min length
					if (minLength > stk.size() + 1)
					{
						visited[*it] = 1;
						stk.push_back(*it);
						DFS(stk,depth+1);
						visited[*it] = 0;
						stk.pop_back();
					}
				}
			}
		}

	}

	void printQueue(deque<int> que)
	{
		while (!que.empty())
		{
			cout << que.front() << " ";
			que.pop_front();
		}
		cout << endl;
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		memset(visited, 0, sizeof(int) * 10000);
		memset(pathLength, 0, sizeof(int) * 10000);

		wordList.push_back(beginWord);
		int length = wordList.size();

		vector<vector<string>> result;
		minLength = length;
		for (int i = 0; i < length; i++)
		{
			vec.push_back(Node(i));
		}

		for (int i = 0; i < length; i++)
		{
			if (endWord == wordList[i]) end = i;
			for (int j = 0; j < i; j++)
			{
				if (isOnlyCharDiff(wordList[i], wordList[j]))
				{
					vec[i].next.push_back(j);
					vec[j].next.push_back(i);
				}
			}
		}

		if (end == -1) return result;
		start = length - 1;

		deque<int> stk;
		stk.push_back(start);
		visited[start] = 1;

		int wordCount = 1;
		int depth = 0;


		while (!found && maxDepth <= length)
		{
			maxDepth++;
			cout <<"Max Depth: "<<maxDepth << endl;
			DFS(stk, depth);
		}

		for (auto it = res.begin(); it != res.end(); it++)
		{
			vector<string> tmp;
			while (!it->empty())
			{
				tmp.push_back(wordList[it->front()]);
				it->pop_front();
			}
			result.push_back(tmp);
		}
		return result;
	}
};


