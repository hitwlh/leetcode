/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedTree(head);
    }
private:
    vector<ListNode*> break_by_medium(ListNode* head){
        if(!head || !head->next) return {head, NULL, NULL};
        ListNode* fast = head, *slow = head, *slow_father, *slow_son;
        while(fast && fast->next){
            fast = fast->next->next;
            slow_father = slow;
            slow = slow->next;
        }
        slow_father->next = NULL;
        slow_son = slow->next;
        return {slow, head, slow_son};
    }
    TreeNode* sortedTree(ListNode* head){
        if(!head) return NULL;
        vector<ListNode*> vec = break_by_medium(head);
        if(!vec[0]) return NULL;
        TreeNode* middle = new TreeNode(vec[0]->val);
        middle->left = sortedTree(vec[1]);
        middle->right = sortedTree(vec[2]);
        return middle;
    }
};