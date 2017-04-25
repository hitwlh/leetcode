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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int num = element(root->left);
        if(num+1 == k) return root->val;
        if(num+1 > k) return kthSmallest(root->left, k);
        return kthSmallest(root->right, k - num - 1);
    }
private:
    int my_k;
    int element(TreeNode* root){
        if(!root) return 0;
        return 1 + element(root->left) + element(root->right);
    }
};