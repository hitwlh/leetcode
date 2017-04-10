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
    bool isSymmetric(TreeNode* root) {
        myq.push(make_pair(root, root));
        return IsSame();
    }
private:
    queue<pair<TreeNode*, TreeNode*>> myq;
    vector<int> tree;
    bool IsSame(){
        while(!myq.empty()){
            TreeNode* left = get<0>(myq.front());
            TreeNode* right = get<1>(myq.front());
            myq.pop();
            if(!left && !right)
                continue;
            if(!left && right)
                return false;
            if(left && !right)
                return false;
            if(left->val != right-> val)
                return false;
            myq.push(make_pair(left->left, right->right));
            myq.push(make_pair(left->right, right->left));
        }
        return true;
    }
};