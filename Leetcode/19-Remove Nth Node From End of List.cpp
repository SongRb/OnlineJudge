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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = new ListNode(-1);
        ListNode* p2 = new ListNode(-1);
        p1->next = head;
        p2->next = head;
        
        int cnt=0;
        while(cnt<n) {p1 = p1->next;cnt++;}
        while(p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p2->next==head) return head->next;
        else
        {
            p2->next = p2->next->next;
            return head;
        }
    }
};