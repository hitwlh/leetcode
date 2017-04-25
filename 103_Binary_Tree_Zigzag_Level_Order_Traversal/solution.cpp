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
        vector<TreeNode*> tmp_ele;
        tmp_ele.push_back(root);
        tmp.push_back(tmp_ele);
        bfs(0);
        getret();
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<vector<TreeNode*>> tmp;
    void getret(){
        for(int i = 0; i<tmp.size(); i++){
            vector<TreeNode*> pu = tmp[i];
            vector<int> my;
            for(int j = 0; j<pu.size(); j++)
                my.push_back(pu[j]->val);
            ret.push_back(my);
        }
    }
    void bfs(int level){
        vector<TreeNode*> ele = tmp[level];
        vector<TreeNode*> pu;
        for(int i = ele.size()-1; i >= 0; i--){    
            if(level%2){
                if(ele[i]->left) pu.push_back(ele[i]->left);
                if(ele[i]->right) pu.push_back(ele[i]->right);
            }
            else{
                if(ele[i]->right) pu.push_back(ele[i]->right);
                if(ele[i]->left) pu.push_back(ele[i]->left);
            }
        }
        if(!pu.empty()){
            tmp.push_back(pu);
            bfs(level+1);
        }
    }
};