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
    unordered_map<TreeNode*, int> depth;
    
    int findDepth(TreeNode* p)
    {
        if(p==NULL) return 0;

        int leftDepth = findDepth(p->left);
        int rightDepth = findDepth(p->right);
        if(abs(leftDepth-rightDepth)>1) throw 15;
        else return depth[p] = max(leftDepth, rightDepth)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        try
        {
            findDepth(root);
        }
        catch(int param)
        {
            if(param==15) return false;
            else throw param;
        }
        return true;
    }
};