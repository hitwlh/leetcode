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
    vector<int> preorderTraversal(TreeNode* root) {
        q.push(root);
        search();
        return ret;
    }
private:
    vector<int> ret;
    stack<TreeNode*> q;
    void search(){
        while(!q.empty()){
        TreeNode* root = q.top();
        q.pop();
        if(!root)
            continue;
        ret.push_back(root->val);
        q.push(root->right);
        q.push(root->left);
        }
    }
};