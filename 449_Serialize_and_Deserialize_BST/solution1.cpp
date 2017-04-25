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
        if(!root)   return "";    
        string left = serialize(root->left);
        string right = serialize(root->right);
        stringstream ss;
        ss << root->val;
        string str = ss.str();
        int length = left.length();
        stringstream ss2;
        ss2 << length;
        string str2 = ss2.str();
        return str2 + " " + left + str + " " + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        string str;
        int i, place1, place2;
        for(i = 0; i < data.length() && data[i] != ' '; i++)
            str += data[i];
        place1 = i;
        int n = atoi(str.c_str());
        i += n+1;
        string middle;
        for(; i < data.length() && data[i] != ' '; i++)
            middle += data[i];
        place2 = i;
        int val = atoi(middle.c_str());
        TreeNode *root = new TreeNode(val);
        TreeNode *left = deserialize(data.substr(place1+1, n));
        TreeNode *right = deserialize(data.substr(place2+1));
        root->left = left;
        root->right = right;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));