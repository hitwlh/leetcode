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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        w = 0;
        preorder(s);
        w = 1;
        preorder(t);
        //cout << str[0] << endl;
        //cout << str[1] << endl;
        return str[0].find(str[1]) != string::npos;
    }
private:
    string str[2];
    int w;
    void preorder(TreeNode* s){
        if(!s){
            str[w] += ",,";
            return;
        }
        str[w] += "," + to_string(s->val);
        preorder(s->left);
        preorder(s->right);
    }
};