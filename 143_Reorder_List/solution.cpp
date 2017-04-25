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
    void reorderList(ListNode* head) {
         if(!head || !head->next) return ;
         ListNode *fast = head, *slow = head;
         fast = fast->next->next;
         while(fast){
             fast = fast->next;
             if(fast) fast = fast->next;
             slow = slow->next;
         }
         ListNode *left = head, *right = slow->next;
         slow->next = NULL;
         right = reverseList(right);
         ListNode *rn, *ln;
         while(right){
             rn = right->next;
             ln = left->next;
             right->next = ln;
             left->next = right;
             right = rn;
             left = ln;
         }
    }
private:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};