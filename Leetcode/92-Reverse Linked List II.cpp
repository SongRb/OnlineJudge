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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL) return head;
        ListNode* p = head;
        ListNode* prev = NULL;
        int cnt = 1;
        while(cnt<m)
        {
            prev = p;
            p = p->next;
            cnt++;
        }
        ListNode* pre = p;
        ListNode* cur = p->next;
        while(cnt<n)
        {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            cnt++;
        }
        if(prev==NULL)
        {
            prev = pre;
            head = prev;
        }
        else
        {
            prev->next = pre;
        }
        p->next = cur;
        return head;
    }
};