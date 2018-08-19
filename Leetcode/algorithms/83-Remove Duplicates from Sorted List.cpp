/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        if(head==NULL) return head;
        ListNode* prev = new ListNode(p->val+1);
        prev->next = p;
        ListNode* res = prev;
        while(p)
        {
            // cout<<p->val<<endl;
            if(prev->val != p->val)
            {
                prev->next = p;
                prev = prev->next;
            }
            p = p->next;
        }
        prev->next = NULL;
        return res->next;
    }
};