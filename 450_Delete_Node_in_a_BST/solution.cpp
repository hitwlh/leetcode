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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key){
            TreeNode* biggest = root->left;
            if(!biggest) return root->right;
            if(!biggest->right){
                biggest->right = root->right;
                return biggest;
            }
            while(biggest->right->right) biggest = biggest->right;
            biggest->right->right = root->right;
            TreeNode* left = biggest->right->left;
            biggest->right->left = root->left;
            TreeNode* HEAD = biggest->right;
            biggest->right = left;
            return HEAD;
        }
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else
            root->left = deleteNode(root->left, key);
        return root;
    }
};