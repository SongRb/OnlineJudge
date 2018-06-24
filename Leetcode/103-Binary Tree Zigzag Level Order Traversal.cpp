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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<deque<TreeNode*>> vec(2, deque<TreeNode*>());
        int idx = 0;
        if(root) vec[idx].push_back(root);
        vector<vector<int>> result;
        while(!vec[idx].empty())
        {
            vector<int> tmp;
            while(!vec[idx].empty())
            {
                TreeNode* p;
                if(idx==0)
                {
                    p = vec[idx].front();
                    vec[idx].pop_front();
                    if(p->left) vec[1-idx].push_back(p->left);
                    if(p->right) vec[1-idx].push_back(p->right);
                }
                else
                {
                    p = vec[idx].back();
                    vec[idx].pop_back();
                    if(p->right) vec[1-idx].push_front(p->right);
                    if(p->left) vec[1-idx].push_front(p->left);
                }
                // cout<<(p->val)<<endl;
                tmp.push_back(p->val);
            }
            // cout<<endl;
            idx = 1-idx;
            result.push_back(tmp);
        }
        return result;
    }
};