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
    TreeNode *p1=NULL, *p2=NULL, *prev = new TreeNode(INT_MIN);
    void inOrderTrav(TreeNode* root)
    {
        if(root->left) inOrderTrav(root->left);
        if(p1==NULL && prev->val>=root->val) p1 = prev;
        if(p1!=NULL && prev->val>=root->val) p2 = root;
        prev = root;
        if(root->right) inOrderTrav(root->right);
    }
    
    
    void recoverTree(TreeNode* root) {
        inOrderTrav(root);
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }
};