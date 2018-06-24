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
        if(head==NULL) return head;
        ListNode* p = head->next;
        if(p==NULL) return head;
        ListNode* prev = new ListNode(p->val+1);
        prev->next = head;
        ListNode* result = prev;
        bool isDup = false;
        while(true)
        {
            if(p && prev->next->val==p->val) 
            {
                isDup = true;
            }
            else 
            {
                if(isDup) 
                {
                    prev->next = p;
                }
                else 
                {
                    prev = prev->next;
                    prev->next = p;
                }
                isDup = false;
                if(!p) break;
            }
            p=p->next;
        }
        return result->next;
    }
};