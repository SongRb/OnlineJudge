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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p1, *p2, *result;
        p1 = new ListNode(-10);
        p1->next = head;
        p2 = head;
        result = head->next;
        while(p2 && p2->next)
        {
            auto tmp = p2->next;
            p2->next = p2->next->next;
            p1->next = tmp;
            p1->next->next = p2;
            p1 = p2;
            p2 = p2->next;
        }
        return result;
    }
};