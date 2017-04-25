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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& posterorder) {
        if(posterorder.empty()) return NULL;
        my_posterorder = posterorder, my_inorder = inorder;
        TreeNode* root = new TreeNode(posterorder[posterorder.size()-1]);
        int size;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == posterorder[posterorder.size()-1]){
                size = i;
                break;
            }
        }
        root->left = my_buildTree(0, size-1, 0, size-1);
        root->right = my_buildTree(size, posterorder.size()-2, size+1, inorder.size()-1);
        return root;
    }
private:
    vector<int> my_posterorder, my_inorder;
    TreeNode* my_buildTree(int posterorder_start, int posterorder_end, int inorder_start, int inorder_end) {
        TreeNode* root = NULL;
        if(posterorder_start < posterorder_end){
            root = new TreeNode(my_posterorder[posterorder_end]);
            int size = -1;
            for(int i = inorder_start; i <= inorder_end; i++)
                if(my_inorder[i] == my_posterorder[posterorder_end]){
                    size = i;
                    break;
                }
            if(size == -1) cout << "fuck!!\n", exit(0);
            size -= inorder_start;
            root->left = my_buildTree(posterorder_start, posterorder_start+size-1, inorder_start, inorder_start+size-1);
            root->right = my_buildTree(posterorder_start+size, posterorder_end-1, inorder_start+size+1, inorder_end);
        }
        else if(posterorder_start == posterorder_end){
            root = new TreeNode(my_posterorder[posterorder_start]);
        }
        return root;
    }
};