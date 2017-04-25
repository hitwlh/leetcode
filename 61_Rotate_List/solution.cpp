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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int len = 0;
        ListNode *HEAD = head;
        while(HEAD) HEAD = HEAD->next, len++;
        k = k % len;
        ListNode *left=head, *right=head;
        while(k--) right = right->next;
        while(right->next){
            right = right->next;
            left = left->next;
        }
        right->next = head;
        HEAD = left->next;
        left->next = NULL;
        return HEAD;
    }
};