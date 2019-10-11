/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        zhongxu(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return now < val.size();
    }

    /** @return the next smallest number */
    int next() {
        return val[now++];
    }
private:
    void zhongxu(TreeNode *root){
        if(!root) return;
        zhongxu(root->left);
        val.push_back(root->val);
        zhongxu(root->right);
    }
    int now = 0;
    vector<int> val;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */