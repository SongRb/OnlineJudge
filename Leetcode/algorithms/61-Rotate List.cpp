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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0) return head;
        if(head==NULL) return head;

        int length = 1;
        ListNode* p = head;
        // if p reaches the tail, break
        while(p->next)
        {
            p = p->next;
            length++;
        }
        
        k%=length;
        
        p = head;
        ListNode* p2 = head;

        int i=0;
        while(i<k)
        {
            p2 = p2->next;
            i++;
        }
        while(p2->next)
        {
            p = p->next;
            p2 = p2->next;
        }
        p2->next = head;
        auto result = p->next;
        p->next = NULL;
        return result;
    }
};