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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;stack<TreeNode*> stk;TreeNode *p,*pre=NULL;if(root==NULL) return result;
        stk.push(root);
        while(!stk.empty())
        {
            p = stk.top();
            result.push_back(p->val);
            stk.pop();
            if(p->right!=NULL) stk.push(p->right);
            if(p->left!=NULL) stk.push(p->left);
        }
        return result;
    }
};