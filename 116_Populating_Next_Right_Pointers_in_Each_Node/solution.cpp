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
        if(!root)
            return;
        root->next=NULL;
        int flag = 1;
        TreeLinkNode * father_queue = root;
        TreeLinkNode *son_queue;
        TreeLinkNode *son_start;
        while(father_queue){
            if(flag){
                son_start = father_queue->left;
                flag = 0;
            }
            son_queue = father_queue->left;
            if(!son_queue)
                return ;
            son_queue->next = father_queue->right;
            son_queue = son_queue->next;
            father_queue = father_queue->next;
            if(!father_queue){
                son_queue->next = NULL;
                father_queue = son_start;
                flag = 1;
            }
            else{
                son_queue->next = father_queue->left;
            }
        }
    }
};