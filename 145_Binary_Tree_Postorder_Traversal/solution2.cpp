class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        q1.push(root);
        search();
        return ret;
    }
private:
    stack<TreeNode*> q1;
    vector<int> ret;
    void search(){
        while(!q1.empty()){
            TreeNode* root = q1.top();
            q1.pop();
            if(!root)
                continue;
            ret.insert(ret.begin(), root->val);
            q1.push(root->left);
            q1.push(root->right);
        }
    }
};