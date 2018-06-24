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
    vector<TreeNode*> createTree(int left, int right)
    {
        vector<TreeNode*> result;
        if(left==right)
        {
            result.push_back(new TreeNode(left));
        }
        else if(left>right)
        {
            result.push_back(NULL);
        }
        else
        {
            for(int i=left;i<=right;i++)
            {
                auto ptr1 = createTree(left, i-1);
                auto ptr2 = createTree(i+1, right);
                for(auto p1:ptr1)
                {
                    for(auto p2:ptr2)
                    {
                        TreeNode* p = new TreeNode(i);
                        p->left = p1;
                        p->right = p2;
                        result.push_back(p);
                    }
                }
            }   
        }
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>();
        return createTree(1,n);
    }
};