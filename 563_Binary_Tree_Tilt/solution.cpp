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
    int findTilt(TreeNode* root) {
        cal_sum(root);
        cal_tile(root);
        sum_tree(root);
        return ret;
    }
private:
    int ret = 0;
    void cal_tile(TreeNode *root){
        if(!root) return ;
        if(!root->left && !root->right){
            root->val = 0;
        }else if(!root->left && root->right){
            root->val = abs(root->right->val);
            cal_tile(root->right);
        }else if(root->left && !root->right){
            root->val = abs(root->left->val);
            cal_tile(root->left);
        }else{
            root->val = abs(root->left->val - root->right->val);
            cal_tile(root->right);
            cal_tile(root->left);
        }
    }
    void sum_tree(TreeNode* root){
        if(!root) return;
        ret += root->val;
        sum_tree(root->left);
        sum_tree(root->right);
    }
    int cal_sum(TreeNode* root){
        if(!root) return 0;
        root->val += cal_sum(root->left) + cal_sum(root->right);
        return root->val;
    }
};