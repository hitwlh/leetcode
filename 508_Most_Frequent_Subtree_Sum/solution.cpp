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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        search(root);
        int MAX = INT_MIN;
        for(auto sum: sums)
            MAX = max(MAX, sum.second);
        for(auto sum: sums)
            if(sum.second == MAX)
                ret.push_back(sum.first);
        return ret;
    }
private:
    vector<int> ret;
    unordered_map<int, int> sums;
    int search(TreeNode* root){
        if(!root) return 0;
        int sum = root->val + search(root->left) + search(root->right);
        sums[sum]++;
        return sum;
    }
};