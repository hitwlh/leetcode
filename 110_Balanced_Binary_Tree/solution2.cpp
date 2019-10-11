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
    bool isBalanced(TreeNode* root) {
        IsBalanced(root);
        return ret;
    }
private:
    bool ret = true;
    int IsBalanced(TreeNode* root){
        if(!root) return 0;
        if(!root->left and !root->right) return 1;
        int left = IsBalanced(root->left);
        int right = IsBalanced(root->right);
        if(abs(left - right) > 1)
            ret = false;
        return max(left, right)+1;
    }
};