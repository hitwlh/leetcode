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
        ListNode *rl1, *rl2, *res, *resH;
        resH = new ListNode(-1);
        res = resH;
        rl1 = reverseList(l1);
        rl2 = reverseList(l2);
        int acc = 0;
        while(rl1 && rl2){
            if(rl1->val + rl2->val + acc > 9){
                res->next = new ListNode(rl1->val + rl2->val + acc - 10);
                res = res->next;
                acc = 1;
            }else{
                res->next = new ListNode(rl1->val + rl2->val + acc);
                res = res->next;
                acc = 0;
            }
            rl1 = rl1->next;
            rl2 = rl2->next;
        }
        rl1 = (rl1 == NULL) ? rl2 : rl1;
        if(rl1){
            if(!acc) res->next = rl1;
            else{
                while(acc && rl1){
                    if(rl1->val + acc > 9){
                        res->next = new ListNode(rl1->val + acc - 10);
                        res = res->next;
                        acc = 1;
                    }else{
                        res->next = new ListNode(rl1->val + acc);
                        res = res->next;
                        acc = 0;
                    }
                    rl1 = rl1->next;
                }
                if(rl1) res->next = rl1;
            }
        }
        if(acc) res->next = new ListNode(1);
        return reverseList(resH->next);
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