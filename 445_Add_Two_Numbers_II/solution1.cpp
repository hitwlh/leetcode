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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return reverseList(addNumbers(reverseList(l1), reverseList(l2)));
    }
private:
    ListNode* addNumbers(ListNode* l1, ListNode* l2) {
        ListNode *HEAD = new ListNode(-1);
        ListNode *p = HEAD;
        int sum = 0, carry = 0;
        while(l1 && l2){
            sum = carry + l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            carry = sum / 10;
            sum %= 10;
            p->next = new ListNode(sum);
            p = p->next;
        }
        l1 = l1 ? l1 : l2;
        while(carry > 0 and l1){
            sum = carry + l1->val;
            l1 = l1->next;
            carry = sum / 10;
            sum %= 10;
            p->next = new ListNode(sum);
            p = p->next;
        }
        if(carry > 0) p->next = new ListNode(1);
        else p->next = l1;
        return HEAD->next;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};