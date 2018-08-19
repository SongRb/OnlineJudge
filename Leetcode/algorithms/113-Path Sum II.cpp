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
    vector<vector<int>> result;
    void dps(vector<int>& path, TreeNode* root, int sum)
    {
        if(!root) return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==root->val) result.push_back(path);
        if(root->left) dps(path, root->left, sum-root->val);
        if(root->right) dps(path, root->right, sum-root->val);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        dps(tmp, root, sum);
        return result;
    }
};