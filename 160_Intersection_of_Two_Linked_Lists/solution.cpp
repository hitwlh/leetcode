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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *tailB = headB;
        while(tailB->next) tailB = tailB->next;
        tailB->next = headA;
        ListNode *slow = headB->next, *fast = headB->next;
        if(fast) fast = fast->next;
        else{
            tailB->next = NULL;
            return NULL;
        }
        while(slow != fast){
            slow = slow->next;
            if(fast) fast = fast->next;
            else{
                tailB->next = NULL;
                return NULL;
            }
            if(fast) fast = fast->next;
            else{
                tailB->next = NULL;
                return NULL;
            }
        }
        while(headB != slow){
            slow = slow->next;
            headB = headB->next;
        }
        tailB->next = NULL;
        return slow;
    }
};