/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "# ";
        string s="";
        stringstream ss;
        ss << root->val;
        string str = ss.str();
        s = str + " ";
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
    }   

    // Decodes your encoded data to tree.
    TreeNode* deserialize1(string& data) {
        if(data == "") return NULL;
        string tmp = data.substr(0,data.find(" "));
        data = data.substr(data.find(" ")+1);
        if(tmp == "#") return NULL;
        TreeNode* root = new TreeNode(atoi(tmp.c_str()));
        root->left = deserialize1(data);
        root->right = deserialize1(data);
        return root;
    }
    TreeNode* deserialize(string data) {
        return deserialize1(data);
    }
};