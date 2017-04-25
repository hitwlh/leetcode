/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode *nex =NULL;
        while(root){
            TreeLinkNode *next = avaliable_next(root->next);
            if(root->left){
                if(!nex) nex = root->left;
                if(root->right) root->left->next = root->right;
                else{
                    if(!next) root->left->next = NULL;
                    else root->left->next = (next->left == NULL ? next->right : next->left);
                }
            }
            if(root->right){
                if(!nex) nex = root->right;
                if(!next) root->right->next = NULL ;
                else root->right->next = (next->left == NULL ? next->right : next->left);
                
            }
            root = next;
        }
        connect(nex);
    }
private:
    TreeLinkNode *avaliable_next(TreeLinkNode *root){
        while(root){
            if(root->left || root->right) return root;
            root = root->next;
        }
        return root;
    }
};