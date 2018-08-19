/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* rec(ListNode* left, ListNode* right)
    {
        ListNode* p1 = left, *p2 = left;
        if(left==right) return NULL;
        while(p2!=right && p2->next!=right)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        TreeNode* root = new TreeNode(p1->val);
        root->left = rec(left, p1);
        root->right = rec(p1->next, right);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        return rec(head, NULL);
    }
};