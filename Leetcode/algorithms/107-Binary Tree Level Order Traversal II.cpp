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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<queue<TreeNode*>> vec(2);
        vector<vector<int>> result;
        if(root)
        {
            vec[0].push(root);
            int idx = 0;
            while(!vec[idx].empty())
            {
                vector<int> tmp;
                while(!vec[idx].empty())
                {
                    auto p = vec[idx].front();
                    vec[idx].pop();
                    tmp.push_back(p->val);
                    if(p->left) vec[1-idx].push(p->left);
                    if(p->right) vec[1-idx].push(p->right);
                }
                idx = 1-idx;
                result.push_back(tmp);
            }
            reverse(result.begin(), result.end());
        }
        return result;
    }
};