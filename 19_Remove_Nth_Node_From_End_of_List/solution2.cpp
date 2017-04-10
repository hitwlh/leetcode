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
        int i = -1;
        struct ListNode Head = ListNode(-1);
        Head.next = head;
        ListNode* first = &Head;
        ListNode* second = &Head;
        while(i != n && first){
            first = first->next;
            i++;
        }
        while(first){
            first = first->next;
            second = second->next;
        }
        if(second && second->next)
            second->next = second->next->next;
        return Head.next;
    }
};