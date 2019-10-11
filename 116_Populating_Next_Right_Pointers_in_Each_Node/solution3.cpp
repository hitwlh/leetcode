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
            if(!start) start = dealing->left;
            if(!start) return ;
            dealing->left->next = dealing->right;
            if(!dealing->right) return;
            if(!dealing->next){
                dealing = dealing->next;
                continue;
            }
            dealing->right->next = dealing->next->left;
            dealing = dealing->next;
        }
    }
};