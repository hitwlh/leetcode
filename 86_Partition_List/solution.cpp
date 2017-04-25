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
        ListNode *p = NULL, *q = NULL, *pH = NULL, *qH = NULL;
        while(head){
            if(head->val < x){
                if(!p) p = head, pH = head;
                else p->next = head, p = p->next;
            }
            else{
                if(!q) q = head, qH = head;
                else q->next = head, q = q->next;
            }
            head=head->next;
        }
        if(!p) return qH;
        p->next = qH;
        if(q) q->next = NULL;
        return pH;
    }
};