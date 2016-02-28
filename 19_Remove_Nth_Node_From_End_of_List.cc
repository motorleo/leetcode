/**
 *
 *  * Definition for singly-linked list.
 *
 *   * struct ListNode {
 *
 *    *     int val;
 *
 *     *     ListNode *next;
 *
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *
 *       * };
 *
 *        */

class Solution 
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		if (head == NULL) return NULL;
		if (n <= 0) return head;
		int length = 1;
		ListNode* node = head;
		while (node->next)
		{
			++length;
			node = node->next;
		}
		//error
		if (n > length) return head;
		//delete head
		if (n == length)
		{
			ListNode* temp = NULL;
			if (head->next)
			{
				temp = head->next;
			}
			delete head;
			head = NULL;
			return temp;
		}
		//normal delete
		node = head;
		for (int i = 0;i < length - n - 1;++i)
		{
			node = node->next;
		}
		ListNode* toBeDelete = node->next;
		if (toBeDelete->next)
		{
			node->next = toBeDelete->next;
		}
		else
		{
			node->next = NULL;
		}
		delete toBeDelete;
		toBeDelete = NULL;
		return head;
	}
};
