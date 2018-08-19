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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l;
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val > l2->val)
        {
            l = l2;
            l2 = l2->next;
        }
        else
        {
            l = l1;
            l1 = l1->next;
        }
        ListNode* result = l;

        while(true)
        {
            if(l2)
            {
                while(l1 && l1->val < l2->val) 
                {
                    l->next = l1;
                    l = l->next;
                    l1 = l1->next;
                }
            }
            else
            {
                l->next = l1;
                break;
            }
            if(l1)
            {
                while(l2 && l1->val >= l2->val) 
                {
                    l->next = l2;
                    l = l->next;
                    l2 = l2->next;
                }
            }
            else
            {
                l->next = l2;
                break;
            }
        }
        return result;
    }
};