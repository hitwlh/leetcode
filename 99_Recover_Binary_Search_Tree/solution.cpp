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
    void recoverTree(TreeNode* root) {
        if(!root) return ;
        place1 = place2 = last = NULL;
        inorder(root);
        if(place1 && place2) swap(place1->val, place2->val);
    }
private:
    TreeNode *last, *place1, *place2;
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        if(!last) last = root;
        else{
            if(root->val < last->val){
                if(!place1){
                    place1 = last;
                    place2 = root;
                }
                else{
                    place2 = root;
                    return;
                }
            }
            last = root;
        }
        inorder(root->right);
    }
};