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
        if(!root) return "";    
        string left = serialize(root->left);
        string right = serialize(root->right);
        stringstream ss;
        ss << root->val;
        string str = ss.str();
        return str+ " " + left + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        string root, use;
        int i, count = 0, place1;
        for(i = 0; i < data.length() && data[i]!= ' '; i++)
            root += data[i];
        place1 = i;
        int n = atoi(root.c_str());
        TreeNode* Troot = new TreeNode(n);
        for(i++; i < data.length(); i++){
            use = "";
            while(i < data.length() && data[i] != ' ') use += data[i++];
            count = atoi(use.c_str());
            if(count > n) break;
        }
        for(i--; i >= 0 && data[i] != ' '; i--);
        TreeNode *left = deserialize(data.substr(place1+1, i-place1));
        TreeNode *right = deserialize(data.substr(i+1));
        Troot->left = left;
        Troot->right = right;
        return Troot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));