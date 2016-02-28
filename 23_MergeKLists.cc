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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
        if (lists.empty()) return NULL;
		//head work
		int minNum = 0x7FFFFFFF;
		int minIndex = -1;
		ListNode* newList = NULL;
		for (int i = 0;i < lists.size();)
		{
			if (lists[i])
			{
				if (lists[i]->val < minNum)
				{
					minNum = lists[i]->val;
					minIndex = i;
				}
				++i;
			}
			else
			{
				lists[i] = lists.back();
				lists.pop_back();
			}
		}
		if (minIndex >= 0)
		{
			newList = lists[minIndex];
			lists[minIndex] = lists[minIndex]->next;
		}
		else 
		{
			return newList;
		}
		//normal work
		ListNode* lastNode = newList;
		while (lists.size() > 1)
		{
			minNum = 0x7FFFFFFF;
			minIndex = -1;
			for (int i = 0;i < lists.size();)
			{
				if (lists[i])
				{
					if (lists[i]->val < minNum)
					{
						minNum = lists[i]->val;
						minIndex = i;
					}
					++i;
				}
				else
				{
					lists[i] = lists.back();
					lists.pop_back();
				}
			}
			if (minIndex >= 0)
			{
				lastNode->next = lists[minIndex];
				lastNode = lastNode->next;
				lists[minIndex] = lists[minIndex]->next;
			}
			else 
			{
				return newList;
			}
		}
		//last one
		if (lists.size() == 1)
		{
			lastNode->next = lists.front();
		}
		return newList;
    }
};//TLE   O(nk*k)





ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (!l1) return l2;
	else if (!l2) return l1;
	ListNode* newList = NULL;
	if (l1->val < l2->val)
	{
		newList = l1;
		l1 = l1->next;
	}
	else
	{
		newList = l2;
		l2 = l2->next;
	}
	ListNode* lastList = newList;
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


ListNode* mergeCore(vector<ListNode*>& lists,int left,int right)
{
	if (left == right)
	{
		return lists[left];
	}
	else
	{
		int center = (left + right) >> 1;
		ListNode* l1 = mergeCore(lists,left,center);
		ListNode* l2 = mergeCore(lists,center + 1,right);
		return mergeTwoLists(l1,l2);
	}
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if (lists.empty())
	   {
		   return NULL;
	   }
	   else
	   {
		   return mergeCore(lists,0,lists.size() - 1);
	   }
    }
};//O(nk*logk)


struct compare
{
	bool operator()(ListNode* lhs,ListNode* rhs)
	{
		return lhs->val > rhs->val;
	}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		if (lists.empty()) return NULL;
		priority_queue<ListNode*,vector<ListNode*>,compare> queue;
		for (int i = 0;i < lists.size();++i)
		{
			if (lists[i])
			{
				queue.push(lists[i]);
			}
		}
		ListNode* newList = NULL;
		if (!queue.empty())
		{
			ListNode* temp = queue.top();
			queue.pop();
			if (temp->next)
				queue.push(temp->next);
			newList = temp;
		}
		ListNode* lastNode = newList;
		while (queue.size() > 1)
		{
			ListNode* temp = queue.top();
			queue.pop();
			if (temp->next)
				queue.push(temp->next);
			lastNode->next = temp;
			lastNode = lastNode->next;
		}
		if (queue.size() == 1)
			lastNode->next = queue.top();
		return newList;
    }
};
