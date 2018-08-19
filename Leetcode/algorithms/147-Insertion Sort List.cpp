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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(-1000000);
        dummy->next = head;
        ListNode* end = head;
        ListNode* p = end->next;
        while(p)
        {
            ListNode* p1 = dummy;
            while(true)
            {
                if(p1->next->val > p->val)
                {
                    ListNode* next = p->next;
                    p->next = p1->next;
                    p1->next = p;
                    p = next;
                    break;
                }
                else if(p1==end)
                {
                    end->next = p;
                    end = p;
                    p = p->next;
                    break;
                }
                p1 = p1->next;
            }
        }
        end->next = NULL;
        return dummy->next;
    }
};