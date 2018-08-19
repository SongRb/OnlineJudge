/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef std::map<ListNode*,int> MyMap;
typedef std::pair<ListNode*,int> MyPair;

class Solution {
public:
	ListNode * detectCycle(ListNode *head) {
		ListNode* p = head;
		MyMap visited;
		while (p)
		{
			if (visited.find(p) != visited.end())
				return p;
			visited.insert(MyPair(p,1));
			p = p->next;
		}
		return NULL;
	}
};

