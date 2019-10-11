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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isS(root->left, root->right);
    }
private:
    bool isS(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right || left->val != right->val) return false;
        return isS(left->left, right->right) && isS(left->right, right->left);
    }
};