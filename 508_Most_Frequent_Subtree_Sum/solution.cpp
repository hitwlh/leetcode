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
        while(!sta.empty()){
            kk[sta.top()]++;
            sta.pop();
        }
        int maxx = -1;
        for(auto i: kk){
            if(i.second >= maxx)    maxx = i.second;
        }
        for(auto i: kk){
            if(i.second >= maxx)    ret.push_back(i.first);
        }
        return ret;
    }
private:
    stack<int> sta;
    map<int, int> kk;
    vector<int> ret;
    int search(TreeNode* root){
        if(!root)
            return 0;
        int p = search(root->left) + search(root -> right) + root->val;
        sta.push(p);
        return p;
    }
};