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
    int findBottomLeftValue(TreeNode* root) {
        int ret = 0;
        queue<TreeNode *> que;
        int poped = 0, pushed = 0, pushing = 0;
        if(root){
            que.push(root);
            pushed++;
        }
        int nextlevel = true;
        while(!que.empty()){
            TreeNode * front = que.front();
            if(nextlevel){
                nextlevel = false;
                ret = front->val;
            }
            //cout << front->val << endl;
            que.pop();
            poped++;
            if(front->left){
                que.push(front->left);
                pushing++;
            }
            if(front->right){
                pushing++;
                que.push(front->right);
            }
            //cout << poped << " " << pushed << endl;
            if(poped == pushed){
                pushed = pushing;
                pushing = 0;
                poped = 0;
                nextlevel = true;
            }
        }
        return ret;
    }
};