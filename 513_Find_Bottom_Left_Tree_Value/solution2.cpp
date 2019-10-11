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
    int findBottomLeftValue(TreeNode* root) {
        my_findBottomLeftValue(root, 0);
        return level_left.back();
    }
private:
    vector<int> level_left;
    void my_findBottomLeftValue(TreeNode* root, int level) {
        if(level_left.size() <= level)
            level_left.push_back(root->val);
        if(root->left)
            my_findBottomLeftValue(root->left, level+1);
        if(root->right)
            my_findBottomLeftValue(root->right, level+1);
    }
};