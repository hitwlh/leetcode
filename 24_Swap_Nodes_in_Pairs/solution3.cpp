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
    ListNode* swapPairs(ListNode* head) {
        ListNode* Head = new ListNode(-1);
        Head->next = head;
        ListNode* pre = Head;
        while(pre->next and pre->next->next){
            ListNode *q = pre->next->next;
            pre->next->next = q->next;
            q->next = pre->next;
            pre->next = q;
            pre = q->next;
        }
        return Head->next;
    }
};