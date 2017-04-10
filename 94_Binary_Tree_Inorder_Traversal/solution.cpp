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
    vector<int> inorderTraversal(TreeNode* root) {
        search(root);
        return ret;
    }
private:
    stack<TreeNode*> qt;
    vector<int> ret;
    void search(TreeNode* root){
        TreeNode* p = root;
        while(p || !qt.empty()){
            if(p){
                qt.push(p);
                p = p->left;
            }
            else{
                p = qt.top();
                qt.pop();
                ret.push_back(p->val);
                p = p->right;
            }
        }
    }
};