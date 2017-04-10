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
    ListNode *head = new ListNode(0);
    head->next = new ListNode(0);
    ListNode *tmp = head;
    int flag = 0;
    int val1,val2;
    do
    {
        tmp = tmp->next;
        if(l1)
            tmp->val +=  l1->val;
        if(l2)
            tmp->val +=  l2->val;
        if(flag)
            tmp->val += 1;
        flag = 0;
        if(tmp->val>9)
        {
            flag = 1;
            tmp->val -= 10;
        }
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
        tmp->next = new ListNode(0);
    }while(l1||l2);
    if(flag)
        tmp->next->val = 1;
    else
        tmp->next = NULL;
    return head->next;
    }
};
