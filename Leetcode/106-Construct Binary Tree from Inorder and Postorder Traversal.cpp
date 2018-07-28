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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
    TreeNode* buildTree(vector<int>& inorder, int left1, int right1, vector<int>& postorder, int left2, int right2)
    {
        if(left2==right2) return NULL;
        TreeNode* mid = new TreeNode(postorder[right2-1]);
        int midVal = postorder[right2-1];
        int i = left1;
        for(;i<right1;i++)
        {
            if(inorder[i]==postorder[right2-1]) break;
        }
        
        int rightSubTreeSize = right1-i-1;
        int leftSubTreeSize = i-left1;

        mid->left = buildTree(inorder, left1, i, postorder, left2, left2+i-left1);
        mid->right = buildTree(inorder, i+1, right1, postorder, left2+i-left1,right2-1);
        return mid;
    }
    
};