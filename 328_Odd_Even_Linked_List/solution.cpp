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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* p = head, *q = head->next, *pH = p, *qH = q;
        while(q and q->next){
            p->next = q->next;
            if(p->next){
                p = p->next;
                q->next = p->next;
                q = q->next;
            }
        }
        p->next = qH;
        return pH;
    }
};