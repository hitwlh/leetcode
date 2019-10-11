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
        ListNode *p = head, *q;
        while(p){
            q = p->next;
            if(q && p->val == q->val){
                p->next = q->next;
                delete q;
            }
            else  p = p->next;
        }
        return head;
    }
};