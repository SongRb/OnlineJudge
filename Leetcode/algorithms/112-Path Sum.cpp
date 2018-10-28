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
    bool found = false;
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(!found){
            if(root == NULL) return false;
            else
            {
                if(root->val == sum) found = found || (root->left==NULL && root->right==NULL);
                found = found || (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
            }
        }
        return found;
    }
};