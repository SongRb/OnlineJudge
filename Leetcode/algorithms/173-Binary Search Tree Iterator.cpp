/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* p;
    stack<TreeNode*> stk;
    BSTIterator(TreeNode *root) {
        p = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return p || !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        while(p) 
        {
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        int result = p->val;
        p = p->right;
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */