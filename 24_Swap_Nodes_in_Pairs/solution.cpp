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
        if(!head || !head->next)
            return head;
        ListNode* tmp_next = head->next;
        head->next = tmp_next->next;
        tmp_next -> next = head;
        head->next = swapPairs(head->next);
        return tmp_next;
    }
};