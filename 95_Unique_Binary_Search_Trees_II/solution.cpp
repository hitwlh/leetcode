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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        res = get_tree(1, n);
        return res;
    }
    vector<TreeNode*> get_tree(int left, int right){
        //cout << "left is: " << left << ", right is: " << right << endl;
        vector<TreeNode*> q;
        vector<TreeNode*> left_tree;
        vector<TreeNode*> right_tree;
        if(left > right)
            return q;
        if(left == right){
            TreeNode* root = new TreeNode(left);
            q.push_back(root);
            return q;
        }
        else{
            for(int i = left; i<= right; i++){
                left_tree = get_tree(left, i-1);
                right_tree = get_tree(i+1, right);
                if(left_tree.size() == 0 && right_tree.size() == 0){
                    TreeNode* root = new TreeNode(i);
                    root->left = root->right = NULL;
                    q.push_back(root);
                }
                else if(left_tree.size() == 0){
                    for(int k = 0; k<right_tree.size(); k++){
                        TreeNode* root = new TreeNode(i);
                        //root->left = NULL;
                        root->right = right_tree[k];
                        q.push_back(root);
                    }
                }
                else if(right_tree.size() == 0){
                    for(int k = 0; k<left_tree.size(); k++){
                        TreeNode* root = new TreeNode(i);
                        root->left = left_tree[k];
                        //root->right = NULL;
                        q.push_back(root);
                    }
                }
                else{
                    for(int j = 0; j<left_tree.size(); j++){
                        for(int k = 0; k<right_tree.size(); k++){
                            TreeNode* root = new TreeNode(i);
                            root->left = left_tree[j];
                            root->right = right_tree[k];
                            q.push_back(root);
                        }
                    }
                }
            }
        }
        TreeNode* tmp = q[0];
        q[0] = q[q.size()-1];
        q[q.size()-1] = tmp;
        //这三行代码说明leetcode背后判断是否ac应该用了集合相等，而不管先后顺序
        return q;
        
    }
};