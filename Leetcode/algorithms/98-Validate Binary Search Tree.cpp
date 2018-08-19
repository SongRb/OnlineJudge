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
    bool isValidBST(TreeNode* root, long long lower, long long upper) {
        if(!root) return true;
        bool result = true;
        if(root->left) 
        { 
            long long newUpper = min(upper, (long long)root->val);
            long long left = (long long) root->left->val;
            result = result && (left < newUpper) && (left > lower) && isValidBST(root->left, lower, newUpper); 
        }
        if(root->right) 
        { 
            long long newLower = max(lower, (long long)root->val);
            long long right = (long long) root->right->val;
            result = result && (right > newLower) && (right < upper) && isValidBST(root->right, newLower, upper); 
        }
        return result;
    }
      
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool result = true;
        if(root->left) { result = result && (root->left->val < root->val) && isValidBST(root->left, -10000000000, root->val); }
        if(root->right) { result = result && (root->right->val > root->val) && isValidBST(root->right, root->val, 10000000000); }
        return result;
    }
};