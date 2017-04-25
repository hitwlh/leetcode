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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        value = ret = 0;
        dfs(root);
        return ret;
    }
private:
    int value,ret;
    void dfs(TreeNode* root){
        if(root->left==NULL && root->right==NULL)
            ret += value*10 + root->val;
        if(root->left){
            value = value*10 + root->val;
            dfs(root->left);
            value = (value - root->val) / 10;
        }
        if(root->right){
            value = value*10 + root->val;
            dfs(root->right);
            value = (value - root->val) / 10;
        }
    }
};