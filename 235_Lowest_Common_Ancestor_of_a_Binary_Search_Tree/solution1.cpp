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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
            return root;
        while(root){
            if(findnode(root->left, p)){
                if(findnode(root->right, q))
                    return root;
                else
                    return lowestCommonAncestor(root->left, p, q);
            }
            else{
                if(findnode(root->left, q))
                    return root;
                else
                    return lowestCommonAncestor(root->right, p, q);
            }
        }
    }
private:
    bool findnode(TreeNode *root, TreeNode *target){
        if(root == target)
            return true;
        if(!root)
            return false;
        return findnode(root->left, target) || findnode(root->right, target);
    }
};