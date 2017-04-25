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
        if(!head) return NULL;
        ListNode* tmp = head;
        while(tmp->next) tmp = tmp->next;
        return my_sortedListToBST(head, tmp);
    }
private:
    TreeNode* my_sortedListToBST(ListNode* left, ListNode* right) {
        //if(left == right || (left != NULL && left->next == NULL))
        if(left == right)
            return left == NULL ? NULL : new TreeNode(left->val);
        if(left != NULL && right != NULL && left->next == right){
            TreeNode *root = new TreeNode(left->val);
            root->left = NULL;
            root->right = new TreeNode(right->val);
            return root;
        }
        if(right != NULL && right->next == left) return NULL;
        //if(!left) return NULL;
        ListNode *middle = left, *tmp = left;
        if(tmp != right && tmp->next != NULL) tmp = tmp->next;
        if(tmp != right && tmp->next != NULL) tmp = tmp->next;
        while(tmp != right){
            middle = middle->next;
            tmp = tmp->next;
            if(tmp != right) tmp = tmp->next;
        }
        TreeNode *root = new TreeNode(middle->next->val);
        root->left = my_sortedListToBST(left, middle);
        root->right = my_sortedListToBST(middle->next->next, right);
        return root;
    }
};