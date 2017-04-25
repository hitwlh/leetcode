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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *Head = new ListNode(-1);
        ListNode *p = Head;
        p->next = head;
        while(p->next){
            if(p->next->val == val) p->next = p->next->next;
            else p = p->next;
        }
        return Head->next;
    }
};