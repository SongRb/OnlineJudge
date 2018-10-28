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
    int _minDepth(TreeNode* root){
        if(root == NULL) return INT_MAX;
        if(root->left == NULL && root->right == NULL) return 1;
        else return min(_minDepth(root->left), _minDepth(root->right)) + 1;
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        else return _minDepth(root);
    }
};