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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return my_sortedArrayToBST(nums, 0, nums.size()-1);
    }
private:
    TreeNode* my_sortedArrayToBST(vector<int>& nums, int start, int end) {
        TreeNode* root = NULL;   
        if(start == end) root = new TreeNode(nums[start]);
        else if(start < end){
            int middle = (start+end) / 2;
            root = new TreeNode(nums[middle]);
            root->left = my_sortedArrayToBST(nums, start, middle - 1);
            root->right = my_sortedArrayToBST(nums, middle+1, end);
        }
        return root;
    }
};