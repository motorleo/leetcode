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
    ListNode* swapPairs(ListNode* head) 
	{
        if (head == NULL || head->next == NULL) return head;
		ListNode* pLeft = head;
		ListNode* pRight = pLeft->next;
		//swap head
		pLeft->next = pRight->next;
		pRight->next = pLeft;
		//nolmal
		ListNode* pLast = pLeft;
		ListNode* pHead = pRight;
		pLeft = pLeft->next;
		while (pLeft)
		{
			pRight = pLeft->next;
			if (pRight)
			{
				pLeft->next = pRight->next;
				pRight->next = pLeft;
				pLast->next = pRight;
				pLast = pLeft;
				pLeft = pLeft->next;
			}
			else
			{
				break;
			}
		}
		return pHead;
    }
};
