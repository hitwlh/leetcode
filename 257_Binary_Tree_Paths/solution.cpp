class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        vector<string> ret_left;
        vector<string> ret_right;
        string tmp;
        if(!root)
            return ret;
        else{
            ret_left = binaryTreePaths(root->left);
            ret_right = binaryTreePaths(root->right);
            for(int i = 0; i < ret_left.size(); i++){
                stringstream ss;
                ss << root->val;
                string str = ss.str();
                ret.push_back(str + "->" + ret_left[i]);
            }
            for(int i = 0; i < ret_right.size(); i++){
                stringstream ss;
                ss << root->val;
                string str = ss.str();
                ret.push_back(str + "->" + ret_right[i]);
            }
            if(ret.empty()){
                stringstream ss;
                ss << root->val;
                string str = ss.str();
                ret.push_back(str);
            }
        }
        return ret;
    }
};