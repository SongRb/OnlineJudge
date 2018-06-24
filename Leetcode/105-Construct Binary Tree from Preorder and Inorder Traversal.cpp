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
    void buildTree(const vector<int>& preorder, int lpdx, int rpdx , vector<int>& inorder, int lidx, int ridx, TreeNode* prev, bool left)
    {
        int root = preorder[lpdx];
        int mid=lidx;
        for(; mid<=ridx; mid++)
        {
            if(inorder[mid]==root) break;
        }
        TreeNode* p;
        if(left) {prev->left = new TreeNode(root);p=prev->left;}
        else {prev->right = new TreeNode(root);p=prev->right;}
        int leftCnt = mid - lidx;
        if(lidx<=mid-1) buildTree(preorder, lpdx+1, lpdx+leftCnt , inorder, lidx, mid-1, p, true);
        if(mid+1<=ridx) buildTree(preorder, lpdx+1+leftCnt, rpdx , inorder, mid+1, ridx, p, false);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* p;
        p = new TreeNode(-1);
        if(preorder.size()>0) buildTree(preorder, 0, preorder.size()-1 , inorder, 0, inorder.size()-1, p, true);
        return p->left;
    }
};