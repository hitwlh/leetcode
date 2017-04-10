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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m==n)
            return head;
        struct ListNode Head(-1);
        Head.next = head;
        ListNode* FOLLOW = &Head;
        n -= m;
        while(head && (--m)){
            FOLLOW = head;
            head = head->next;
        }
        ListNode* HEAD = head;
        ListNode* now = head->next;
        while(n--){
            now = head->next;
            head->next = now->next;
            now->next = HEAD;
            HEAD = now;
        }
        FOLLOW->next = HEAD;
        return Head.next;
    }
};