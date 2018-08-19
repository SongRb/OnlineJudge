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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        
        ListNode *p1pre;
        ListNode *p2pre;
        

        
//         while(p1 != NULL || p2 != NULL)
//         {
//             int curDigit = p1->val+p2->val+carry;
//             if(curDigit>9)
//             {
//                 curDigit -=9;
//                 carry = 1;
//             }
//             else
//             {
//                 carry = 0;
//             }
//         }
        
        int carry = 0;
        
        
        while(p1!=NULL && p2!=NULL)
        {
            p1->val +=(p2->val+carry);
            if(p1->val>9)
            {
                p1->val-=10;
                carry =1;
            }
            else
            {
              carry = 0;
            }
            p1pre = p1;
            p1 = p1->next;
            
            p2pre = p2;
            p2 = p2->next;
        }
        
        if(p1==NULL && p2!=NULL)
        {
            p1pre->next = p2;
            p1 = p1pre->next;
        }
        
        while(p1!=NULL)
        {
            p1->val +=carry;
            if(p1->val>9)
            {
                p1->val-=10;
                carry =1;
            }
            else
            {
              carry = 0;
            }
            p1pre = p1;
            p1 = p1->next;
        }
        
        if(carry!=0)
        {
            p1pre->next = new ListNode(carry);
        }
        
        return l1;
        
        
    }
};