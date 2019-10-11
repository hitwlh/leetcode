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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode *n_head, *HEAD = reverseK(head, k), *n_end = head;
        while(true){
            n_head = n_end->next;
            n_end->next = reverseK(n_head, k);
            //for(int i = 0; i < k && n_head; i++)
            //    n_head = n_head->next;这里写错了，因为老的k段的头进过翻转已经是尾了，尾的next就是新的head，而不是要走k步，这里容易错
            if(n_end->next == n_head)
                break;
            n_end = n_head;//做了reverse之后，n_head就成了当前的段的尾
        }
        return HEAD;
    }
private:
    ListNode* reverseK(ListNode* head, int k){
        ListNode* HEAD = head;
        ListNode* nextK;
        ListNode *end = head;
        while(end && --k)
            end = end->next;
        if(end && !k)//end指向第k个，如果end是空，说明没第k个，则不需要逆转
        {
            nextK = end->next;
            ListNode *now = head->next;
            while(now != nextK){
                head->next = now->next;
                now->next = HEAD;
                HEAD = now;
                now = head->next;
            }
        }
        return HEAD;
    }
};