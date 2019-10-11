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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Head = new ListNode(-1);
        Head->next = head;
        ListNode *p = Head;
        while(p->next){
            ListNode *q = p->next->next;
            if(q && q->val == p->next->val){
                while(q && q->val == p->next->val){
                    p->next = q;
                    q = q->next;
                }
                p->next = q;
            }
            else
                p = p->next;
        }
        return Head->next;
    }
};