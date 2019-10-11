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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> myqueue;
        vector<vector<int>> ret;
        myqueue.push(root);
        myqueue.push(NULL);
        while(myqueue.front()){
            vector<int> in;
            TreeNode* p = myqueue.front();
            myqueue.pop();
            while(p){
                in.push_back(p->val);
                if(p->left) myqueue.push(p->left);
                if(p->right) myqueue.push(p->right);
                p = myqueue.front();
                myqueue.pop();
            }
            ret.push_back(in);
            myqueue.push(NULL);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};