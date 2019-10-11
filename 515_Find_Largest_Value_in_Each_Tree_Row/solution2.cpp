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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return level_max;
        my_largestValues(root, 0);
        return level_max;
    }
private:
    vector<int> level_max;
    void my_largestValues(TreeNode* root, int level) {
        if(level_max.size() <= level)
            level_max.push_back(root->val);
        else
            level_max[level] = max(level_max[level], root->val);
        if(root->left)
            my_largestValues(root->left, level+1);
        if(root->right)
            my_largestValues(root->right, level+1);
    }
};