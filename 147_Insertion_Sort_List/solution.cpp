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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        ListNode *right = head;
        while(true){
            ListNode *next = right->next;
            if(next) next = next->next;
            pair<ListNode*, ListNode*> ret = insert(head, right, right->next);
            head = ret.first, right = ret.second;
            right->next = next;
            if(!next) break;
        }
        return head;
    }
private:
    pair<ListNode*, ListNode*> insert(ListNode *left, ListNode *right, ListNode *insert){
        if(!insert) return {left,right};
        if(!left) return {insert,insert};
        ListNode *start = left;
        if(start->val >= insert->val){
            insert->next = left;
            return {insert, right};
        }
        while(start != right){
            if(!start->next) break;
            if(start->next->val >= insert->val) break;
            start = start->next;
        }
        insert->next = start->next;
        start->next = insert;
        if(start == right) return {left,insert};
        else return {left,right};
    }
};