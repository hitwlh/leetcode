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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p = new ListNode(-1), *q = new ListNode(-1);
        ListNode *pH = p, *qH = q;
        while(head){
            if(head->val < x)
                p->next = head, p = p->next;
            else
                q->next = head, q = q->next;
            head=head->next;
        }
        if(!pH->next) return qH->next;
        p->next = qH->next;
        q->next = NULL;
        return pH->next;
    }
};