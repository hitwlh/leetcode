//只使用常数空间

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* l1_head = l1;
        ListNode* l2_head = l2;
        ListNode* Head = new ListNode(-1);
        ListNode* ret = Head;
        while(l1 && l2){
            if(l1->val < l2->val){
                Head->next = l1;
                l1 = l1->next;
                Head = Head -> next;
            }
            else{
                Head->next = l2;
                l2 = l2->next;
                Head = Head -> next;
            }
        }
        if(!l1)
            Head->next = l2;
        else
            Head->next = l1;
        return ret->next;
    }
};