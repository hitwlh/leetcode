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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *Head = new ListNode(-1);
        Head->next = head;
        ListNode *p1 = Head->next, *p2 = Head;
        while(n-- && p1)
            p1 = p1->next;
        while(p1){
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p2 and p2->next)
            p2->next = p2->next->next;
        return Head->next;
    }
};