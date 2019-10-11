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
        while(root){
            mysta.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mysta.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = mysta.top();
        mysta.pop();
        if(top->right){
            TreeNode *root = top->right;
            while(root){
                mysta.push(root);
                root = root->left;
            }
        }
        return top->val;
    }
private:
    stack<TreeNode *> mysta;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */