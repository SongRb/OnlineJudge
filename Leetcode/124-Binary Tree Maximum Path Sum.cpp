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
    
    int maxValue = -100000000;
    int maxNode = -100000000;
    
    int search(TreeNode* root)
    {
        if(root==NULL) return 0;
        else
        {
            maxNode = max(root->val, maxNode);
            int leftValue = search(root->left);
            int rightValue = search(root->right);
 
            int returnValue  = max(max(leftValue,rightValue)+root->val, 0);
            int sumValue = max(leftValue+rightValue+root->val,0);
            
            maxValue = max(sumValue, maxValue);
            return returnValue;
        }
    }
    
    int maxPathSum(TreeNode* root) {
        int result = search(root);
        if(root==NULL) return 0;
        else if(maxNode<0) return maxNode;
        else return maxValue;
    }
};