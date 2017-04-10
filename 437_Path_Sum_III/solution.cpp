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
    int res;
    int pathSum(TreeNode* root, int sum) {
        res = 0;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode * p;
        while(!q.empty()){
            p = q.front();
            q.pop();
            if(p){
                q.push(p->left);
                q.push(p->right);
            }
            hasPathSum(p, sum);
        }
        return res;
    }
    void hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return;
        /*cout << "=========================" << endl;
        cout << "root->val is: " << root->val << endl;
        cout << "sum: " << sum << endl;
        cout << "=========================" << endl;*/
        if(root->val == sum){
            res++;
            hasPathSum(root->left, 0);
            hasPathSum(root->right, 0);
            return;
        }
        hasPathSum(root->left, sum-root->val);
        hasPathSum(root->right, sum-root->val);
        return ;
    }
};