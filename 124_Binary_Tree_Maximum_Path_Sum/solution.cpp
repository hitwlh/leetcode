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
    int maxPathSum(TreeNode* root) {
        maxsum(root);
        return ret;
    }
private:
    int ret = INT_MIN;
    int maxsum(TreeNode* root){
        if(!root) return 0;
        int val = root->val;
        int ls = maxsum(root->left), rs = maxsum(root->right);
        if(ls > 0) val += ls;
        if(rs > 0) val += rs;
        if(val > ret) ret = val;
        return max(root->val, max(root->val+ls, root->val + rs));
        //注意这里用root->val而不是val
        //这里三选一，都用了root，也就是说返回的值是一定经过过了root的，而这个root是上次调用的左儿子或右儿子，所以上次调用的root可以和这次调用的root联合起来组成一个路径
    }
};