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
    ListNode* partition(ListNode* head, int x) {
        ListNode* t1 = new ListNode(-1); 
        ListNode* t2 = new ListNode(-1);
        ListNode* p1 = t1, *p2 = t2;
        ListNode* p = head;
        while(p)
        {
            if(p->val>=x) {p2->next = new ListNode(p->val);p2 = p2->next;}
            else if(p->val<x) {p1->next = new ListNode(p->val);p1 = p1->next;}
            p = p->next;
        }
        p1->next = t2->next;
        return t1->next;
    }
};