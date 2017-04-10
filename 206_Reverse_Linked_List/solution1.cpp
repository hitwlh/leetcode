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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode *HEAD = head;
        ListNode *now = head->next;
        while(now){
            head->next = now->next;
            now->next = HEAD;
            HEAD = now;
            now = head->next;
        }
        return HEAD;
    }
};