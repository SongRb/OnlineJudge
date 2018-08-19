/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
        if(root==NULL) return;
		vector<queue<TreeLinkNode*>> que(2);
		int idx = 0;
		que[idx].push(root);
		while (!que[idx].empty())
		{
			TreeLinkNode* prev = NULL;
			while (!que[idx].empty())
			{
				auto top = que[idx].front();
				if (prev == NULL) prev = top;
				else
				{
					top->next = prev;
					prev = top;
				}
				if (top->right != NULL)que[1 - idx].push(top->right);
				if (top->left != NULL)que[1 - idx].push(top->left);
				que[idx].pop();
			}
			idx = 1 - idx;
		}
	}
};