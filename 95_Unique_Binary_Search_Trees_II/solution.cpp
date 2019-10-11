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
        if(!n) return vector<TreeNode*>();
        return generates(1, n);   
    }
private:
    vector<TreeNode *> generates(int left, int right){
        if(left > right) return {NULL};
        if(left == right){
            TreeNode *node = new TreeNode(left);
            return {node};
        }
        vector<TreeNode *> result;
        for(int i = left; i <= right; i++){
            vector<TreeNode *> lnodes = generates(left, i-1);
            vector<TreeNode *> rnodes = generates(i+1, right);
            for(int j = 0; j < lnodes.size(); j++){
                for(int k = 0; k < rnodes.size(); k++){
                    TreeNode *node = new TreeNode(i);
                    node->left = lnodes[j];
                    node->right = rnodes[k];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};