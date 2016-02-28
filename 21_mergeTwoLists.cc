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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
        if (!l1) return l2;
		else if (!l2) return l1;
		ListNode* newList = NULL;
		ListNode* lastList = NULL;
		if (l1->val < l2->val)
		{
			newList = l1;
			lastList = l1;
			l1 = l1->next;
		}
		else
		{
			newList = l2;
			lastList = l2;
			l2 = l2->next;
		}
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				lastList->next = l1;
				lastList = l1;
				l1 = l1->next;
			}
			else
			{
				lastList->next = l2;
				lastList = l2;
				l2 = l2->next;
			}
		}
		if (l1)
			lastList->next = l1;
		else if (l2)
			lastList->next = l2;
		return newList;
    }
};
