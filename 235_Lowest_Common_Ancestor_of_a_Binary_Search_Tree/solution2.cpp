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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        postorder(root);
        TreeNode* up;
        TreeNode* p_chain = p;
        TreeNode* q_chain = q;
        while(!sta.empty()){
            up = sta.top();
            sta.pop();
            if(up == p_chain || up->left == p_chain || up->right == p_chain) p_chain = up;
            //这个判断条件一开始没想明白
            if(up == q_chain || up->left == q_chain || up->right == q_chain) q_chain = up;
            if(p_chain == q_chain)
                return p_chain;
        }
        return NULL;
    }
private:
    stack<TreeNode* > sta;
    void postorder(TreeNode *root){
        if(!root)
            return;
        sta.push(root);
        postorder(root->right);
        postorder(root->left);
    }
};