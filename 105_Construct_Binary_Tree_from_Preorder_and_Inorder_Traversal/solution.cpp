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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < preorder.size(); i++)
            in_index[inorder[i]] = i;
        return buildSonTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
private:
    unordered_map<int, int> pre_index, in_index;
    TreeNode* buildSonTree(vector<int>& preorder, vector<int>& inorder, int pleft, int pright, int ileft, int iright){
        if(pleft > pright) return NULL;
        TreeNode* root = new TreeNode(preorder[pleft]);
        int mid_index = in_index[preorder[pleft]];
        int nums = mid_index - ileft;
        root->left = buildSonTree(preorder, inorder, pleft+1, pleft+nums, ileft, mid_index - 1);
        nums = iright - mid_index;
        root->right = buildSonTree(preorder, inorder, pright-nums+1, pright, mid_index+1, iright);
        return root;
    }
};