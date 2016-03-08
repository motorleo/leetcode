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
		ListNode* pLast = head;
		ListNode* pFirst = head;
		ListNode* pPrev = head;
		int len = 0;
		while (pLast)
		{
			pLast = pLast->next;
			++len;
		}
		if (len <= 1) return head;
		k = k % len;
		pLast = head;
		for (int i = 1;i <= k;++i)
		{
			pLast = pLast->next;
		}
		while (true)
		{
			if (pLast->next == NULL)
			{
				pPrev = pFirst;
				pFirst = pFirst->next;
				break;
			}
			pFirst = pFirst->next;
			pLast = pLast->next;
		}
		pLast->next = head;
		pPrev->next = NULL;
		return pFirst;
    }
};
