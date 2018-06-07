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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while(p || !stk.empty())
        {
            while(p)
            {
                stk.push(p);
                p = p->left;
            }
            if(!stk.empty())
            {
                p = stk.top();
                k--;
                if(k==0)
                {
                    return p->val;
                }
                stk.pop();
                p = p->right;
            }
        }
    }
};