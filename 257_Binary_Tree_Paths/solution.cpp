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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return ret;
        if(!root->left && !root->right) return {to_string(root->val)};
        string father = to_string(root->val);
        bt(father, root);
        return ret;
    }
private:
    vector<string> ret;
    void bt(string father, TreeNode* root){
        if(!root->left && !root->right)
            ret.push_back(father);
        if(root->left)
            bt(father + "->" + to_string(root->left->val), root->left);
        if(root->right)
            bt(father + "->" + to_string(root->right->val), root->right);
    }
};