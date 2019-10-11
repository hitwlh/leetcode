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
        ListNode *tail = headA;
        while(tail->next) tail = tail->next;
        tail->next = headB;
        ListNode *node = detectCycle(headA);
        tail->next = NULL;
        return node;
    }
private:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *fast = head, *slow = head;
        do{
            if(fast && fast->next) fast = fast->next->next;
            else return NULL;
            slow = slow->next;
        }while(fast != slow);
        while(head != slow){
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};