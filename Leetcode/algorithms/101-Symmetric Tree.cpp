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
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if(left==NULL && right==NULL) 
            return true;
        else if(left!=NULL && right!=NULL && left->val==right->val)
        {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetric(root->left, root->right);
    }
};