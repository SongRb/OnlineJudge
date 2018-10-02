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
    
    ListNode* sortList(ListNode* left, ListNode* right)
    {
        if(left->next==right) return left;
        ListNode* mid = getMidNode(left, right);

        ListNode* p1 = sortList(left, mid);
        ListNode* p2 = sortList(mid, right);

        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        while(p1!=mid || p2!=right)
        {
            if(p1==mid)
            {
                p->next = p2;
                p2 = p2->next;
            }
            else if(p2==right)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else if(p1!=mid && p1->val<p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else if(p2!=right && p2->val<=p2->val)
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = right;
        return head->next;
    }
    
    ListNode* getMidNode(ListNode* left, ListNode* right)
    {
        ListNode* p = left;
        ListNode* p2 = left;
        while(p->next!=right)
        {
            p = p->next;
            p2 = p2->next;
            if(p->next!=right) p = p->next;
        }
        return p2;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        return sortList(head, NULL);
    }
};