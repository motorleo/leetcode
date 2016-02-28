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
    ListNode* reverseKGroup(ListNode* head, int k) 
	{
        if (!head || k <= 0) return NULL;
		if (k == 1) return head;
		ListNode* pPrev = NULL;
		ListNode* pNext = head;
		ListNode* newHead = NULL;
		bool unChange = true;
		while (pNext)
		{
			ListNode* pLeft = pNext;
			int i = 0;
			//check
			for (;i < k && pNext;++i)
			{
				pNext = pNext->next;
			}
			//Reverse k nodes
			if (i == k)
			{
				if (unChange) unChange = false;
				ListNode* pFirst = pLeft;
				ListNode* pRight = pLeft->next;
				ListNode* pTemp = pRight->next;
				for (int j = 1;j < k;++j)
				{
					pRight->next = pLeft;
					pLeft = pRight;
					if (pTemp)
					{
						pRight = pTemp;
						pTemp = pRight->next;
					}
				}
				if (pPrev)
				{
					pPrev->next = pLeft;
				}
				else
				{
					newHead = pLeft;
				}
				pPrev = pFirst;
				pPrev->next = pNext;
			}
		}
		if (unChange) return head;
		else return newHead;
    }
};
