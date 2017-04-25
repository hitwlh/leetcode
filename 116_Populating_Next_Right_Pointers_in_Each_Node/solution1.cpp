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
        if(!root) return;
        root->next=NULL;
        my_queue.push(root);
        my_queue.push(NULL);
        while(!my_queue.empty()){
            TreeLinkNode * tmp = my_queue.front();
            my_queue.pop();
            if(!tmp && my_queue.empty()) break;
            if(tmp){
                tmp->next = my_queue.front();
                if(tmp->left) my_queue.push(tmp->left);
                if(tmp->right) my_queue.push(tmp->right);
            }
            else my_queue.push(NULL);
        }
    }
private:
    queue<TreeLinkNode *> my_queue;
};