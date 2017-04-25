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
        ListNode Head(-1);
        Head.next = head;
        ListNode *p=&Head;
        int flag = 0;
        while(p->next){
            int val = p->next->val;
            ListNode *q = p->next->next;
            if(q && q->val == val){
                while(q && q->val == val){
                    p->next = q->next;
                    q = p->next;
                }
            }
            else p = p->next;
        }
        return Head.next;
    }
};