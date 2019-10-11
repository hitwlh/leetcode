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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return search(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int ret = 0;
    int search(TreeNode* root, int sum){
        if(!root) return 0;
        int ans = 0;
        if(root->val == sum) ans += 1;
        int left = search(root->left, sum-root->val);
        int right = search(root->right, sum-root->val);
        return left+right+ans;
    }
};