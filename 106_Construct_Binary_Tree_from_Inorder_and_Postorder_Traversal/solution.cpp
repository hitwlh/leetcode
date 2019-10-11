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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        for(int i = 0; i < inorder.size(); i++)
            mymap[inorder[i]] = i;
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
private:
    unordered_map<int, int> mymap;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int ileft, int iright, int pleft, int pright) {
        if(ileft > iright) return NULL;
        TreeNode* node = new TreeNode(postorder[pright]);
        if(ileft == iright)
            return node;
        int medium = mymap[postorder[pright]];
        node->left = build(inorder, postorder, ileft, medium-1, pleft, pleft+medium-ileft-1);
        node->right = build(inorder, postorder, medium+1, iright, pright + medium - iright, pright-1);
        return node;
     }
};