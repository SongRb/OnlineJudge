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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;stack<TreeNode*> stk;
        TreeNode *p,*pre=NULL;
        if(root==NULL) return result;
        p = root;
        while(p ||!stk.empty())
        {
            while(p)
            {
                stk.push(p);
                p=p->left;
            }
            if(!stk.empty())
            {
                p = stk.top();
                result.push_back(p->val);
                stk.pop();
                p = p->right;
            }
        }
        return result;
    }
};