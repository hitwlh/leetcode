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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret, ne[2];
        queue<TreeNode *> que;
        int poped = 0, pushed = 0, pushing = 0, MAX = INT_MIN;
        if(root){
            que.push(root);
            pushed++;
        }
        while(!que.empty()){
            TreeNode * front = que.front();
            //cout << front->val << endl;
            if(front->val > MAX) MAX = front->val;
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
                ret.push_back(MAX);
                pushed = pushing;
                pushing = 0;
                poped = 0;
                MAX = INT_MIN;
            }
        }
        return ret;
    }
};