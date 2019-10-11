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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *HEAD = new TreeNode(INT_MIN);
        HEAD->left = root;
        TreeNode *p = root, *pt = HEAD;
        while(p && p->val != key){
            pt = p;
            if(p -> val > key) p = p->left;
            else p = p->right;
        }
        if(!p);
        else if(!p->right){
            if(pt->left == p) pt->left = p->left;
            else pt->right = p->left;
        }else if(!p->right->left){
            p->val = p->right->val;
            p->right = p->right->right;
        }else{
            TreeNode *rl = p->right->left, *father = p->right;
            while(rl->left){
                father = rl;
                rl = rl->left;
            }
            p->val = rl->val;
            father->left = rl->right;
        }
        return HEAD->left;
    }
};




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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *HEAD = new TreeNode(INT_MIN);
        HEAD->left = root;
        TreeNode* p_father = HEAD, *p = HEAD->left;
        while(p && p->val != key){
            p_father = p;
            if(p->val > key) p = p->left;
            else p = p->right;
        }
        if(!p) return root;
        if(!p->right){//1
            if(p_father->left == p) p_father->left = p->left;
            else p_father->right = p->left;
        }else if(!p->right->left){//2
            p->right->left = p->left;
            if(p_father->left == p) p_father->left = p->right;
            else p_father->right = p->right;
        }else{//3 情况3和情况2的区别在于，情况3需要设置node_left_father->left = node_left->right;在情况2里，node_left_father和p重合，那么p的左指针就被设置错了！
            TreeNode* node_left = p->right->left, *node_left_father = p->right;
            while(node_left->left){
                node_left_father = node_left;
                node_left = node_left->left;
            }
            node_left_father->left = node_left->right;
            node_left->left = p->left;
            node_left->right = p->right;
            if(p_father->left == p) p_father->left = node_left;
            else p_father->right = node_left;
        }
        return HEAD->left;
    }
};