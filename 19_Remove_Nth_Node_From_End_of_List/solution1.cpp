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
        int i = 0;
        ListNode* now = head;
        struct ListNode Head = ListNode(-1);
        Head.next = head;
        now = &Head;
        while(now){
            i++;
            now = now->next;
        }
        now = &Head;
        int target = i - n - 1;
        i = 0;
        while(now && target != i){
            i++;
            now = now->next;
        }
        if(now && now->next)
            now->next = now->next->next;
        return Head.next;
    }
};