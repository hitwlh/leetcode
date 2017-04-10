class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<pair<TreeNode*, int>> tree;
        int level = 1;
        if(!root)
            return ret;
        TreeNode* right = root;
        tree.push(make_pair(root, level));
        TreeNode* top = NULL;
        while(!tree.empty()){
            if(tree.front().second > level){
                ret.push_back(top->val);
                level = tree.front().second;
            }
            top = tree.front().first;
            tree.pop();
            if(top->left)
                tree.push(make_pair(top->left, level+1));
            if(top->right)
                tree.push(make_pair(top->right, level+1));
        }
        if(top)
            ret.push_back(top->val);
        return ret;
    }
};