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
        vector<ListNode*> ret = reverseK(head, k);
        ListNode* Head = ret[0];
        while(ret[0] != ret[1]){
            head = ret[1]->next;
            ListNode* last_end = ret[1];
            ret = reverseK(head, k);
            last_end->next = ret[0];
        }
        return Head;
    }
private:
    vector<ListNode*> reverseK(ListNode* head, int k) {
        if(!head or !head->next or k <= 1) return {head, head};
        ListNode* p = head, *Head = head;
        int K = k;
        while(p and --K)
            p = p->next;
        if(K) return {head, head};
        p = head->next;
        while(--k){
            head->next = p->next;
            p->next = Head;
            Head = p;
            p = head->next;
        }
        return {Head, head};
    }
};