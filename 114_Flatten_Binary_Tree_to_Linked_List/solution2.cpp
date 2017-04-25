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
    void flatten(TreeNode* root) {
        if(!root) return;
        cout << root->val << endl;
        if(!(root->left)){
            flatten(root->right);
            return;
        }
        TreeNode *left = root->left;
        while(left && left->right)
            left = left->right;
        left->right =  root->right;;
        root->right = root->left;
        root->left = NULL;
        flatten(root->right);
    }
};