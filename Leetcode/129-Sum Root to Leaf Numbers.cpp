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
    int result=0;
    void dfs(TreeNode* root, int num)
    {
        num = num*10+root->val;
        if(root->left || root->right)
        {
            if(root->left) dfs(root->left, num);
            if(root->right) dfs(root->right, num);
        }
        else
        {
            result+=num;
        }
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return result;
        dfs(root, 0);
        return result;
    }
};