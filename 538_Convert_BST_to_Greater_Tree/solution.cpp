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
    TreeNode* convertBST(TreeNode* root) {
        last(root);
        return root;
    }
private:
    int sum = 0;
    void last(TreeNode* root){
        if(!root) return;
        last(root->right);
        root->val += sum;
        sum = root->val;
        last(root->left);
    }
};