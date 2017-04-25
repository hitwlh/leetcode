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
    void flatten(TreeNode* root) {
        preorder(root);
        TreeNode* now;
        while(!my_queue.empty()){
            now = my_queue.front();
            my_queue.pop();
            now->left = NULL;
            if(!my_queue.empty()) now->right = my_queue.front();
            else now->right = NULL;
        }
    }
private:
    queue<TreeNode*> my_queue;
    void preorder(TreeNode* root){
        if(root){
            my_queue.push(root);
            preorder(root->left);
            preorder(root->right);
        }
    }
};