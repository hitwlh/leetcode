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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int left_count = 1, right_count = 1;
        while(left){
            left = left->left;
            left_count ++;
        }
        while(right){
            right = right->right;
            right_count ++;
        }
        if(left_count == right_count)
            return ((1<<left_count) - 1);
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};