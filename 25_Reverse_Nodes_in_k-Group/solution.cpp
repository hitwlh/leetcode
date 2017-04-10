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
        ListNode* n_head;
        ListNode* HEAD = reverseK(head, k);
        ListNode* n_end = head;
        if(n_end)
            n_head = n_end->next;
        while(flag){
            n_end->next = reverseK(n_head, k);
            //for(int i = 0; i < k && n_head; i++)
            //    n_head = n_head->next;这里写错了，因为老的k段的头进过翻转已经是尾了，尾的next就是新的head，而不是要走k步，这里容易错
            n_end = n_head;//做了reverse之后，n_head就成了当前的段的尾
            if(n_head)
                n_head = n_head->next;
            //debug(HEAD);
        }
        return HEAD;
    }
private:
    void debug(ListNode* head)
    {
        while(head){
        cout << head->val << " ";
        head = head->next;
        }
        cout << endl;
    }
    bool flag = true;
    ListNode* reverseK(ListNode* head, int k){
        ListNode* HEAD = head;
        ListNode* nextK;
        int i = 1;
        ListNode *tmp = head;
        while(tmp && i < k){
            tmp = tmp->next;
            i++;
        }
        ListNode *end = tmp;
        if(end && i == k)//end指向第k个，如果end是空，说明没第k个
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
        else
            flag = false;
        return HEAD;
    }
};