/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //wlh
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root || !root->left) return;
        TreeLinkNode *nex = root->left;
        while(root){
            root->left->next = root->right;
            if(root->next)
                root->right->next = root->next->left;
            root = root->next;
        }
        connect(nex);
    }
};