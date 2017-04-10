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
    bool isValidBST(TreeNode* root) {
        show(root);
        return ret;
    }
private:
    bool ret = true;
    bool flag = true;
    long long  mi = LLONG_MIN;
    void show(TreeNode* root){
        if(!root) return;
        show(root->left);
        long long re = root->val;
        if(mi < re)
            mi = re;
        else
            ret = false;
        show(root->right);
    }
};