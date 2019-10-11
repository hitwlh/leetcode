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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return ret;
        myvec.push_back(root);
        myvec.push_back(NULL);
        bool flag = false;
        vector<int> ins;
        while(!myvec.empty()){
            TreeNode* p = myvec[0];
            myvec.erase(myvec.begin());
            if(!p){
                if(flag)
                    reverse(ins.begin(), ins.end());
                ret.push_back(ins);
                ins = {};
                if(myvec.empty()) break;
                myvec.push_back(NULL);
                flag = !flag;
            }else{
                ins.push_back(p->val);
                if(p->left) myvec.push_back(p->left);
                if(p->right) myvec.push_back(p->right);
            }
        }
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<TreeNode*> myvec;
};