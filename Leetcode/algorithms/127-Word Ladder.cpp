
class Solution {
public:
	int visited[10000];
	bool isOnlyCharDiff(const string& str1, const string& str2)
	{
		int length = str1.size();
		bool hasDiff = false;
		for (int i = 0; i<length; i++)
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

	struct Node
	{
		int index;
		vector<int> next;
		Node(int i) :index(i) {}
	};


	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		memset(visited, 0, sizeof(int) * 10000);
		int start=-1, end=-1;
		wordList.push_back(beginWord);
		int length = wordList.size();
		vector<Node> vec;

		for (int i = 0; i<length; i++)
		{
			vec.push_back(Node(i));
		}

		for (int i = 0; i<length; i++)
		{
			if (endWord == wordList[i]) end = i;
			for (int j = 0; j<i; j++)
			{
				if (isOnlyCharDiff(wordList[i], wordList[j]))
				{
					vec[i].next.push_back(j);
					vec[j].next.push_back(i);
				}
			}
		}

		if (end == -1) return 0;
		start = length - 1;

		queue<int> que[2];
		que[0].push(start);
		visited[start] = 1;

		int i = 0;
		int layerNum = 1;
		int wordCnt = 1;
		while (wordCnt<length)
		{
			while (!que[i].empty())
			{
				int index = que[i].front();
				que[i].pop();
				wordCnt++;
				for (auto it = vec[index].next.begin(); it != vec[index].next.end(); it++)
				{
					if (*it == end)
						return layerNum + 1;

					if (!visited[*it])
					{
						visited[*it] = 1;
						que[1 - i].push(*it);
						//cout << wordList[*it] << " ";
					}
				}
			}

			if (que[1 - i].empty()) return 0;
			//cout << endl;
			i = 1 - i;
			layerNum++;
		}
		return 0;
	}
};
