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
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int choose = 0, not_choose = 0;
        choose = root->val;
        int LEFT = 0, RIGHT = 0;
        not_choose = rob(root->left) + rob(root->right);
        if(root->left)
            LEFT = rob(root->left->left) + rob(root->left->right);
        if(root->right)
            RIGHT = rob(root->right->left) + rob(root->right->right);
        return max(not_choose, choose + LEFT + RIGHT);
    }
};