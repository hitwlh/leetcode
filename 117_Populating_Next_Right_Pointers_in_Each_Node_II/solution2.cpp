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
        TreeLinkNode *dealing = NULL, *start = root;
        while(dealing || start){
            if(!dealing){
                dealing = start;
                start = NULL;
            }
            TreeLinkNode *right;
            if(dealing->left && dealing->right){
                if(!start) start = dealing->left;
                dealing->left->next = dealing->right;
                right = dealing->right;
            }else if(dealing->left && !dealing->right){
                if(!start) start = dealing->left;
                right = dealing->left;
            }
            else if(!dealing->left && dealing->right){
                if(!start) start = dealing->right;
                right = dealing->right;
            }
            else{
                dealing = dealing->next;
                continue;
            }
            dealing = dealing->next;
            while(dealing && !dealing->left && !dealing->right)
                dealing = dealing->next;
            if(!dealing)
                right->next = NULL;
            else if(dealing->left) right->next = dealing->left;
            else right->next = dealing->right;
        }
    }
};