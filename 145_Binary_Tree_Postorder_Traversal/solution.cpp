class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //if(!root)
          //  return ret;
        q1.push(root);
        search();
        return ret;
    }
private:
    stack<TreeNode*> q1, q2;
    vector<int> ret;
    void search(){
        while(!q1.empty()){
            TreeNode* root = q1.top();
            q1.pop();
            if(!root)
                continue;
            q2.push(root);
            q1.push(root->left);
            q1.push(root->right);
        }
        while(!q2.empty()){
            ret.push_back(q2.top()->val);
            q2.pop();
        }
    }
};