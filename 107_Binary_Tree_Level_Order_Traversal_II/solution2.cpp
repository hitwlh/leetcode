/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
/* for this question, we need to construct the ret vector first
   thus, we need to know the depth of this tree, we write a simple
   function to calculate the height of this tree */
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
       int depth = getHeight(root);
       vector<vector<int>> ret(depth);
       if(depth == 0) //invalid check
            return ret;
        getSolution(ret,root,0, depth-1);
        return ret;
    }

    void getSolution(vector<vector<int>>& ret, TreeNode* root, int level, int depth)
    {
        if(root == NULL)
            return;
        ret[depth - level].push_back(root->val);
        getSolution(ret,root->left,level+1, depth);
        getSolution(ret,root->right,level+1, depth);
    }

    int getHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int height = (left > right?left:right)+1;
        return height;
    }
};