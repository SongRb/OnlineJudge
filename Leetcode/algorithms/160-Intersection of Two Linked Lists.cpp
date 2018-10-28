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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;

		int lengthA = 0, lengthB = 0;
		ListNode *pA = headA, *pB = headB;
		while (pA->next)
		{
			pA = pA->next;
			lengthA++;
		}

		while (pB->next)
		{
			pB = pB->next;
			lengthB++;
		}

		if (pA == pB)
		{
			int delta = 0, cnt = 0;
			ListNode *pL, *pS;
			if (lengthA >= lengthB)
			{
				pL = headA;
				pS = headB;
				delta = lengthA - lengthB;
			}
			else
			{
				pL = headB;
				pS = headA;
				delta = lengthB - lengthA;
			}

			while (cnt < delta)
			{
				pL = pL->next;
				cnt++;
			}

			while (pL)
			{
				if (pL == pS) return pL;
				pL = pL->next;
				pS = pS->next;
			}
		}
		else
		{
			return NULL;
		}
	}
};