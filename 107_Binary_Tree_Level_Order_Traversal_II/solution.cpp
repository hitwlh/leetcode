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
        std::queue<TreeNode *> myqueue;
        vector<vector<int>> ret;
        myqueue.push(root);
        myqueue.push(NULL);
        while(myqueue.front()){
            vector<int> in;
            TreeNode* p = myqueue.front();
            myqueue.pop();
            while(p){
            auto it = in.begin();
            it = in.insert(it, p->val);
            if(p->right)
                myqueue.push(p->right);
            if(p->left)
                myqueue.push(p->left);
            p = myqueue.front();
            myqueue.pop();
            }
            ret.insert(ret.begin(), in);
            myqueue.push(NULL);
        }
        return ret;
    }
};