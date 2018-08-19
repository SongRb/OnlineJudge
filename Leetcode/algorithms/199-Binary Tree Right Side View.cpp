/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        vector<queue<TreeNode*>> que(2);
        int idx = 0;
        que[idx].push(root);
        while(!que[idx].empty())
        {
            while(!que[idx].empty())
            {
                auto p = que[idx].front();
                que[idx].pop();
                if(que[idx].empty()) result.push_back(p->val);
                if(p->left) que[1-idx].push(p->left);
                if(p->right) que[1-idx].push(p->right);
            }
            idx = 1-idx;
        }
        return result;
    }
};