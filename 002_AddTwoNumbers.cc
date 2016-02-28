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
		if (!l1 || !l2) return NULL;
        int sum=l1->val+l2->val;
        ListNode* root=new ListNode(sum%10);
        ListNode* p=root;
        while (l1->next&&l2->next){
            l1=l1->next;
            l2=l2->next;
            sum/=10;
            sum=sum+l1->val+l2->val;
            p->next=new ListNode(sum%10);
            p=p->next;
        }
        while (l1->next){
            l1=l1->next;
            sum/=10;
            sum=sum+l1->val;
            p->next=new ListNode(sum%10);
            p=p->next;
        }
        while (l2->next){
            l2=l2->next;
            sum/=10;
            sum=sum+l2->val;
            p->next=new ListNode(sum%10);
            p=p->next;
        }
        sum=sum/10;
        if (sum)
            p->next=new ListNode(sum);
        return root;
    }
};
