//第二种解法
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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int lef = length(root->left);
        if(!flag) return false;
        int rig = length(root->right);
        if(!flag) return false;
        if(fabs(lef-rig) <=1 && flag)
            return true;
        return false;
    }
private:
    bool flag = true;
    int length(TreeNode* root){
        if(!root || ! flag)
            return 0;
        int left_l = length(root->left);
        int right_l = length(root->right);
        if(fabs(left_l-right_l)>1)
            flag = false;
        int ret = left_l > right_l ? left_l+1 : right_l+1;
        return ret;
        
    }
};