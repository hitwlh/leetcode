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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        sum = 0;
        my_leftsum(root->left, 1);
        my_leftsum(root->right, 0);    
        return sum;
    }
private:
    int sum;
    void my_leftsum(TreeNode* root, int flag){
        if(!root)
            return ;
        if(!root ->left && !root->right && flag)
            sum += root->val;
        my_leftsum(root->left, 1);
        my_leftsum(root->right, 0);
    }
};