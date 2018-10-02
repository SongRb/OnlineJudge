/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		vector<RandomListNode*> origin;
		vector<RandomListNode*> keep;
		unordered_map<RandomListNode*, int> mp;
		RandomListNode* p = head;
		while (p)
		{
			origin.push_back(p);
			keep.push_back(new RandomListNode(p->label));
			mp[p] = keep.size() - 1;
			p = p->next;
		}

		for (int i = 0; i < keep.size(); i++)
		{
			if (i + 1 < keep.size()) keep[i]->next = keep[i + 1];
			if (origin[i]->random == NULL) keep[i]->random = NULL;
			else keep[i]->random = keep[mp[origin[i]->random]];
		}
		if (keep.empty()) return NULL;
		else return keep[0];
	}
};

