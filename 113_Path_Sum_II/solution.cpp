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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> re;
        hasPathSum(re, root, sum);
        return res;
    }
    void hasPathSum(vector<int> path, TreeNode* root, int sum) {
        if(!root)
            return;
        path.push_back(root->val);
        if(!root->left && !root->right && root->val == sum){
            res.push_back(path);
            return;
        }
        hasPathSum(path, root->left, sum-root->val);
        hasPathSum(path, root->right, sum-root->val);
        return ;
    }
};