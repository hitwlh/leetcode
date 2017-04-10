//这题最大的感悟就是不要舍易求难
//这是只扫描一遍的解法，还是很容易出错
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
    vector<int> findMode(TreeNode* root) {
        Inorder(root);
        vector<int> ret;
        int times = 0;
        int now_times = 1;
        for(int i = 0;i<vec.size();i++)
            cout << vec[i] << " " ;
        cout << endl;
        //vec.push_back(-31414);下面的循环会忽略掉最末尾的数字，可以在最后再添加一个数字，这样就会忽略添加的，正好把原先的全处理好
        if(!vec.empty())
            vec.push_back(vec[vec.size()-1]+1);
        else
            return ret;
        for(int i = 1; i<vec.size(); i++){
            if(vec[i] == vec[i-1]){
                now_times ++;
            }
            else{
                if(now_times > times){
                    times = now_times;
                    ret.erase (ret.begin(),ret.end());
                    ret.push_back(vec[i-1]);
                    now_times = 1;
                }
                else if(now_times == times){
                    ret.push_back(vec[i-1]);
                    now_times = 1;
                }
                else{
                    now_times = 1;
                }
            }
        }
        return ret;
    }
private:
    vector<int > vec;
    void Inorder(TreeNode *root){
        if(!root) return;
        Inorder(root->left);
        vec.push_back(root->val);
        Inorder(root->right);
    }
};