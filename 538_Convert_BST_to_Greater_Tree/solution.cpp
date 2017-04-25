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
    TreeNode* convertBST(TreeNode* root) {
        last(root);
        int size = que.size();
        for(int i = size-2; i >= 0; i--)
            que[i]->val += que[i+1]->val;
        return root;
    }
private:
    vector<TreeNode*> que;
    void last(TreeNode* root){
        if(!root) return;
        last(root->left);
        que.push_back(root);
        last(root->right);
    }
};