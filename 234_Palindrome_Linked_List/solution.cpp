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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *fast = head, *slow = head;
        fast = head->next;
        if(fast) fast = fast->next;
        while(fast){
            fast = fast->next;
            if(fast) fast = fast->next;
            slow = slow->next;
        }
        ListNode *right = slow->next;
        slow->next = NULL;
        right = reverseList(right);
        return equa(head, right);
    }
private:
    bool equa(ListNode *left, ListNode*right){
        while(left){
            //if(!right) return false;
            //因为截断原字符串的时候，如果是奇数长度，会造成左侧的串比右侧的串长1，但是如果右侧的串所有字符都没造成break，说明可以返回true
            if(!right) return true;
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        if(right) return false;
        return true;
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