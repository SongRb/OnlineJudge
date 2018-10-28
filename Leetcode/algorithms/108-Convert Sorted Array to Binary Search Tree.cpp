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
    TreeNode* makeTree(const vector<int>& nums, int left, int right)
    {
        if(left==right) return NULL;
        int mid = (left+right)/2;
        TreeNode * p = new TreeNode(nums[mid]);
        p->left = makeTree(nums, left, mid);
        p->right = makeTree(nums, mid+1, right);
        return p;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums, 0, nums.size());
    }
};