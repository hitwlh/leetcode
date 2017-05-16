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
    int getMinimumDifference(TreeNode* root) {
        inord(root);
        return ret;
    }
private:
    int ret = INT_MAX, last = -INT_MAX+10000;
    void inord(TreeNode* root){
        if(!root) return;
        inord(root->left);
        ret = min(ret, abs(root->val - last));
        last = root->val;
        inord(root->right);
    }
};