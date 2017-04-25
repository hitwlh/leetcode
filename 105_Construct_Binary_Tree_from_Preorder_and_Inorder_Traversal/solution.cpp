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
        if(preorder.empty()) return NULL;
        my_preorder = preorder, my_inorder = inorder;
        TreeNode* root = new TreeNode(preorder[0]);
        int size;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == preorder[0]){
                size = i;
                break;
            }
        }
        root->left = my_buildTree(1, size, 0, size-1);
        root->right = my_buildTree(size+1, preorder.size()-1, size+1, inorder.size()-1);
        return root;
    }
private:
    vector<int> my_preorder, my_inorder;
    TreeNode* my_buildTree(int preorder_start, int preorder_end, int inorder_start, int inorder_end) {
        TreeNode* root = NULL;
        if(preorder_start < preorder_end){
            root = new TreeNode(my_preorder[preorder_start]);
            int size = -1;
            for(int i = inorder_start; i <= inorder_end; i++)
                if(my_inorder[i] == my_preorder[preorder_start]){
                    size = i;
                    break;
                }
            if(size == -1) cout << "fuck!!\n", exit(0);
            size -= inorder_start;
            root->left = my_buildTree(preorder_start+1, preorder_start+size, inorder_start, inorder_start+size-1);
            root->right = my_buildTree(preorder_start+size+1, preorder_end, inorder_start+size+1, inorder_end);
        }
        else if(preorder_start == preorder_end){
            root = new TreeNode(my_preorder[preorder_start]);
        }
        return root;
    }
};